<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="es">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<title>Classnet Technology - <?php echo $title?></title>
<?php 
		// Metas			
		
		if (!isset($keywords))
			$keywords = array();
		array_unshift($keywords,'classnet,technology,consulting,consultoría,capacitación,formación,tablero de comando,sistema,SAP,parametrización,reportes,excel,access,balanced scorecard,ms-office,coaching informático,planillas,logística,auditorias,RR.HH.,finanzas,simuladores financieros,análisis de costos,optimización procesos');
		add_meta('keywords', implode(',', $keywords));
		
		if (isset($description))
			add_meta('description', $description);
		
		if (isset($noindex))
			add_meta('robots', 'noindex, nofollow');
		else
			add_meta('robots', 'index, follow');
		add_meta('copyright', '2009-2016 Classnet Technology');
		add_meta('author', 'Ariel Flesler');
		add_meta('language', 'es-ar');
		
		if ($page === '')
			add_meta('google-site-verification', '3icQKukuoaNoQcIlaMJv0uKzvJX-mpEQtDx0f-yvgw8');
		
		
		// Links		
		
		add_link('favicon.ico', 'shortcut icon', 'image/x-icon');
		add_link('css/style.css', 'stylesheet', 'text/css');
		
		/*
		add_link('', 'start');
		add_link($tour_prev, 'prev');
		add_link($tour_next, 'next');
		
		if (count($parts) > 1)
			add_link($tour_next, 'parent');
		*/
			
		add_js('common');
		
		add_comment('Last Modified: '.time())
?>
</head>