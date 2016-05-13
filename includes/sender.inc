<?php

require(rurl('class.phpmailer'));

$mail = new PHPMailer(true); // the true param means it will throw exceptions on errors, which we need to catch
$mail->IsSMTP(); // telling the class to use SMTP

$data = $_POST['data'];
$fields = array(
	'name' => 'Nombre',
	'email' => 'Email',
	'company' => 'Empresa',
	'country' => 'País',
	'province' => 'Provincia',
	'specialty' => 'Especialidad',
	'area' => 'Tema de interés'
);

$body = '<em>Datos</em><ul>';
foreach ($fields as $field_name=>$field_value)
{
	$value = $data[$field_name];
	$body .= '<li>'.$field_value.': '.$value.'</li>';

	if ($value)
		setrawcookie($field_name, rawurlencode($value), time()+60*60*24*365); 
}
$body .= '</ul>';
$body .= '<br /><p>'.$data['message'].'</p>';

try {
  $mail->SMTPDebug  = 0;                     // enables SMTP debug information (for testing)
  $mail->SMTPAuth   = true;                  // enable SMTP authentication
  $mail->SMTPSecure = 'ssl';                 // sets the prefix to the server
  $mail->Host       = 'smtp.gmail.com';      // sets GMAIL as the SMTP server
  $mail->Port       = 465;                   // set the SMTP port for the GMAIL server
  $mail->Username   = '';  // GMAIL username
  $mail->Password   = '';            // GMAIL password
  $mail->SetFrom($data['email'], $data['name']);
  $mail->AddReplyTo($data['email'], $data['name']);
  $mail->AddAddress();
  $mail->AddCC();
  $mail->Subject = 'Classnet - '.$data['subject'];
  $mail->AltBody = $body; // optional - MsgHTML will create an alternate automatically
  $mail->MsgHTML($body);
//  $mail->AddAttachment('images/phpmailer_mini.gif'); // attachment
  $mail->Send();
  $content = 'Gracias '.$data['name'].' por dejarnos sus datos.<br />Nos contactaremos con Ud. a la brevedad.';
} catch (phpmailerException $e) {
  $content = $e->errorMessage(); //Pretty error messages from PHPMailer
} catch (Exception $e) {
  $content = $e->getMessage(); //Boring error messages from anything else!
}

$content = "<div id='post-contact'>$content</div>";

?>
