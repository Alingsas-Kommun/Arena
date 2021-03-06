<?php
/**
 * @file
 * bootstrap-panel.tpl.php
 *
 * Markup for Bootstrap panels ([collapsible] fieldsets).
 */

?>
<fieldset <?php print $attributes; ?>>
  <?php if ($title): ?>
    <?php if ($collapsible): ?>
    <legend class="panel-heading">
      <span class="panel-title fieldset-legend" data-toggle="collapse" data-target=".<?php print $target; ?>.panel-collapse"><?php print $title; ?></span>
    </legend>
    <?php else: ?>
    <legend class="panel-heading">
      <span class="panel-title fieldset-legend"><?php print $title; ?></span>
    </legend>
    <?php endif; ?>
  <?php endif; ?>
  <?php if ($collapsible): ?>
  <div class="<?php print $target; ?> panel-collapse collapse fade<?php print (!$collapsed ? ' in' : ''); ?>">
  <?php endif; ?>
  <div class="panel-body">
    <?php if ($description): ?><div class="help-block"><?php print $description; ?></div><?php endif; ?>
    <?php print $content; ?>
  </div>
  <?php if ($collapsible): ?>
  </div>
  <?php endif; ?>
</fieldset>
