<?php

/**
 * @file
 * template.php
 */

function arena_bootstrap_username_alter(&$name, $account) {
  if (isset($account->uid)) {
    $this_user = user_load($account->uid);//loads the custom fields
    if((isset($this_user->field_firstname['und'][0]['value']) && isset($this_user->field_lastname['und'][0]['value']) && ($this_user->field_firstname['und'][0]['value'] || $this_user->field_lastname['und'][0]['value']))) {
      $name = $this_user->field_firstname['und'][0]['value'].' '.$this_user->field_lastname['und'][0]['value'];
    }
  }
}

function arena_bootstrap_theme_registry_alter(&$theme_registry) {
  $theme_registry['username']['preprocess functions'][] = _untrim_username;
}

function _untrim_username(&$variables) {
  $name = $variables['name_raw'];
  $variables['name'] = check_plain($name);
}

function arena_bootstrap_preprocess_image_style(&$vars) {
  $vars['attributes']['class'][] = 'img-responsive'; // http://getbootstrap.com/css/#overview-responsive-images
  if($vars['style_name'] == 'icon') {
    $vars['attributes']['class'][] = 'img-rounded';
  }
}

/**
 * Implements hook_preprocess_page().
 *
 * @see page.tpl.php
 */
function arena_bootstrap_preprocess_page(&$variables) {
  // Add information about the number of sidebars.
  if(in_array('page__node__webform', $variables['theme_hook_suggestions']) 
    || in_array('page__node__webform_results', $variables['theme_hook_suggestions'])
    || in_array('page__node__submission', $variables['theme_hook_suggestions'])){
    $variables['content_column_class'] = ' class="col-md-12"';
  }
  elseif($variables['node']->type == 'news' && !in_array('page__node__edit', $variables['theme_hook_suggestions'])) {
    $variables['content_column_class'] = ' class="col-md-6 col-sm-push-3"';
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['content_column_class'] = ' class="col-sm-6 col-sm-pull-6"';
  }
  else {
    $variables['content_column_class'] = ' class="col-md-8 col-md-push-2"';
  }
  if(!empty($variables['user'])) {
    if (drupal_match_path(current_path(),"user") ||
        drupal_match_path(current_path(),"user/*")){
       global $user;
       if(arg(1) == $user->uid){
         menu_set_active_item('user');
         $variables['title'] = 'Mitt konto';
       }
       else {
         $variables['title'] = 'Konto';
       }
    }
  }
}

function arena_bootstrap_preprocess_node(&$vars) {

  unset($vars['content']['links']['node']['#links']['node-readmore']);

  $node = $vars['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node);

  // Add theme hook suggestions for node templates per type and view mode.
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['view_mode'];
  $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '__' . $vars['view_mode'];

  if($vars['view_mode'] == 'search_result_teaser') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__searchresultteaser';
  }

  // Extend preprocess node per node type.
  $controller = 'arena_preprocess_node_' . $node->type;
  if (function_exists($controller)) {
    $controller($vars, $node, $node_wrapper);
  }
}

function arena_bootstrap_file_widget($variables) {
  $element = $variables['element'];

  // The "form-managed-file" class is required for proper Ajax functionality.
  $output = '<div class="file-widget form-managed-file clearfix">';
  $output .= _arena_bootstrap_file_widget($element); 
  $output .= '</div>';

  return $output;
}

function arena_bootstrap_image_widget($variables) {
  $element = $variables['element'];
  $output = '';
  $output .= '<div class="image-widget form-managed-file clearfix">';

  if (isset($element['preview'])) {
    $output .= '<div class="image-preview">';
    $output .= drupal_render($element['preview']);
    $output .= '</div>';
  }

  $output .= '<div class="image-widget-data">';
  $output .= _arena_bootstrap_file_widget($element);
  $output .= '</div>';

  return $output;
}

/**
 * returns $output
 */
function _arena_bootstrap_file_widget($element) {
  if ($element['fid']['#value'] != 0) {
    $element['filename']['#markup'] = '<div class="form-group">' . $element['filename']['#markup'] . ' <span class="file-size badge">' . format_size($element['#file']->filesize) . '</span></div>';
  }
  else {
    $element['upload']['#prefix'] = '<div class="input-group"><span class="input-group-btn"><span class="btn btn-primary btn-file">'.t('Browse');
    $element['upload']['#suffix'] = '</span></span>';
    $element['upload_button']['#prefix'] = '<input class="form-control" type="text" readonly=""><span class="input-group-btn">';
    $element['upload_button']['#suffix'] = '</span></div>';
  }
  drupal_add_js("
    (function($) {
      Drupal.behaviors.bootstrapImages = {
        attach: function (context) {
              $('.btn-file :file', context).once().on('change', function() {
                var txt  = '';
                var input = $(this);
                var numFiles = input.get(0).files ? input.get(0).files.length : 1;
                if (numFiles > 1) {
                  txt = numFiles + ' Selected';
                } else {
                  txt = input.val();
                }
                input.closest('.input-group').children('input[type=text]:lt(1)').val(txt);
              });
        }
      };
    })(jQuery)
  ", 'inline');
  
  return drupal_render_children($element).'</div>';
}

function arena_bootstrap_file_link($variables) {
  $file = $variables['file'];
  //$icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
  //$icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
      'attributes' => array(
          'type' => $file->filemime . '; length=' . $file->filesize,
      ),
  );

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  } else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  //open files of particular mime types in new window
  //$new_window_mimetypes = array('application/pdf', 'text/plain');
  //if (in_array($file->filemime, $new_window_mimetypes)) {
  //  $options['attributes']['target'] = '_blank';
  //}

  $options['attributes']['target'] = '_blank';
  return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';

}
