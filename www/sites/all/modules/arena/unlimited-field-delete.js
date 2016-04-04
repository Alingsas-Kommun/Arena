//add remove button to multiple-fields
jQuery(function(){
	var removelink = jQuery('<a/>', {
	    class: 'tableremove-handle',
	    href: '#',
	    text: 'Ta bort'
	}).click(function(e){
		e.preventDefault();
		jQuery(this).closest('tr').hide().find('input[type=text]').val('');
	});
	jQuery('a.tabledrag-handle').parent().append(removelink);
});