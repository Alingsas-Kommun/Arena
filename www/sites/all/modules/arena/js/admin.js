(function ($) {
  'use strict';

  Drupal.behaviors.handleOrganizationalStructure = {
    attach: function () {
      if ($('#edit-promote').prop('checked') || $('#edit-promote').length == 0){
        setTimeout(function () {
          jQuery('#edit-field-access-groups .term-reference-menu .selector ul ul li:first-child span.name').trigger('click');
          jQuery('#edit-field-organizational-structure .term-reference-menu .selector ul ul li:first-child span.name').trigger('click');
        }, 1000);

        $('#edit-field-organizational-structure').slideDown();
      }
      else {
        $('#edit-field-organizational-structure').slideUp();
      }

      $('#edit-promote').on('click', function() {
        if($('#edit-promote').prop('checked')){
          $('#edit-field-organizational-structure').slideDown();
        }
        else {
          $('#edit-field-organizational-structure').slideUp();
        }
      });
      //hide options fieldset if empty
      if($('#edit-additional-settings .panel-body').children().length <= 0) {
        $('#edit-additional-settings').hide();
      }
    }
  };

})(jQuery);
