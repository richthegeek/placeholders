jQuery(function($) {
	Drupal.behaviors.placeholders = {
		attach: function(context) {
			$('.block-placeholders .content', context).text(function() {
				return $(this).parent().outerWidth(true) + ' x ' + $(this).parent().height();
			});
		}
	};
});