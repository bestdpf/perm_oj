<?php

namespace Home\Controller;


/**
 * 控制功能模块
 */

class FuncPageController extends HomeController {
	
/* 用户中心首页 */
	public function index(){
		$this->check_sql();
		$this->read_lastre_from_sql();
		$this->display();
	
	}
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
		$xml=new \DOMDocument("1.0");
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
	
	public function check_sql(){
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
	}
	
	public function insert_result(){
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
	}
	
	public function read_lastre_from_sql(){
		$result = mysql_query("SELECT * FROM judge");
		while($row = mysql_fetch_array($result))
		{
			echo $row['runid'] . "\n";
			echo $row['MLE'] . "\n";
		}
		
	}
	
	public function upload_file(){
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
				$this->post_host($this->create_xml($runid, $store_path, $src_name));
				//$this->success('新增成功', U('Index/test'));
				$this->success('新增成功');
			}
		}
		else
		{
			//echo "Format must be .cpp/.c/.java";
			$this->error('Format must be .cpp/.c/.java');
		}
	}
}
