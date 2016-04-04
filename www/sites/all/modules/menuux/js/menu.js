var MenuUX = MenuUX || {};
var $ = jQuery;
$(document).ready(function() {
  MenuUX.init();
});

MenuUX.init = function() {
  MenuUX.loading = false;
  MenuUX.initing = true;
  MenuUX.urlStart = location.protocol + '//' + location.host + Drupal.settings.basePath;
  MenuUX.checkForErrors();
  MenuUX.initing = MenuUX.loading;
  if ($('#form-error-name').length) {
    $('#fmenu-link-input').addClass('error').val('');
  }
};

MenuUX.checkForErrors = function() {
  var relLink = $('#edit-fmenu-related-link').val();
  if (!isNaN($('#edit-fmenu-related-link').val()) && relLink != '') {
    MenuUX.menuChanged();
  }
};

MenuUX.initLink = function() {
  $('[data-mlid="' + $('#edit-fmenu-related-link').val() + '"] .fmenu-' + $('#edit-fmenu-relation-type').val() + ':first').trigger('click');
  $('#fmenu-browser .fmenu-expanded').trigger('click');
  $('#fmenu-link-input').parents('.fmenu-link').each(function(){
    $(this).children('.fmenu-collapsed').trigger('click');
  });
  if ($('#form-error-name').length) {
    $('#fmenu-link-input').addClass('error');
  }
};

Drupal.behaviors.MenuUX = {
  attach: function($el) {
    $('#edit-fmenu-menu-name:not(.MenuUX-processed)')
    .addClass('MenuUX-processed')
    .change(MenuUX.menuChanged);
    $('.fmenu-collapsed:not(.MenuUX-processed, .fmenu-new)', $el).click(MenuUX.expanderClicked).addClass('MenuUX-processed');
    $('.fmenu-expanded:not(.MenuUX-processed)', $el).click(MenuUX.expanderClicked).addClass('MenuUX-processed')
    .parent().children('ul.fmenu').show();
    $('.fmenu-above:not(.MenuUX-processed)', $el).click(MenuUX.aboveClicked).addClass('MenuUX-processed');
    $('.fmenu-below:not(.MenuUX-processed)', $el).click(MenuUX.belowClicked).addClass('MenuUX-processed');
    $('.fmenu-child:not(.MenuUX-processed)', $el).click(MenuUX.childClicked).addClass('MenuUX-processed');
    $('#fmenu-link-input:not(.MenuUX-processed)', $el).bind('change keyup', function() {
      $('#edit-fmenu-link-title').val($(this).val());
    }).addClass('MenuUX-processed');
  }
}

MenuUX.menuChanged = function(event) {
  if (!MenuUX.initing) {
    $('#edit-fmenu-relation-type, #edit-fmenu-related-link').val('');
  }
  var menuName = $('#edit-fmenu-menu-name').val();
  if (menuName == '0') {
    return;
  }
  var extra = $('#edit-fmenu-old-mlid2').val() == '' ? '' : '/' + $('#edit-fmenu-old-mlid2').val();
  $('#fmenu-browser').html('<div class="ahah-progress"><em>' + Drupal.t('Loading menu...') + '</em><div class="throbber"></div></div>');
  var get = {q:'node/add/menuux_load_menu/' + menuName + extra};
  MenuUX.loading = true;
  $.get(MenuUX.urlStart, get, MenuUX.recieveMenu, 'html');
};

MenuUX.recieveMenu = function(data) {
  $('#fmenu-browser').html(data);
  if ($('#fmenu-browser .fmenu-level-0 li').length == 0) {
    $('#fmenu-browser .fmenu-level-0').html('<li class="fmenu-link"><div class="fmenu-link-inner fmenu-new"></div></li>').find('.fmenu-new').append(MenuUX.createLinkField());
    $('#fmenu-browser').append('<em>' + Drupal.t('There are no other elements in this menu') + '</em>');
  }
  Drupal.attachBehaviors($('#fmenu-browser'));
  if (MenuUX.initing) {
    MenuUX.initLink();
  }
  if ($('#fmenu-link-input').length) {
    var title = $('#edit-fmenu-link-title').val();
    if (title.length) {
      $('#fmenu-link-input').val(title);
    }
    else {
      $('#edit-fmenu-link-title').val($('#fmenu-link-input').val());
    }
  }
  MenuUX.loading = false;
  MenuUX.initing = false;
};

