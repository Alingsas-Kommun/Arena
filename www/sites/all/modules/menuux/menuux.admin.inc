<?php
/**
 * Replace the default menu fieldset with our menu browser
 *
 * @param array $form
 *  Drupal form array
 * @param array $form_state
 *  Drupal form state array
 */
function menuux_node_form_alter(&$form, &$form_state) {
  if (!isset($form['menu'])) {
    return;
  }
  unset($form['menu']);
  $node = &$form['#node'];
  unset($node->menu);
  $form['fmenu'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add to menu'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
    '#access' => user_access('administer menu'),
    '#group' => 'additional_settings',
  );
  $options = menuux_available_menus($node->type);
  array_unshift($options, '<' . t('None') . '>');
  $form['fmenu']['menu_name'] = array(
    '#type' => 'select',
    '#title' => t('Menu'),
    '#description' => t('Choose the menu you want to add this node to, or choose "none" if you don\'t want to add this node to a menu.'),
    '#options' => $options,
    '#default_value' => $node->fmenu['menu_name'],
  );
  $form['fmenu']['positioning'] = array(
    '#type' => 'container',
    '#title' => t('Name and position'),
    '#description' => t('After a menu has been chosen it will appear below. Browse the menu and add the content you are editing to the menu by using the icons that appear when you hover over or tap the existing menu items.'),
    '#collapsible' => TRUE,
    '#states' => array(
      'invisible' => array(
        '#edit-fmenu-menu-name' => array('value' => '0'),
      ),
    )
  );
  if ($node->fmenu['menu_name']) {
    $form['fmenu']['positioning']['#attributes']['style'] = 'display:block;';
  }
  $menu = empty($node->fmenu['menu_name']) ? '<em>' . t('Choose a menu') . '</em>' : menuux_get_menu($node->fmenu['menu_name'], $node->fmenu['mlid']);
  $form['fmenu']['positioning']['menu_browser'] = array(
    '#type' => 'markup',
    '#markup' => '<div id="fmenu-browser">' . $menu . '</div>',
  );
  $form['fmenu']['related_link'] = array(
    '#type' => 'hidden',
    '#default_value' => isset($node->fmenu['related_link']) ? $node->fmenu['related_link'] : '',
    '#attributes' => array(
      'id' => 'edit-fmenu-related-link'
    ),
  );
  $form['fmenu']['relation_type'] = array(
    '#type' => 'hidden',
    '#default_value' => isset($node->fmenu['relation_type']) ? $node->fmenu['relation_type'] : '',
    '#attributes' => array(
      'id' => 'edit-fmenu-relation-type'
    ),
  );
  $form['fmenu']['link_title'] = array(
    '#type' => 'hidden',
    '#maxlength' => 255,
    '#default_value' => empty($node->fmenu['link_title']) ? $node->title : $node->fmenu['link_title'],
    '#attributes' => array(
      'id' => 'edit-fmenu-link-title'
    ),
  );
  $form['fmenu']['old_link_title'] = array(
    '#type' => 'value',
    '#value' => $node->fmenu['link_title'],
  );

  $form['fmenu']['old_mlid2'] = array(
    '#type' => 'hidden',
    '#value' => $node->fmenu['mlid'],
    '#attributes' => array(
      'id' => 'edit-fmenu-old-mlid2'
    ),
  );
  $form['fmenu']['mlid'] = array(
    '#type' => 'value',
    '#value' => $node->fmenu['mlid'],
  );
  $form['fmenu']['weight'] = array(
    '#type' => 'value',
    '#value' => $node->fmenu['weight'],
  );
  $form['fmenu']['plid'] = array(
    '#type' => 'value',
    '#value' => $node->fmenu['plid'],
  );
  $form['fmenu']['old_menu_name'] = array(
    '#type' => 'value',
    '#value' => $node->fmenu['menu_name'],
  );
  $form['fmenu']['has_children'] = array(
    '#type' => 'value',
    '#value' => $node->fmenu['has_children'],
  );
  $form['fmenu']['#theme'] = 'menuux_node_form';
}

/**
 * Validate the menu-browser part of nodes beeing created.
 *
 * @param object $node
 *  The node object for the node beeing edited/created
 */
