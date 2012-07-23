<?php

function placeholders_admin($form, &$form_state) {

	$settings = (object) _get_placeholders();

	$rows = array();
	foreach ($settings->blocks as $type => $count) {
		$qnt = array(
			'#name' => 'blocks[' . $type . ']',
			'#type' => 'select',
			'#options' => range(0,100),
			'#value' => $count
		);
		$rows[] = array(ucwords($type), drupal_render($qnt));
	}
	$form = array(
		'settings' => array(
			'#type' => 'fieldset',
			'#title' => t('Settings'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			'_show_blocks' => array(
				'#type' => 'checkbox',
				'#title' => 'Show placeholder blocks',
				'#description' => 'Temporarily stop placeholder blocks from showing. For deployment, they should be removed by settings quantities to 0',
				'#value' => $settings->_show_blocks
			),
		),
		'table' => array(
			'#theme' => 'table',
			'#header' => array('Type', 'Quantity'),
			'#rows' => $rows,
		),
		'actions' => array(
			'#type' => 'actions',
			'submit' => array(
				'#type' => 'submit',
				'#value' => 'Save'
			),
		),
	);
	return $form;
}

function placeholders_admin_submit($form, $form_state) {
	drupal_set_message('Placeholder block settings saved');
	
	$settings = (object) array(
		'_show_blocks' => $form_state['input']['_show_blocks'],
		'blocks' => $form_state['input']['blocks'],
	);
	variable_set('placeholders', (object) $settings);
}