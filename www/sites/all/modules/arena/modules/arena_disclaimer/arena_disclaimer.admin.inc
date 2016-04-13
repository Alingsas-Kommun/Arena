<?php

/**
 * @file
 * Arena disclaimer admin functions 
 */

/**
 * Form builder.
 */
function arena_disclaimer_settings_form($form, &$form_state) {
  $form['arena_disclaimer_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Disclaimer title'),
    '#default_value' => variable_get('arena_disclaimer_title', ''),
    '#weight' => 0, 
  );
  $text = variable_get('arena_disclaimer_text', array('value' => '', 'format' => 'html'));
  $form['arena_disclaimer_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Disclaimer text'),
    '#default_value' => $text['value'],
    '#format' => $text['format'],
    '#weight' => 1, 
  );
  $form['arena_disclaimer_confirm'] = array(
    '#type' => 'checkbox',
    '#title' => t('Users have to confirm the disclaimer to use the portal.'),
    '#default_value' => variable_get('arena_disclaimer_confirm', FALSE),
    '#weight' => 2,
    '#prefix' => '<br/>',
    '#suffix' => 'You can see the resulting disclaimer page under <a href="/disclaimer/view">disclaimer/view</a>.',
  );
  return system_settings_form($form);
}