function menuux_node_form_validate(&$node) {
  $illegal = FALSE;
  if ($node->fmenu['related_link']) {
    if (empty($node->fmenu['link_title'])) {
      form_set_error('', t('You must provide a name for your menu element.') . '<div id="form-error-name"></div>');
    }
    if (!is_numeric($node->fmenu['related_link']) || intval($node->fmenu['related_link']) != $node->fmenu['related_link']) {
      $illegal = TRUE;
    }
    $menu_name = db_query('SELECT menu_name FROM {menu_links} WHERE mlid = :mlid', array(
      ':mlid' => $node->fmenu['related_link'])
    )->fetch(PDO::FETCH_OBJ)->menu_name;
    if ($menu_name) {
      $available_menus = menuux_available_menus($node->type);
      if (!isset($available_menus[$menu_name])) {
        $illegal = TRUE;
      }
    }
    else {
      $illegal = TRUE;
    }
  }
  elseif (!empty($node->fmenu['mlid']) && $node->fmenu['menu_name'] == $node->fmenu['old_menu_name'] && empty($node->fmenu['link_title'])) {
    form_set_error('', t('You must provide a name for your menu element.') . '<div id="form-error-name"></div>');
  }
  if ($illegal) {
    form_set_error('', t('An illegal choice has been detected. Please contact the site administrator.'));
  }
}

/**
 * Handle the menubrowser part of nodes being inserted or updated
 *
 * @param object $node
 *  The node beeing inserted/updated
 */
function menuux_node_form_submit(&$node) {
  if (!empty($node->fmenu['mlid']) && $node->fmenu['menu_name'] == '0') {
    menu_link_delete($node->fmenu['mlid']);
    return;
  }
  $link = array(
    'link_title' => trim($node->fmenu['link_title']),
    'link_path' => "node/$node->nid",
    'menu_name' => $node->fmenu['menu_name'],
  );
  if (!empty($node->fmenu['mlid'])) {
    $link['mlid'] = $node->fmenu['mlid'];
    $link['has_children'] = $node->fmenu['has_children'];
    if (empty($node->fmenu['related_link'])) {
      if ($node->fmenu['link_title'] != $node->fmenu['old_link_title']) {
        $link['plid'] = $node->fmenu['plid'];
        $link['weight'] = $node->fmenu['weight'];
      }
      elseif ($node->fmenu['menu_name'] == $node->fmenu['old_menu_name']) {
        return;
      }
    }
  }
  if (!empty($node->fmenu['related_link'])) {
    $related_link = db_query('SELECT * FROM {menu_links} WHERE mlid = :mlid', array(
      ':mlid' => $node->fmenu['related_link']
    ))->fetchAssoc();
    switch ($node->fmenu['relation_type']) {
      case 'above':
        $link['plid'] = $related_link['plid'];
        $link['weight'] = $related_link['weight'] -1;
        break;
      case 'below':
        $link['plid'] = $related_link['plid'];
        $link['weight'] = $related_link['weight'] + 1;
        menuux_fix_menu_weights($related_link);
        break;
      case 'child':
        $link['plid'] = $related_link['mlid'];
        break;
    }
  }
  if ($link['menu_name']) {
    menu_link_save($link);
    menu_cache_clear($link['menu_name']);
  }
}

/**
 * Make sure weight are correct when a new item is inserted between existing ones.
 *
 * @param array $link_above
 *  The link we want to place a new item below
 */
function menuux_fix_menu_weights($link_above) {
  $same_as_related = db_query_range(
    "SELECT 1 FROM {menu_links} WHERE menu_name = :menu_name AND weight = :weight AND plid = :plid AND link_title > :link_title", 0, 1, array(
      ':menu_name' => $link_above['menu_name'],
      ':weight' => $link_above['weight'],
      ':plid' => $link_above['plid'],
      ':link_title' => $link_above['link_title'],
    )
  )->fetch(PDO::FETCH_NUM);
  // Several other links has the same weight as the one we want to be placed below...
  if ($same_as_related) {
    db_update('menu_links')
      ->expression('weight', 'weight + 2')
      ->condition('menu_name', $link_above['menu_name'])
      ->condition('weight', $link_above['weight'], '>=')
      ->condition('plid', $link_above['plid'])
      ->condition('link_title', $link_above['link_title'])
      ->execute();
  }
  else {
    $same_as_new = db_query_range(
      "SELECT 1 FROM {menu_links} WHERE menu_name = :menu_name AND weight = :weight AND plid = :plid", 0, 1, array(
        ':menu_name' => $link_above['menu_name'],
        ':weight' => $link_above['weight'] + 1,
        ':plid' => $link_above['plid'],
      )
    )->fetch(PDO::FETCH_NUM);
    // Several other links has the same weight as the one we want to be placed below...
    if ($same_as_new) {
      db_update('menu_links')
        ->expression('weight', 'weight + 1')
        ->condition('menu_name', $link_above['menu_name'])
        ->condition('weight', $link_above['weight'], '>')
        ->condition('plid', $link_above['plid'])
        ->execute();
    }
  }
}

/**
 * Get all available menus we can add nodes to.
 *
 * @return array menus
 *  All available menus
 */
function menuux_available_menus($type = FALSE) {
  $all_menus = menu_get_menus();
  if ($type === FALSE) {
    return $all_menus;
  }
  $menus = variable_get('menu_options_' . $type, array('main-menu' => 'main-menu'));
  $to_return = array();
  foreach ($menus as $key => $menu) {
    $to_return[$menu] = $all_menus[$menu];
  }
  return $to_return;
}

