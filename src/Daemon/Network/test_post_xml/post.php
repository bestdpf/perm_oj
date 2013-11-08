<?php
function postToHost($host, $port, $path, $postdata = array(), $filedata = array()) {
	$data = "";
	$boundary = "---------------------".substr(md5(rand(0,32000)),0,10);
	$fp = fsockopen($host, $port);
 
	fputs($fp, "POST $path HTTP/1.0\n");
	fputs($fp, "Host: $host\n");
	fputs($fp, "Content-type: multipart/form-data; boundary=".$boundary."\n");
 
	// Ab dieser Stelle sammeln wir erstmal alle Daten in einem String
	// Sammeln der POST Daten
	foreach($postdata as $key => $val){
	    $data .= "--$boundary\n";
	    $data .= "Content-Disposition: form-data; name=\"".$key."\"\n\n".$val."\n";
	}
 
	// Sammeln der FILE Daten
	if($filedata) {
		$data .= "--$boundary\n";
		$data .= "Content-Disposition: form-data; name=\"".$filedata['name']."\"; filename=\"".$filedata['filename']."\"\n";
		$data .= "Content-Type: ".$filedata['type']."\n";
		$data .= "Content-Transfer-Encoding: binary\n\n";
		$data .= $filedata['data']."\n\n";
		$data .='--';
		#$data .= "--$boundary--\n";
	}
 
	// Senden aller Informationen
	fputs($fp, "Content-length: ".(strlen($data))."\n\n");
	fputs($fp, $data);
 
	// Auslesen der Antwort
	while(!feof($fp)) {
		$res .= fread($fp, 8);
	}
	fclose($fp);
 
	return $res;
}
 
$postdata='' ;#= array('var1'=>'test', 'var2'=>'test');
$filedata = array(
	'name' => 'file',
	'filename' => 'post_xml.xml',
	'type' => 'application/octet-stream',
	'data' => file_get_contents('post_xml.xml')
);
 
echo '<pre>'.postToHost ("localhost", 8888, "/filepost", $postdata, $filedata).'</pre>';
