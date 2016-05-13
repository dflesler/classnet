			<!-- SIDEBAR -->
			<div id="sidebar">
				<?php 
					if (isset($sidebar_image))
						add_image('classnet_'.$sidebar_image, $title, 240, 360);
					else
						add_image('sb_'.rand(1,5));
				?>
			</div>