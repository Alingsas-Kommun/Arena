
(function ($) {
    $.fn.termReferenceMenu = function (options) {
        var settings = {
            selectedClass: 'selected',
            addText: 'Add item',
            deleteText: 'Delete item',
            title: 'No title'
        };
        return this.each(function () {
            if (options) {
                $.extend(settings, options);
            }
            var $this = $(this);
            $this.cache = [];
            $this.items = [];
            $this.itemsselected = [];
            $this.lock = 0;
            var init = function () {
                $this.find('input').hide();
                if($this.find('input').val()) {
                	$this.items = $this.find('input').val().split(',');
                }

                //set behaviours
                $this.delegate("li span.add", "click", function(){
                  if($(this).closest('li').hasClass('locked') === false) {
                	  addItem($(this).closest('li'));
                  }
                });
                $this.delegate("li span.del", "click", function(){
                  delItem($(this).closest('li'));
                });
                $this.delegate(".has-children span.name", "click", function(){
                  if($(this).closest('li').find('ul').hasClass('open')) {
                	  $(this).closest('li').find('ul').removeClass('open').slideUp();
                  }
                  else {
                	  getItems($(this).closest('li'));
                	  $(this).closest('li').find('ul').addClass('open').slideDown();
                  }
                });
                $this.delegate("span.add, span.del", "mouseenter mouseleave", function(){
                    $(this).closest('li').toggleClass('over');
                });                                
                $this.find('.form-item').append('<div class="term-reference-menu"><div class="container"><ul><li>Ingen grupp vald</li></ul></div><label for="organisation-container">Lägg till fler:</label><div class="selector"><ul name="0"></ul></div></div>');
                getItems($this.find('.selector ul'));
                
                $this.itemsselected = Drupal.settings[$this.attr('id').substr(5).replace(/-/g,'_')].itemsselected;
                if($this.items.length > 0) {
                	$this.find('.container ul > li').remove();
                	$.each($this.itemsselected, function(index, val){
                		if(val.path.length > 0){
                			$.each(val.path, function(index2, val2){
                			  $this.find('.container ul li[name="' + val.tid + '"]').remove();
                				$this.find('.container ul').append('<li name="' + val.tid + '"><span class="dot"></span><span class="name">' + val2 + ' &gt; ' + val.name + '</span><span class="del glyphicon glyphicon-minus"></span></li>');
                			});
                		}
                		else {
                		  $this.find('.container ul li[name="' + val.tid + '"]').remove();
                			$this.find('.container ul').append('<li name="' + val.tid + '"><span class="dot"></span><span class="name">' + val.name + '</span><span class="del glyphicon glyphicon-minus"></span></li>');
                		}
                	});
                }
                
            };
            
            var addItem = function( object ) {
            	//console.log($this);
            	if(typeof object !== undefined && object.attr('name') !== undefined) {
                    var tid = object.attr('name');
                    if($.inArray(tid, $this.items) < 0) {
                    	if($this.items.length <= 0) {
                    		$this.find('.container ul > li').remove();
                    	}
                    	$this.items.push(tid);
                    	if($this.cache[tid].path.lenght > 0){
                    		$.each($this.cache[tid].path, function(index, val){
                    		  $this.find('.container ul li[name="' + tid + '"]').remove();
                    			$this.find('.container ul').append('<li name="' + tid + '"><span class="dot"></span><span class="name">' + val + ' &gt; ' + $this.cache[tid].name + '</span><span class="del glyphicon glyphicon-minus"></span></li>');
                    		});
                    	}
                    	else {
                    	  $this.find('.container ul li[name="' + tid + '"]').remove();
                    		$this.find('.container ul').append('<li name="' + tid + '"><span class="dot"></span><span class="name">' + $this.cache[tid].name + '</span><span class="del glyphicon glyphicon-minus"></span></li>');
                    	}
                    	$this.find('input').val($this.items.join(','));
                    	rebuildMenu();
                    }
            	}
            }
            
            var delItem = function( object ) {
            	if(typeof object !== undefined && object.attr('name') !== undefined) {
	                var tid = object.attr('name');
	                if($.inArray(tid, $this.items) >= 0) {
	                	$this.items.splice($.inArray(tid, $this.items),1);
	                	$this.find('input').val($this.items.join(','));
	                	$this.find('.container li[name="' + tid + '"]').remove();
	                	if($this.items.length <= 0) {
	                		$this.find('.container ul').append('<li ><span class="name">Ingen grupp vald</span></li>');
	                	}
	                	rebuildMenu();
	                }
            	}
            }
            
            var rebuildMenu = function() {
            	$this.find('.selector li').removeClass('selected');
            	$.each($this.items, function(index, val) {
            		$this.find('.selector li[name="' + val + '"]').addClass('selected');
            	});
            }
            
            var getItems = function( object ){
            	if(typeof object !== undefined && object.attr('name') !== undefined) {
            		var tid = object.attr('name');
            		//var voc = object.parent().parent().parent().parent().attr('id');
            		var voc = Drupal.settings[$this.attr('id').substr(5).replace(/-/g,'_')].field_name;
            	  if($this.lock == 0) {
            		    if (typeof $this.cache[tid] !== "undefined" && $this.cache[tid].loaded === true) {
            		    	if(object.find('ul').length == 0) {
	            		    	object.append('<ul></ul>');
	            		    	$.each($this.cache[tid].children, function( index, val) {
	            		    		var attributes = '';
			                        if(val.has_children === true) {
			                          attributes = 'has-children';
			                        }
			                        if(val.parents.length > 1) {
			                            attributes += ' multi';
			                        }
                              if(val.locked === true) {
		                              attributes += ' locked';
		                          }
	                        object.find('ul').append('<li class="' + attributes + '" name="' + val.tid + '"><span class="dot"></span><span class="name">' + val.name + '</span><span class="add glyphicon glyphicon-plus"></span></li>');
	                      });
	            		   object.find('ul').addClass("open").slideDown();
	            		   rebuildMenu();
            		    	}
            		    }
            		    else {
            		      $this.lock = 1;
            		      $.getJSON('/term-reference-menu/' + tid + '/' + voc + '/get', function(data) {
            		        $this.lock = 0;
            		        if(!$this.cache[tid]) {
            		        	$this.cache[tid] = {};
            		        }
            		        $this.cache[tid].children = data;
            		        $this.cache[tid].loaded = true;
            		        object.append('<ul></ul>');
            		        $.each(data, function( index, val) { 
            		        	$this.cache[val.tid] = val;
            		        	$this.cache[val.tid].loaded = false;
            		        	var attributes = '';
            		        	if(val.has_children === true) {
            		        		attributes = 'has-children';
            		        	}
            		        	if(val.parents.length > 1) {
		                            attributes += ' multi';
		                        }
		                      if(val.locked === true) {
		                            attributes += ' locked';
		                      }
            		        	object.find('ul').append('<li class="' + attributes + '" name="' + val.tid + '"><span class="dot"></span><span class="name">' + val.name + '</span><span class="add glyphicon glyphicon-plus"></span></li>');
            		        });
            		        object.find('ul').addClass("open").slideDown();
            		        rebuildMenu();
            		      })
            		      .error(function(data){
            		    	  alert('Fel: Kunde inte ladda listan.');
            		    	  $this.lock = 0;
            		      });
            		    }
            		  }
            		}
            }
            
                     
          init();

        });
    }
})(jQuery);

jQuery(function(){
	jQuery('.field-widget-term-reference-menu').termReferenceMenu();
});
