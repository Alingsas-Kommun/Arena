<?php
/**
 * @file
 * arena_base.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function arena_base_taxonomy_default_vocabularies() {
  return array(
    'organizational_structure' => array(
      'name' => 'Organisation Struktur',
      'machine_name' => 'organizational_structure',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
