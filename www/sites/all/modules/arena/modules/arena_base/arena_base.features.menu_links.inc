<?php
/**
 * @file
 * arena_base.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function arena_base_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_alla-skolor:users-unfiltered.
  $menu_links['main-menu_alla-skolor:users-unfiltered'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'users-unfiltered',
    'router_path' => 'users-unfiltered',
    'link_title' => 'Alla skolor',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_alla-skolor:users-unfiltered',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_min-skola:users-filtered-school.
  $menu_links['main-menu_min-skola:users-filtered-school'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'users-filtered-school',
    'router_path' => 'users-filtered-school',
    'link_title' => 'Min skola',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_min-skola:users-filtered-school',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_mina-grupper:min-klass.
  $menu_links['main-menu_mina-grupper:min-klass'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'min-klass',
    'router_path' => 'min-klass',
    'link_title' => 'Mina grupper',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_mina-grupper:min-klass',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_mitt-innehll:my/content.
  $menu_links['main-menu_mitt-innehll:my/content'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'my/content',
    'router_path' => 'my/content',
    'link_title' => 'Mitt innehåll',
    'options' => array(
      'identifier' => 'main-menu_mitt-innehll:my/content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_skapa-innehll:node/add.
  $menu_links['main-menu_skapa-innehll:node/add'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Skapa innehåll',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_skapa-innehll:node/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_start:<front>.
  $menu_links['main-menu_start:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Start',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_start:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alla skolor');
  t('Min skola');
  t('Mina grupper');
  t('Mitt innehåll');
  t('Skapa innehåll');
  t('Start');

  return $menu_links;
}
