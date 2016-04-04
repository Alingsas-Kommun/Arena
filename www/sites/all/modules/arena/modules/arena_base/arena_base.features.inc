<?php
/**
 * @file
 * arena_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function arena_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function arena_base_image_default_styles() {
  $styles = array();

  // Exported image style: userimage.
  $styles['userimage'] = array(
    'label' => 'userimage',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 70,
          'height' => 70,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