MenuUX.expanderClicked = function(event) {
  var $this = $(this);
  if ($this.hasClass('fmenu-collapsed')) {
    $(this).addClass('fmenu-expanded').removeClass('fmenu-collapsed')
    .parent().children('ul.fmenu').show();
  }
  else {
    $(this).removeClass('fmenu-expanded').addClass('fmenu-collapsed')
    .parent().children('ul.fmenu').hide();
  }
  event.stopPropagation();
};

MenuUX.belowClicked = function(event) {
  var $clone = MenuUX.commonMoveActions.call(this, event);
  $clone.insertAfter($(this).parents('.fmenu-link').eq(0));
  if ($(this).parents('.fmenu-link-inner').hasClass('fmenu-expanded')) {
    $(this).parents('.fmenu-link-inner').trigger('click');
  }
  $('#edit-fmenu-relation-type').val('below');
  Drupal.attachBehaviors($('#fmenu-browser'));
};

MenuUX.aboveClicked = function(event) {
  var $clone = MenuUX.commonMoveActions.call(this, event);
  $clone.insertBefore($(this).parents('.fmenu-link').eq(0));
  $('#edit-fmenu-relation-type').val('above');
  Drupal.attachBehaviors($('#fmenu-browser'));
};

MenuUX.childClicked = function(event) {
  var $clone = MenuUX.commonMoveActions.call(this, event);
  var $ul = $('<ul class="fmenu fmenu-new-ul"></ul>').append($clone);
  $ul.insertAfter($(this).parents('.fmenu-link-inner').eq(0).addClass('fmenu-expanded').addClass('fmenu-new-expanded'));
  $('#edit-fmenu-relation-type').val('child');
  Drupal.attachBehaviors($('#fmenu-browser'));
}

MenuUX.commonMoveActions = function(event) {
  event.stopPropagation();
  event.preventDefault();
  var hadChildren = $('#fmenu-browser .fmenu-new').hasClass('fmenu-collapsed');
  $('#fmenu-browser .fmenu-new').parent().remove();
  $('#fmenu-browser .fmenu-new-ul').remove();
  $('#fmenu-browser .fmenu-new-expanded')
    .removeClass('fmenu-expanded fmenu-collapsed fmenu-new-expanded')
    .unbind('click', MenuUX.expanderClicked);
  var $clone = $(this).parents('.fmenu-link').eq(0).clone();
  $('#edit-fmenu-related-link').val($clone.attr('data-mlid'));
  $('.hover-options, .fmenu-link', $clone).remove();
  $('.fmenu-link-inner', $clone).removeClass('fmenu-expanded fmenu-collapsed').addClass('fmenu-new');
  if (hadChildren) {
    $('.fmenu-link-inner', $clone).addClass('fmenu-collapsed')
  }
  $('.fmenu-link-title', $clone).html('').append(MenuUX.createLinkField());
  return $clone;
};

MenuUX.createLinkField = function() {
  var extra = ' placeholder="' + Drupal.t('Write title here') + '"';
  var title = $('#edit-fmenu-link-title').val();
  if (title.length == 0 && $('#edit-title').length && !MenuUX.initing) {
    title = $('#edit-title').val();
  }
  if (title.length) {
    extra = ' value="' + title + '"';
  }
  $('#edit-fmenu-link-title').val(title);
  return $('<div class="form-item"><input id="fmenu-link-input" type="text" size="60" maxlength="255"' + extra + '/></div>');
};