/**
 * Callback function for loading a menu using ajax
 *
 * @param string $menu_name
 *  Name of the menu to be loaded
 * @param int $active_mlid
 *  Id of the menu link that is already active
 */
function menuux_load_menu_ajax($menu_name, $active_mlid = FALSE) {
  drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');
  print menuux_get_menu($menu_name, $active_mlid);
}

/**
 * Generate a themed menu
 *
 * @param string $menu_name
 *  The menu we want to retrieve
 * @param int $active_mlid
 *  The id of the active menu link
 * @return string
 *  HTML representing the chosen menu
 */
function menuux_get_menu($menu_name, $active_mlid = FALSE) {
  $raw_menu = menu_tree_all_data($menu_name);
  $menu = array();
  menuux_generate_menu_rec($menu, $raw_menu, $active_mlid);
  return theme('menuux_menu', array('menu' => $menu));
}

/**
 * Generate a menu array for use in the menu browser
 *
 * This function is recursive
 *
 * @param array $menu
 *  The menu that is to be generated
 * @param array $raw_menu
 *  The menu as returned from menu_tree_all_data
 * @param int $active_mlid
 *  The id of the active link
 * @return boolean
 *  Was the mlid of the active item found in the menu?
 */
function menuux_generate_menu_rec(&$menu, $raw_menu, $active_mlid = FALSE) {
  $has_active = FALSE;
  foreach ($raw_menu as $data) {
    if ($data['link']['hidden'] >= 0) {
      $title = truncate_utf8($data['link']['title'], 30, TRUE, FALSE);
      if ($data['link']['hidden']) {
        $title .= ' ('. t('disabled') .')';
      }
      $mlid = $data['link']['mlid'];
      $menu[$mlid]['title'] = $title;
      if ($mlid == $active_mlid) {
        $menu[$mlid]['active'] = TRUE;
        $has_active = TRUE;
      }
      $menu[$mlid]['expanded'] = FALSE;
      if ($data['below']) {
        $below = array();
        $active_child = menuux_generate_menu_rec($below, $data['below'], $active_mlid);
        $has_active = $has_active || $active_child;
        if (!empty($below)) {
          $menu[$mlid]['below'] = $below;
        }
        if ($active_child) {
          $menu[$mlid]['expanded'] = TRUE;
        }
      }
    }
  }
  return $has_active;
}

/**
 * Theme the menu browser
 *
 * This function is recursive
 *
 * @param array $menu
 *  Menu as created by menuux_generate_menu_rec
 * @param int $level
 *  How deep in the menu we are
 * @return string
 *  HTML for the menu browser
 */
function theme_menuux_menu($variables, $level = 0) {
  $menu = $variables['menu'];
  $output = '<ul class="fmenu fmenu-level-' . $level . '">';
  $first = TRUE;
  foreach ($menu as $key => $link) {
    $has_below = isset($link['below']);
    $extra_class = $has_below ? $link['expanded'] ? ' fmenu-expanded' : ' fmenu-collapsed' : '';
    $extra_class .= isset($link['active']) ? ' fmenu-new' : '';
    $output .= '<li class="fmenu-link" data-mlid="' . $key . '"><div class="fmenu-link-inner' . $extra_class . '">';
    if (!isset($link['active'])) {
      $output .= '<div class="hover-options"><ul>';
      if (!$has_below) {
        $output .= '<li><a href="#" class="fmenu-child" title="' . t('Place as child') . '"></a></li>';
      }
      $output .= '<li><a href="#" class="fmenu-below" title="' . t('Place below') . '"></a></li>';
      if ($first) {
        $output .= '<li><a href="#" class="fmenu-above" title="'. t('Place above') .'"></a></li>';
        $first = FALSE;
      }
      $output .= '</ul></div>';
    }
    $below = $has_below && !isset($link['active']) ? theme_menuux_menu(array('menu' => $link['below']), $level + 1) : '';
    $title = isset($link['active']) ?
      '<div class="form-item"><input id="fmenu-link-input" type="text" size="60" maxlength="255" value="' . $link['title'] . '"/></div>' :
      '<span class="fmenu-link-title">' . (isset($link['title']) ? $link['title'] : '') . '</span>';
    $output .= $title . '</div>' . $below;
    $output .= '</li>';
  }
  $output .= '</ul>';
  return $output;
}

/**
 * Add required javascript and css to the node forms
 *
 * @param <type> $form
 * @return <type>
 */
function theme_menuux_node_form($form) {
  $p = drupal_get_path('module', 'menuux');
  drupal_add_js($p . '/js/menu.js');
  drupal_add_css($p . '/css/menu.css');
}