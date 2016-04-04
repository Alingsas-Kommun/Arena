<?php
/**
 * @file
 * arena_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function arena_base_user_default_roles() {
  $roles = array();

  // Exported role: administrativt personal.
  $roles['administrativt personal'] = array(
    'name' => 'administrativt personal',
    'weight' => 8,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 4,
  );

  // Exported role: lärare.
  $roles['lärare'] = array(
    'name' => 'lärare',
    'weight' => 2,
  );

  // Exported role: skoladministrator.
  $roles['skoladministrator'] = array(
    'name' => 'skoladministrator',
    'weight' => 3,
  );

  // Exported role: student.
  $roles['student'] = array(
    'name' => 'student',
    'weight' => 1,
  );

  // Exported role: superadministrator.
  $roles['superadministrator'] = array(
    'name' => 'superadministrator',
    'weight' => 5,
  );

  return $roles;
}
