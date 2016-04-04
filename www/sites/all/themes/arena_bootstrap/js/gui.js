(function ($) {
  'use strict';

  Drupal.behaviors.handleNewsSlider = {
    attach: function () {
      $('.news-slider .content').each(function(){
        if($(this).children('.field-name-field-introduction').length == 1 && $(this).children('.field, .webform-client-form').length > 1) {
          $('<span>').addClass('show-more glyphicon glyphicon-menu-down').prop('aria-hidden', true).appendTo($(this)).on('click', function( event ){
            $(this).data.parent = $(this).closest('.content');
            $(this).data.parent.toggleClass('toggled');
            $('.field', $(this).data.parent).not('.field-name-field-introduction').not('.field-name-field-image').slideToggle();
            $('.webform-client-form', $(this).data.parent).slideToggle();
          });
          $('<span>').addClass('hide-more glyphicon glyphicon-menu-up').prop('aria-hidden', true).appendTo($(this)).on('click', {parent: $(this)}, function( event ){
            $(this).data.parent = $(this).closest('.content');
            $(this).data.parent.toggleClass('toggled');
            $('.field', $(this).data.parent).not('.field-name-field-introduction').not('.field-name-field-image').slideToggle();
            $('.webform-client-form', $(this).data.parent).slideToggle();
          });
        }
        else {
          $(this).addClass('no-toggle');
        }
      });
    }
  };
  
})(jQuery);
