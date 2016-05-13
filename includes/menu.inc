	
	<!-- MENU -->
	<div id="menu">
		<ul class="center">
<?php
				$first = true;
				foreach ($links as $folder=>$data)
				{
					$classes = array();
					
					foreach ($parts as $part)
						if ($folder === $part)
							$classes[] = 'selected';

					if ($first)
						$classes[]= 'first';

					$classes = implode(' ', $classes);
					
					if ($folder)
						$folder .= '/';

					if ($classes)
						$classes = " class='$classes'";
					
					echo "			<li$classes><a href='$root/$folder'>$data</a></li>\n";
					
					$first = false;
				}
?>
			<li class="tour">
				<a class="tour" href="<?php add_url($tour_next) ?>">
					<?php add_image('tour-guiado', 'Tour Guiado', 69, 65, 'png') ?>
				</a>
			</li>
		</ul>
	</div>
	<div id="menu_gradient">&nbsp;</div>