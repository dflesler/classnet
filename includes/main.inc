
	<!-- MAIN -->
	<div id="contentWrap">
		<div id="content" class="center">
<?php require(rurl('sidebar')); ?>

			<!-- CONTENT -->
			<div id="text">
				<h1><?php echo $title?></h1>
<?php 
					if (isset($content)) {
						echo $content;
					} else {
						if (!isset($content_url))
							$content_url = 'content.ct';
						
						$content_url = $base_dir.'/'.$content_url;

						if (endsWith($content_url, '.inc'))
							require($content_url);
						else
							readfile($content_url);
					}
?>

			</div>
		</div>
		<div id="content_gradient">&nbsp;</div>
	</div>