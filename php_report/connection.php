<?php
// to test only
$mysql_host = "localhost";
$mysql_database = "rts";
$mysql_user = "tiago";
$mysql_password = "tiago";

$connection = mysql_connect($mysql_host, $mysql_user, $mysql_password);

mysql_query("SET NAMES 'utf8'");

if (!$connection) {
	die('Could not connect: ' . mysql_error());
}

mysql_select_db($mysql_database, $connection);
?>