<?php

function post_host($a){
	$ch = curl_init();
	curl_setopt($ch, CURLOPT_URL, "http://127.0.0.1:9000/filepost");
	curl_setopt($ch, CURLOPT_HEADER, false);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
	curl_setopt($ch, CURLOPT_POST, true);
	curl_setopt($ch, CURLOPT_POSTFIELDS, array(
	'file'=>'@'.$a));
	$result = curl_exec($ch);
	echo $result;
	curl_close($ch);
}

function create_xml($runid,$store_path,$src_name)
{
	$xml=new DOMDocument("1.0");
	$xml->formatOutput=true;

	$_judge=$xml->createElement("judge");
	$_runid=$xml->createElement("runid",$runid);
	$_store_path=$xml->createElement("storepath",$store_path);
	$_src_name=$xml->createElement("srcname",$src_name);

	$_judge->appendChild($_runid);
	$_judge->appendChild($_store_path);
	$_judge->appendChild($_src_name);
	$xml->appendChild($_judge);

	return $xml->saveXML();
}

$file_name=$_FILES["file"]["name"]; 
$file_type=strstr($file_name,".");
if($file_type==".cpp"||$file_type==".c"||$file_type==".java")
{ 
  	if ($_FILES["file"]["error"] > 0)
  	{
  		echo "Return Code: " . $_FILES["file"]["error"] . "<br />";
  	}
  	else
  	{
    	$runid=1000;
  		$store_path="/var/www/Test/application/Projects/temp/"; //your store path
  		$src_name=$runid . $_FILES["file"]["name"];
  		move_uploaded_file($_FILES["file"]["tmp_name"],$store_path . $src_name);
  		//echo create_xml($runid, $store_path, $src_name);
  		post_host(create_xml($runid, $store_path, $src_name));
  	}
}
else
{
  	echo "Format must be .cpp/.c/.java";
}

?>