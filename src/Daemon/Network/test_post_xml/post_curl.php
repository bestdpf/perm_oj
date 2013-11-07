<?php
function test($a){
$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, "http://127.0.0.1:8888/filepost");
curl_setopt($ch, CURLOPT_HEADER, false);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_POST, true);
curl_setopt($ch, CURLOPT_POSTFIELDS, array(
        'file'=>'@'.$a
));
$result = curl_exec($ch);
echo $result;
curl_close($ch);
}
test('post_xml.xml')
?>
