<?php
	if (isset($_GET['f'])) {
		$download = $_GET['f'];
		$title = 'Formulario de Descarga';
		$content_url = 'form.inc';
		$save = false;
		$description = 'Formulario de descarga para '.$download;
	}
	else if (isset($_POST['file'])) 
	{				
		$file = $_POST['file'];
		$download_file = 'archivos/'.$file;
		
		// Send mail
		$_POST['data']['subject'] = 'Descarga de '.$_POST['data']['name'];
		$_POST['data']['message'] = 'Se ha descargado '.$file;
		
		require_once('../includes/prelude.inc');
		require(rurl('sender'));
		
		$motive = $file;
		require(rurl('logger'));
		
		// Redirect to download
		header('Refresh: 3; url='.$download_file);
		//header('Location: '.$download_file);
		
		// Temp page
		unset($content);
		$noindex = true;
		$content_url = 'downloading.inc';
		$title = 'Descargando...';
		$description = 'Descargando '.$file;
	}
	else
	{
		$content_url = 'content.inc';
		$description = 'Ejemplos en forma libre y gratuita. Capacitación en SAP, Excel, Access. Proveemos de Tableros de Comando, Simuladores (Financieros, RR.HH., Compras, Logística, Ventas)';
	}

	$sidebar_image = 'contenido-libre';
	
	require('../includes/page.inc');
?>