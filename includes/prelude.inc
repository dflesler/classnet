<?php
	error_reporting(E_ALL);

	$filename = $_SERVER['SCRIPT_FILENAME'];
	$base_dir = dirname($filename);
	$cached = $base_dir.'/index.html';
	
	$production = strpos($_SERVER['SERVER_NAME'], 'e-classnet.com') !== false;

	if (!isset($save))
		$save = $production && $_SERVER['REQUEST_METHOD'] === 'GET' && basename($filename, '.php') === 'index';
	
	if ($save && file_exists($cached)){
		readfile($cached);
		exit;
	}
	
	
	$uri = preg_replace('/[?#].*/', '', $_SERVER['REQUEST_URI']);
	$base = dirname($uri.'a');
	
	$root_dir = str_replace('\\', '/', dirname(dirname(__FILE__)));
	
	$path = str_replace($root_dir, '', $base_dir);
	$root = str_replace($path, '', $base);
	
	if ($root === '/')
		$root = '';
	
	/* //Dump
	foreach(array('filename','base_dir','uri','base', 'path','root_dir','root') as $var)
		echo $var.'='.$$var.'<br>';
	/* */
	
	$parts = explode('/', $base);
		
	$page = basename($base);
	if ($page === 'classnet')
		$page = '';
	else
		array_shift($parts);
	
	// Links & Title
	
	$links = array(
		''					=> 'Inicio',
		'quienes-somos'		=> 'Quiénes Somos',
		'servicios' 		=> 'Servicios',
		'productos' 		=> 'Productos',
		'habilidades' 		=> 'Beneficios y Habilidades',
		'contenido-libre' 	=> 'Contenido Libre',
		'contacto' 			=> 'Contacto'
	);

	$other_links = array(
		'sistema-sap'		 		=> 'Sistema SAP',
		'aplicaciones-ms-office'	=> 'Aplicaciones MS-Office',
		'tablero-de-comando' 		=> 'Tablero de Comando',
		'coaching-informatico'		=> 'Coaching Informático',
		'gestion-de-tarjetas'		=> 'Gestión de Tarjetas de Crédito y Débito'
	);

	if (!isset($title))
	{
		if (isset($links[$page]))
			$title = $links[$page];
		else
			$title = $other_links[$page];
	}
	
	// Tour
	
	$tour = array(
		'', 'quienes-somos', 'servicios',
		'servicios/sistema-sap', 'servicios/aplicaciones-ms-office', 
		'servicios/tablero-de-comando', 'servicios/coaching-informatico',
		'productos', 'productos/gestion-de-tarjetas',
		'habilidades', 'contenido-libre', 'contacto'
	);

	$tour_c = count($tour);
	$tour_next = '';
	$tour_prev = '';

	foreach ($tour as $tour_i => $tour_v) {
		$last_part = strrchr($tour_v, '/');
		if ($last_part)
			$tour_v = substr($last_part,1);

		if ($tour_v === $page) {
			$tour_next_i = ($tour_i + 1) % $tour_c;
			$tour_next = $tour[$tour_next_i];
			
			$tour_prev_i = ($tour_i ? $tour_i : $tour_c) - 1;
			$tour_prev = $tour[$tour_prev_i];
			
			break;
		}
	}
	
	if ($tour_next)
		$tour_next .= '/';
	if ($tour_prev)
		$tour_prev .= '/';
	
	function rurl($name){
		global $root_dir;
		return $root_dir."/includes/$name.inc";
	}
?>