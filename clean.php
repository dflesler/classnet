<?php
	function out($text){
		echo $text.'...<br />';
	}

	out('Starting');
	
	for ($i = 0; $i < 3; $i++) {
		$preff = str_repeat('*/', $i);
		
		foreach( glob($preff.'index.html') as $filename ) {
			out("Deleting '$filename'");
			unlink($filename);
		}
	}
	
	out('Done');
?>