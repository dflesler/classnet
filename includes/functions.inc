<?php
	function add_image($name, $alt='', $width='', $height='', $ext='jpg'){
		global $root;
		
		$png = $ext === 'png';
		$uri = "$root/images/$name.$ext";
		
		if ($png)
			echo "<span class='png' style='filter:progid:DXImageTransform.Microsoft.AlphaImageLoader(src=$uri)'>";
		
		echo "<img src='$uri' alt='$alt' title='$alt' width='$width' height='$height' />\n";
		
		if ($png)
			echo '</span>';
	}
	
	function add_meta($name, $content){
		echo "	<meta name='$name' content='$content' />\n";
	}
	
	function add_link($href, $rel, $type=''){
		global $root;
		
		echo "	<link href='$root/$href' rel='$rel'";

		if ($type)
			echo " type='$type'";

		echo " />\n";
	}
	
	function add_url($path=''){
		global $root;
		
		echo "$root/$path";
	}
	
	function add_js($name){
		global $root;
		echo "	<script type='text/javascript' src='$root/js/$name.js'></script>\n";
	}
	
	function add_email($name, $domain){
		$link = "$name (at) $domain (dot) com";
		echo "<script type='text/javascript'>email('$name', '$domain')</script><noscript><a href='mailto:$link'>$link</a></noscript>";
	}
	
	function add_comment($text){
		echo "	<!-- $text -->\n";
	}
	
	function endsWith( $str, $sub ) {
		return substr($str, strlen($str) - strlen($sub)) === $sub;
	}
?>