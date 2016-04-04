<?php
/**
 * @file
 * arena_base.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function arena_base_locale_default_languages() {
  $languages = array();

  // Exported language: sv.
  $languages['sv'] = array(
    'language' => 'sv',
    'name' => 'Swedish',
    'native' => 'Svenska',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 2,
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'sv',
    'weight' => 0,
  );
  return $languages;
}
