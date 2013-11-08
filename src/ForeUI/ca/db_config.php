<?php
$con=mysql_connect("localhost","root","0"); //your user and password
if(! $con)
	die("could not connect：" . mysql_error());
if(!mysql_query("CREATE DATABASE judge",$con))
	die("Could not create database judge" . mysql_error());
mysql_select_db("judge",$con);

$create_judge="CREATE TABLE judge
	(
	  runid INT NOT NULL AUTO_INCREMENT,
	  compilecode SMALLINT,
	  inputtype SMALLINT,
	  time INT,
	  mem INT,
	  RE SMALLINT,
	  TLE SMALLINT,
	  MLE SMALLINT,
	  judgercorrect SMALLINT,
	  judgererrtype SMALLINT,
	  PRIMARY KEY(runid)
	)";

if(!mysql_query($create_judge,$con))
	die("Could not create table judge" . mysql_error());
mysql_close($con);
?>