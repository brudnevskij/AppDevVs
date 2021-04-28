<?php
$name = $_POST["user"];
$min = $_POST["min"];
$max = $_POST["max"];
$ip_addr = $_SERVER["REMOTE_ADDR"];
$today = date("Y-m-d H:i:s");
$rec = $today . ' ' . $min. ' ' . $max . ' ' . $name . ' ' . $ip_addr . "\n";

$fname = "record.txt";
if(file_exists($fname))
	$fp = fopen($fname, "a");
else
	$fp = fopen($fname, "w");

fwrite($fp, $rec);
fclose($fp);
echo "Data is Recorded!";
?>
