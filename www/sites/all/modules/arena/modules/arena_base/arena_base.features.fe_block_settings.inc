<?php
/**
 * @file
 * arena_base.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function arena_base_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['arena-user_info'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'user_info',
    'module' => 'arena',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arena_bootstrap' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'arena_bootstrap',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
