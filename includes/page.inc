<?php
	$root_dir = str_replace('\\', '/', dirname(dirname(__FILE__)));

	require_once("$root_dir/includes/prelude.inc");

	if ($save)
		ob_start();
	
	require(rurl('functions'));
	require(rurl('head'));
	require(rurl('open'));
	require(rurl('header'));
	require(rurl('menu'));
	require(rurl('main'));
	require(rurl('footer'));
	require(rurl('ga'));
	require(rurl('close'));
	
	if ($save) {
		$html = ob_get_contents();
		ob_end_flush();
		file_put_contents( $base_dir.'/index.html', $html );
	}
?>