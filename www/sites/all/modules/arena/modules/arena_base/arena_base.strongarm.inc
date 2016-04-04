<?php
/**
 * @file
 * arena_base.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function arena_base_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_organizational_structure_pattern';
  $strongarm->value = 'group/[term:tid]';
  $export['pathauto_taxonomy_term_organizational_structure_pattern'] = $strongarm;

  return $export;
}
