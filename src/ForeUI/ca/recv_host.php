<?php

$xml = simplexml_load_file($_FILES["sendfile"]["tmp_name"]);

$con=mysql_connect("localhost","root","0"); //your mysql user and password 
if(! $con)
	die("could not connect：" . mysql_error());
mysql_select_db("judge",$con);
$insert_table="INSERT INTO judge VALUES(
			  $xml->runid,
			  $xml->compilecode,
			  $xml->inputtype,
			  $xml->time,
			  $xml->mem,
			  $xml->RE,
			  $xml->TLE,
			  $xml->MLE,
			  $xml->judgercorrect,
			  $xml->judgererrtype)";
if(!mysql_query($insert_table,$con))
	echo "Could not insert into table judge" . mysql_error() ."\n";
/*
the follow down is read from mysql
$result = mysql_query("SELECT * FROM judge");
while($row = mysql_fetch_array($result))
{
		echo $row['runid'] . "\n";
		echo $row['MLE'] . "\n";
}
*/
mysql_close($con);
?>
