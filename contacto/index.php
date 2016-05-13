<?php
	require_once('../includes/prelude.inc');

	if (isset($_POST['submit']))
	{
		$noindex = true;
		require(rurl('sender'));
		
		$motive = 'Contacto';
		require(rurl('logger'));
	}

	$content_url = 'content.inc';
	$sidebar_image = 'contacto';

	require(rurl('page'));
?>