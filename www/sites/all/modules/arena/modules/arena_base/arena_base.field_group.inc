<?php
/**
 * @file
 * arena_base.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function arena_base_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|user|user|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Kontaktinformation',
    'weight' => '3',
    'children' => array(
      0 => 'field_ou',
      1 => 'field_organizational_structure',
      2 => 'field_user_email',
      3 => 'field_user_phone',
      4 => 'field_user_mobile',
      5 => 'field_user_fax',
      6 => 'field_user_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_contact|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_school|user|user|default';
  $field_group->group_name = 'group_school';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Skolinformation',
    'weight' => '5',
    'children' => array(
      0 => 'field_ou',
      1 => 'field_user_fax',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-school field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_school|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_school|user|user|form';
  $field_group->group_name = 'group_school';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'School information',
    'weight' => '4',
    'children' => array(
      0 => 'field_user_school',
      1 => 'field_user_class',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-school field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_school|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_contact|user|user|default';
  $field_group->group_name = 'group_user_contact';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Kontaktinformation',
    'weight' => '4',
    'children' => array(
      0 => 'field_user_email',
      1 => 'field_user_phone',
      2 => 'field_user_mobile',
      3 => 'field_user_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-user-contact field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_user_contact|user|user|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Kontaktinformation');
  t('School information');
  t('Skolinformation');

  return $field_groups;
}
