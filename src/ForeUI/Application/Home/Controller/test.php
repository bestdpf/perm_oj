<?php
	namespace Home\Controller;
	include"FuncpageController.class.php";
	$a=new namespace\FuncPageController();
	$ret=$a->read_lastre_from_sql();
	while($row = mysql_fetch_array($ret))
        {
            echo $row['runid'] . "\n";
            echo $row['MLE'] . "\n";
        }

?>
