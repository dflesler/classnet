<?php
	
	$data = $_POST['data'];
	$name = $data['name'];
	$email = $data['email'];
	$area = $data['area'];

	$file = fopen("$root_dir/emails.txt", 'a');
	fwrite($file, "\"$name\" <$email> $area $motive\n");
	fclose($file);
?>
