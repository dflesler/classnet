<p>Usted está por bajar: <?php echo $download?>.</p>
<p>Por favor, déjenos sus datos.</p>

<form action="." method="POST" id="contact">
	<fieldset>
		<ol>
			<li>
				<label for="name">Nombre y apellido<span>*</span></label>
				<input type="text" name="data[name]" id="name" />
			</li>
			<li>
				<label for="email">Email<span>*</span></label>
				<input type="text" name="data[email]" id="email" />
			</li>
			<li>
				<label for="company">Empresa</label>
				<input type="text" name="data[company]" id="company" />
			</li>
			<li>
				<label for="specialty">Especialidad</label>
				<input type="text" name="data[specialty]" id="specialty" />
			</li>
			<li>
				<label for="country">País</label>
				<select id="country" name="data[country]">
					<option value="" selected="selected">Otro</option>
					<option>Argentina</option>
					<option>Bolivia</option>
					<option>Brasil</option>
					<option>Chile</option>
					<option>Ecuador</option>
					<option>Paraguay</option>
					<option>Perú</option>
					<option>Uruguay</option>
					<option>Venezuela</option>
				</select>
			</li>
			<li id="provinceItem">
				<label for="province">Provincia</label>
				<select id="province" name="data[province]">
					<option value="" selected="selected">Elija una provincia</option>
					<option>Buenos Aires</option>
					<option>Catamarca</option>
					<option>Chaco</option>
					<option>Chubut</option>
					<option>Ciudad de Buenos Aires</option>
					<option>Córdoba</option>
					<option>Corrientes</option>
					<option>Entre Ríos</option>
					<option>Formosa</option>
					<option>Jujuy</option>
					<option>La Pampa</option>
					<option>La Rioja</option>
					<option>Misiones</option>
					<option>Neuquén</option>
					<option>Río Negro</option>
					<option>Salta</option>
					<option>San Juan</option>
					<option>San Luis</option>
					<option>Santa Cruz</option>
					<option>Santa Fe</option>
					<option>Santiago del Estero</option>
					<option>Tierra del Fuego</option>
					<option>Tucumán</option>
				</select>
			</li>
			<li>
				<label for="area">Tema de interés</label>
				<select id="area" name="data[area]">
					<option>SAP</option>
					<option>Tablero de comando</option>
					<option>Excel/Access</option>
					<option>Coaching Informático</option>
					<option selected="selected" value="">Otro</option>
				</select>
			</li>
		</ol>
		<input type="hidden" name="file" value="<?php echo $download?>" />
		<input id="submit" name="submit" type="submit" value="Enviar" />
	</fieldset>
</form>
<script type="text/javascript" src="../js/validation.js"></script>