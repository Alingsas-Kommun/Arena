<?php

/**
 * @file queue_ui.pages.inc
 */

/**
 * Queue form handler.
 */
function queue_ui_page($form, &$form_state) {
  //queue_ui_test(); // @todo remove before prod
  // Initialize.
  if ($form_state['rebuild']) {
    $form_state['input'] = array();
  }
  if (empty($form_state['storage'])) {
    // First step, so start with our overview form.
    $form_state['storage'] = array(
      'step' => 'queue_ui_overview_form',
    );
  }
  // Return the form from the current step.
  $function = $form_state['storage']['step'];
  $form = $function($form, $form_state);
  return $form;
}

function queue_ui_page_submit($form, &$form_state) {
  $values = $form_state['values'];
  // Get submitted queues to act on.
  $queues = array_filter($values['queues']);
  if (empty($queues)) {
    // Nothing to do.
    return;
  }
  if (isset($values['step_submit'])) {
    // Pass off to step submit handler.
    $function = $values['step_submit'];
    $function($form, $form_state, $queues);
  }
  return;
}

function queue_ui_overview_form() {
  $queues = $options = array();
  // @todo activation status
  $header = array(
    'name' => array('data' => t('Name')),
    'title' => array('data' => t('Title')),
    'items' => array('data' => t('Number of items')),
    //'operations' => array('data' => t('Operations')),
  );
  // Get queues defined via our hook.
  $defined_queues = queue_ui_defined_queues();
  // Get queues names.
  $queues = queue_ui_queues();
  foreach ($queues as $name => $queue) {
    $title = '';
    $operations = '';
    if (isset($defined_queues[$name])) {
      $title = $defined_queues[$name]['title'];
    }
    if (isset($defined_queues[$name]['batch'])) {
      $operations = 'batch';
    }
    $options[$name] = array(
      'name' => array('data' => $name),
      'title' => array('data' => $title),
      'items' => array('data' => $queue['items']),
      //'operations' => array('data => $operations),
    );
  }
  
  $form['queues'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No queues exist.'),
  );
  // @todo deactivate options
  // Option to run batch.
  $form['batch'] = array(
    '#type' => 'submit',
    '#value' => t('Batch process'),
  );
  // Option to remove lease timestamps.
  $form['release'] = array(
    '#type' => 'submit',
    '#value' => t('Remove leases'),
  );
  // Option to run via cron.
  $form['cron'] = array(
    '#type' => 'submit',
    '#value' => t('Cron process'),
  );
  // Option to delete queue.
  $form['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete queues'),
  );
  // Specify our step submit callback.
  $form['step_submit'] = array('#type' => 'value', '#value' => 'queue_ui_overview_submit');
  return $form;
}

/**
 * Overview submit handler.
 */
function queue_ui_overview_submit($form, &$form_state, $queues) {
  $values = $form_state['values'];
  // Switch off submitted action.
  switch ($values['op']) {
    case $values['cron']:
      // Set variables for cron to TRUE.
      $defined_queues = queue_ui_defined_queues();
      $intersect = array_intersect(array_keys($defined_queues), $queues);
      foreach ($intersect as $name) {
        if (isset($defined_queues[$name]['cron'])) {
          variable_set('queue_ui_cron_' . $name, TRUE);
        }
      }
      break;
    case $values['batch']:
      // Process queue(s) with batch.
      // We can only run batch on queues using our hook_queue_info() that define batch.
      $defined_queues = queue_ui_defined_queues();
      $intersect = array_intersect(array_keys($defined_queues), $queues);
      foreach ($intersect as $name) {
        // Only if queue_info implementation defined batch can we set it here.
        if (isset($defined_queues[$name]['batch'])) {
          $batch = $defined_queues[$name]['batch'];
          // Add queue as argument to operations by resetting the operations array.
          $operations = array();
          $queue = DrupalQueue::get($name);
          foreach ($batch['operations'] as $operation) {
            // First element is the batch process callback, second is the argument.
            $operations[] = array($operation[0], array_merge(array($queue), $operation[1]));
          }
          $batch['operations'] = $operations;
          // Set.
          batch_set($batch);
        }
      }
      break;
    case $values['delete']:
      // Confirm before deleting. Go multistep!
      $form_state['rebuild'] = TRUE;
      $form_state['storage']['queues'] = $queues;
      $form_state['storage']['step'] = 'queue_ui_confirm_delete';
      break;
    case $values['release']:
      foreach ($queues as $name) {
        $num_updated = db_update('queue')
          ->fields(array(
            'expire' => 0,
          ))
          ->condition('name', $name, '=')
          ->execute();
        drupal_set_message(t('!count lease reset in queue !name', array('!count' => $num_updated, '!name' => $name)));
      }
      break;
  }
  return;
}

/**
 * Confirm form for deleting queues.
 */
function queue_ui_confirm_delete($form, &$form_state) {
  $form['queues'] = array('#type' => 'value', '#value' => $form_state['storage']['queues']);
  $description = t('All items in each queue will be deleted, regardless of if leases exist. This operation cannot be undone.');
  // Specify our step submit callback.
  $form['step_submit'] = array('#type' => 'value', '#value' => 'queue_ui_delete_submit');
  return confirm_form($form,
    format_plural(count($form_state['storage']['queues']), 'Are you sure you want to delete the queue?', 'Are you sure you want to delete @count queues?'),
    'admin/config/system/queue-ui',
    $description,
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Submit handler for deleting queues.
 */
function queue_ui_delete_submit($form, &$form_state, $queues) {
  $values = $form_state['values'];
  $defined_queues = queue_ui_defined_queues();
  foreach ($queues as $name) {
    $queue = DrupalQueue::get($name);
    if (isset($defined_queues[$name]['delete'])) {
      $function = $defined_queues[$name]['delete'];
      $function($queue);
    }
    $queue->deleteQueue();
  }
  drupal_set_message(format_plural(count($values['queues']), 'Queue deleted', '@count queues deleted'));
  return;
}