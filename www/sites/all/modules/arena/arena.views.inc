<?php
$views = array();

$view = new view();
$view->name = 'users_filtered_school';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'users';
$view->human_name = 'Users filtered school';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Users filtered school';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access user profiles';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Sök';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '30';
$handler->display->display_options['pager']['options']['quantity'] = '5';
$handler->display->display_options['pager']['options']['tags']['first'] = '« första';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ föregående';
$handler->display->display_options['pager']['options']['tags']['next'] = 'nästa ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'sista »';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'field_firstname' => 'field_firstname',
  'field_lastname' => 'field_lastname',
  'name' => 'name',
  'rid' => 'rid',
  'field_user_class' => 'field_user_class',
);
/* Fält: Användare: Förnamn */
$handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
$handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
$handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
$handler->display->display_options['fields']['field_firstname']['label'] = '';
$handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_firstname']['element_default_classes'] = FALSE;
/* Fält: Användare: Efternamn */
$handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
$handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
$handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
$handler->display->display_options['fields']['field_lastname']['label'] = '';
$handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_lastname']['element_default_classes'] = FALSE;
/* Fält: Användare: Namn */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
/* Fält: Användare: Roller */
$handler->display->display_options['fields']['rid']['id'] = 'rid';
$handler->display->display_options['fields']['rid']['table'] = 'users_roles';
$handler->display->display_options['fields']['rid']['field'] = 'rid';
$handler->display->display_options['fields']['rid']['label'] = '';
$handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['rid']['element_default_classes'] = FALSE;
/* Fält: Användare: Skola */
$handler->display->display_options['fields']['field_user_school']['id'] = 'field_user_school';
$handler->display->display_options['fields']['field_user_school']['table'] = 'field_data_field_user_school';
$handler->display->display_options['fields']['field_user_school']['field'] = 'field_user_school';
$handler->display->display_options['fields']['field_user_school']['label'] = '';
$handler->display->display_options['fields']['field_user_school']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_user_school']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_user_school']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_user_school']['delta_offset'] = '0';
/* Fält: Användare: Klass */
$handler->display->display_options['fields']['field_user_class']['id'] = 'field_user_class';
$handler->display->display_options['fields']['field_user_class']['table'] = 'field_data_field_user_class';
$handler->display->display_options['fields']['field_user_class']['field'] = 'field_user_class';
$handler->display->display_options['fields']['field_user_class']['label'] = '';
$handler->display->display_options['fields']['field_user_class']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_user_class']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_user_class']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_user_class']['delta_offset'] = '0';
/* Sort criterion: Användare: Förnamn (field_firstname) */
$handler->display->display_options['sorts']['field_firstname_value']['id'] = 'field_firstname_value';
$handler->display->display_options['sorts']['field_firstname_value']['table'] = 'field_data_field_firstname';
$handler->display->display_options['sorts']['field_firstname_value']['field'] = 'field_firstname_value';
/* Sort criterion: Användare: Efternamn (field_lastname) */
$handler->display->display_options['sorts']['field_lastname_value']['id'] = 'field_lastname_value';
$handler->display->display_options['sorts']['field_lastname_value']['table'] = 'field_data_field_lastname';
$handler->display->display_options['sorts']['field_lastname_value']['field'] = 'field_lastname_value';
/* Contextual filter: Användare: Skola (field_user_school) */
$handler->display->display_options['arguments']['field_user_school_tid']['id'] = 'field_user_school_tid';
$handler->display->display_options['arguments']['field_user_school_tid']['table'] = 'field_data_field_user_school';
$handler->display->display_options['arguments']['field_user_school_tid']['field'] = 'field_user_school_tid';
$handler->display->display_options['arguments']['field_user_school_tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_user_school_tid']['exception']['title'] = 'Alla';
$handler->display->display_options['arguments']['field_user_school_tid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_user_school_tid']['default_argument_options']['argument'] = '0';
$handler->display->display_options['arguments']['field_user_school_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_user_school_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_user_school_tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_user_school_tid']['break_phrase'] = TRUE;
/* Filter criterion: Användare: Aktiv */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'contains';
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'Sök efter namn';
$handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
$handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
  2 => '2',
  9 => 0,
  8 => 0,
  10 => 0,
  12 => 0,
  6 => 0,
  11 => 0,
  1 => 0,
);
$handler->display->display_options['filters']['combine']['fields'] = array(
  'field_firstname' => 'field_firstname',
  'field_lastname' => 'field_lastname',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'users-filtered-school';
$translatables['users_filtered_school'] = array(
  t('Master'),
  t('Users filtered school'),
  t('more'),
  t('Sök'),
  t('Återställ'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« första'),
  t('‹ föregående'),
  t('nästa ›'),
  t('sista »'),
  t('([rid])'),
  t('Alla'),
  t('Sök efter namn'),
  t('Page'),
);
$views[$view->name] = $view;

$view = new view();
$view->name = 'users_filtered_class';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'users';
$view->human_name = 'Users filtered class';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Users filtered class';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access user profiles';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Sök';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '30';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '5';
$handler->display->display_options['pager']['options']['tags']['first'] = '« första';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ föregående';
$handler->display->display_options['pager']['options']['tags']['next'] = 'nästa ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'sista »';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'field_firstname' => 'field_firstname',
  'field_lastname' => 'field_lastname',
  'name' => 'name',
  'rid' => 'rid',
  'field_user_class' => 'field_user_class',
);
/* Fält: Användare: Förnamn */
$handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
$handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
$handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
$handler->display->display_options['fields']['field_firstname']['label'] = '';
$handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_firstname']['element_default_classes'] = FALSE;
/* Fält: Användare: Efternamn */
$handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
$handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
$handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
$handler->display->display_options['fields']['field_lastname']['label'] = '';
$handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_lastname']['element_default_classes'] = FALSE;
/* Fält: Användare: Namn */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
/* Fält: Användare: Roller */
$handler->display->display_options['fields']['rid']['id'] = 'rid';
$handler->display->display_options['fields']['rid']['table'] = 'users_roles';
$handler->display->display_options['fields']['rid']['field'] = 'rid';
$handler->display->display_options['fields']['rid']['label'] = '';
$handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['rid']['element_default_classes'] = FALSE;
/* Fält: Användare: Skola */
$handler->display->display_options['fields']['field_user_school']['id'] = 'field_user_school';
$handler->display->display_options['fields']['field_user_school']['table'] = 'field_data_field_user_school';
$handler->display->display_options['fields']['field_user_school']['field'] = 'field_user_school';
$handler->display->display_options['fields']['field_user_school']['label'] = '';
$handler->display->display_options['fields']['field_user_school']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_user_school']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_user_school']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_user_school']['delta_offset'] = '0';
/* Fält: Användare: Klass */
$handler->display->display_options['fields']['field_user_class']['id'] = 'field_user_class';
$handler->display->display_options['fields']['field_user_class']['table'] = 'field_data_field_user_class';
$handler->display->display_options['fields']['field_user_class']['field'] = 'field_user_class';
$handler->display->display_options['fields']['field_user_class']['label'] = '';
$handler->display->display_options['fields']['field_user_class']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_user_class']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_user_class']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_user_class']['delta_offset'] = '0';
/* Sort criterion: Användare: Förnamn (field_firstname) */
$handler->display->display_options['sorts']['field_firstname_value']['id'] = 'field_firstname_value';
$handler->display->display_options['sorts']['field_firstname_value']['table'] = 'field_data_field_firstname';
$handler->display->display_options['sorts']['field_firstname_value']['field'] = 'field_firstname_value';
/* Sort criterion: Användare: Efternamn (field_lastname) */
$handler->display->display_options['sorts']['field_lastname_value']['id'] = 'field_lastname_value';
$handler->display->display_options['sorts']['field_lastname_value']['table'] = 'field_data_field_lastname';
$handler->display->display_options['sorts']['field_lastname_value']['field'] = 'field_lastname_value';
/* Contextual filter: Användare: Klass (field_user_class) */
$handler->display->display_options['arguments']['field_user_class_tid']['id'] = 'field_user_class_tid';
$handler->display->display_options['arguments']['field_user_class_tid']['table'] = 'field_data_field_user_class';
$handler->display->display_options['arguments']['field_user_class_tid']['field'] = 'field_user_class_tid';
$handler->display->display_options['arguments']['field_user_class_tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_user_class_tid']['exception']['title'] = 'Alla';
$handler->display->display_options['arguments']['field_user_class_tid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_user_class_tid']['default_argument_options']['argument'] = '6271';
$handler->display->display_options['arguments']['field_user_class_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_user_class_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_user_class_tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_user_class_tid']['break_phrase'] = TRUE;
/* Filter criterion: Användare: Aktiv */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'contains';
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'Sök efter namn';
$handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
$handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
  2 => '2',
  9 => 0,
  8 => 0,
  10 => 0,
  12 => 0,
  6 => 0,
  11 => 0,
  1 => 0,
);
$handler->display->display_options['filters']['combine']['fields'] = array(
  'field_firstname' => 'field_firstname',
  'field_lastname' => 'field_lastname',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page_users_filtered');
$handler->display->display_options['path'] = 'users-filtered-class';
$translatables['users_filtered_class'] = array(
  t('Master'),
  t('Users filtered class'),
  t('more'),
  t('Sök'),
  t('Återställ'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« första'),
  t('‹ föregående'),
  t('nästa ›'),
  t('sista »'),
  t('([rid])'),
  t('Alla'),
  t('Sök efter namn'),
  t('Page'),
);
$views[$view->name] = $view;


$view = new view();
$view->name = 'users_unfiltered';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'users';
$view->human_name = 'Users unfiltered';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Users unfiltered';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  6 => '6',
  11 => '11',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Sök';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
$handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '30';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '5';
$handler->display->display_options['pager']['options']['tags']['first'] = '« första';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ föregående';
$handler->display->display_options['pager']['options']['tags']['next'] = 'nästa ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'sista »';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'field_firstname' => 'field_firstname',
  'field_lastname' => 'field_lastname',
  'name' => 'name',
  'rid' => 'rid',
  'field_user_class' => 'field_user_class',
);
/* Fält: Användare: Förnamn */
$handler->display->display_options['fields']['field_firstname']['id'] = 'field_firstname';
$handler->display->display_options['fields']['field_firstname']['table'] = 'field_data_field_firstname';
$handler->display->display_options['fields']['field_firstname']['field'] = 'field_firstname';
$handler->display->display_options['fields']['field_firstname']['label'] = '';
$handler->display->display_options['fields']['field_firstname']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_firstname']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_firstname']['element_default_classes'] = FALSE;
/* Fält: Användare: Efternamn */
$handler->display->display_options['fields']['field_lastname']['id'] = 'field_lastname';
$handler->display->display_options['fields']['field_lastname']['table'] = 'field_data_field_lastname';
$handler->display->display_options['fields']['field_lastname']['field'] = 'field_lastname';
$handler->display->display_options['fields']['field_lastname']['label'] = '';
$handler->display->display_options['fields']['field_lastname']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_lastname']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_lastname']['element_default_classes'] = FALSE;
/* Fält: Användare: Namn */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
/* Fält: Användare: Roller */
$handler->display->display_options['fields']['rid']['id'] = 'rid';
$handler->display->display_options['fields']['rid']['table'] = 'users_roles';
$handler->display->display_options['fields']['rid']['field'] = 'rid';
$handler->display->display_options['fields']['rid']['label'] = '';
$handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['rid']['element_default_classes'] = FALSE;
/* Fält: Användare: Skola */
$handler->display->display_options['fields']['field_user_school']['id'] = 'field_user_school';
$handler->display->display_options['fields']['field_user_school']['table'] = 'field_data_field_user_school';
$handler->display->display_options['fields']['field_user_school']['field'] = 'field_user_school';
$handler->display->display_options['fields']['field_user_school']['label'] = '';
$handler->display->display_options['fields']['field_user_school']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_user_school']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_user_school']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_user_school']['delta_offset'] = '0';
/* Fält: Användare: Klass */
$handler->display->display_options['fields']['field_user_class']['id'] = 'field_user_class';
$handler->display->display_options['fields']['field_user_class']['table'] = 'field_data_field_user_class';
$handler->display->display_options['fields']['field_user_class']['field'] = 'field_user_class';
$handler->display->display_options['fields']['field_user_class']['label'] = '';
$handler->display->display_options['fields']['field_user_class']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_user_class']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_user_class']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_user_class']['delta_offset'] = '0';
/* Sort criterion: Användare: Förnamn (field_firstname) */
$handler->display->display_options['sorts']['field_firstname_value']['id'] = 'field_firstname_value';
$handler->display->display_options['sorts']['field_firstname_value']['table'] = 'field_data_field_firstname';
$handler->display->display_options['sorts']['field_firstname_value']['field'] = 'field_firstname_value';
/* Sort criterion: Användare: Efternamn (field_lastname) */
$handler->display->display_options['sorts']['field_lastname_value']['id'] = 'field_lastname_value';
$handler->display->display_options['sorts']['field_lastname_value']['table'] = 'field_data_field_lastname';
$handler->display->display_options['sorts']['field_lastname_value']['field'] = 'field_lastname_value';
/* Filter criterion: Användare: Aktiv */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'contains';
$handler->display->display_options['filters']['combine']['group'] = 1;
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'Namn';
$handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
$handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
  2 => '2',
  9 => 0,
  8 => 0,
  10 => 0,
  12 => 0,
  6 => 0,
  11 => 0,
  1 => 0,
);
$handler->display->display_options['filters']['combine']['fields'] = array(
  'field_firstname' => 'field_firstname',
  'field_lastname' => 'field_lastname',
);
/* Filter criterion: Användare: Skola (field_user_school) */
$handler->display->display_options['filters']['field_user_school_tid']['id'] = 'field_user_school_tid';
$handler->display->display_options['filters']['field_user_school_tid']['table'] = 'field_data_field_user_school';
$handler->display->display_options['filters']['field_user_school_tid']['field'] = 'field_user_school_tid';
$handler->display->display_options['filters']['field_user_school_tid']['value'] = '';
$handler->display->display_options['filters']['field_user_school_tid']['group'] = 1;
$handler->display->display_options['filters']['field_user_school_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_user_school_tid']['expose']['operator_id'] = 'field_user_school_tid_op';
$handler->display->display_options['filters']['field_user_school_tid']['expose']['label'] = 'Skola';
$handler->display->display_options['filters']['field_user_school_tid']['expose']['operator'] = 'field_user_school_tid_op';
$handler->display->display_options['filters']['field_user_school_tid']['expose']['identifier'] = 'field_user_school_tid';
$handler->display->display_options['filters']['field_user_school_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_user_school_tid']['expose']['remember_roles'] = array(
  2 => '2',
  9 => 0,
  8 => 0,
  10 => 0,
  12 => 0,
  6 => 0,
  11 => 0,
  1 => 0,
);
$handler->display->display_options['filters']['field_user_school_tid']['vocabulary'] = 'organizational_structure';
/* Filter criterion: Användare: Klass (field_user_class) */
$handler->display->display_options['filters']['field_user_class_tid']['id'] = 'field_user_class_tid';
$handler->display->display_options['filters']['field_user_class_tid']['table'] = 'field_data_field_user_class';
$handler->display->display_options['filters']['field_user_class_tid']['field'] = 'field_user_class_tid';
$handler->display->display_options['filters']['field_user_class_tid']['value'] = '';
$handler->display->display_options['filters']['field_user_class_tid']['group'] = 1;
$handler->display->display_options['filters']['field_user_class_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_user_class_tid']['expose']['operator_id'] = 'field_user_class_tid_op';
$handler->display->display_options['filters']['field_user_class_tid']['expose']['label'] = 'Klass';
$handler->display->display_options['filters']['field_user_class_tid']['expose']['operator'] = 'field_user_class_tid_op';
$handler->display->display_options['filters']['field_user_class_tid']['expose']['identifier'] = 'field_user_class_tid';
$handler->display->display_options['filters']['field_user_class_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_user_class_tid']['expose']['remember_roles'] = array(
  2 => '2',
  9 => 0,
  8 => 0,
  10 => 0,
  12 => 0,
  6 => 0,
  11 => 0,
  1 => 0,
);
$handler->display->display_options['filters']['field_user_class_tid']['vocabulary'] = 'organizational_structure';
/* Filter criterion: Användare: Roller */
$handler->display->display_options['filters']['rid']['id'] = 'rid';
$handler->display->display_options['filters']['rid']['table'] = 'users_roles';
$handler->display->display_options['filters']['rid']['field'] = 'rid';
$handler->display->display_options['filters']['rid']['group'] = 1;
$handler->display->display_options['filters']['rid']['exposed'] = TRUE;
$handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
$handler->display->display_options['filters']['rid']['expose']['label'] = 'Roller';
$handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
$handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
$handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
  2 => '2',
  9 => 0,
  8 => 0,
  10 => 0,
  12 => 0,
  6 => 0,
  11 => 0,
  1 => 0,
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page_users_unfiltered');
$handler->display->display_options['path'] = 'users-unfiltered';
$translatables['users_unfiltered'] = array(
  t('Master'),
  t('Users unfiltered'),
  t('more'),
  t('Sök'),
  t('Återställ'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« första'),
  t('‹ föregående'),
  t('nästa ›'),
  t('sista »'),
  t('([rid])'),
  t('Namn'),
  t('Skola'),
  t('Klass'),
  t('Roller'),
  t('Page'),
);
$views[$view->name] = $view;
