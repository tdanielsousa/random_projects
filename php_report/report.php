<HTML>

<meta charset="utf-8" />

<HEAD>

	<link rel='stylesheet' type='text/css' href='style.css' />



</HEAD>

<BODY>

	<center><b>
			<h2>Mission Report</h2>
		</b></center><br />




	<?php

	include './connection.php';




	if (isset($_REQUEST["mission"])) {


		$missionId = $_REQUEST["mission"];   // ask for mission number (from form)
	
		$missionReport = mysql_query("SELECT id,name,description,starttime,endtime FROM missions WHERE id=$missionId"); //query to show mission data
	
		if ($missionReport === FALSE) {
			die(mysql_error()); // TODO:  better error handling
		}

		$missionData = mysql_fetch_array($missionReport);  // Data about mission on the header of Report
	
		echo "<b>Mission:</b> " . $missionData['id'] . "<br/>";     // Mission number
		echo "<b>Mission name:</b> " . $missionData['name'] . "<br/>";    // Mission name
		echo "<b>Mission description:</b> " . $missionData['description'] . "<br/>";   // Mission description
	

		$epoch = mb_substr($missionData['starttime'], 0, 10);   // no milliseconds on the epoch
	
		$dateTime = new DateTime("@$epoch");   //  unix (epoc) timestamp to php datetime
	
		echo "<b>Start:</b> " . $dateTime->format('d-m-Y G:i:s') . "<br/>";   //format the date
	


		$epoch = mb_substr($missionData['endtime'], 0, 10);   //no milliseconds on the epoch
		$dateTime = new DateTime("@$epoch");   //  unix (epoc) timestamp to php datetime
	
		echo "<b>End:</b> " . $dateTime->format('d-m-Y G:i:s') . "<br/>"; //format the date
	



		$missionReport = mysql_query("SELECT COUNT(id) as events FROM events where mission=$missionId");
		if ($missionReport === FALSE) {
			die(mysql_error()); // TODO:  better error handling
		}

		$missionData = mysql_fetch_array($missionReport);
		echo "<b>Events:</b> " . $missionData['events'] . "<br/>";  // show nr of users
	



		$missionReport = mysql_query("SELECT COUNT(id) as users FROM mission_user where mission=$missionId");
		if ($missionReport === FALSE) {
			die(mysql_error()); // TODO:  better error handling
		}

		$missionData = mysql_fetch_array($missionReport);
		echo "<b>Users in mission:</b> " . $missionData['users'] . "<br/>";  // show nr of users
	




		// <--------------------------------------------------------------------------------------------------->
		//  <----------------------------       USERS       ------------------------------->
		// <--------------------------------------------------------------------------------------------------->
	

		echo '<br/>';

		echo '<br/><b>Users:</b><br/> <hr noshade size="5px">';


		if (isset($_REQUEST["user"])) {

			$userId = $_REQUEST["user"];

			$sql = "SELECT users.id, username, realname, photo, mission ";
			$sql .= "FROM users LEFT JOIN mission_user ";
			$sql .= "ON mission_user.user  =  users.id ";
			$sql .= "where mission=$missionId AND user=$userId ORDER BY users.id ASC";

		} else {

			$sql = "SELECT users.id, username, realname, photo, mission ";
			$sql .= "FROM users LEFT JOIN mission_user ";
			$sql .= "ON mission_user.user  =  users.id ";
			$sql .= "where mission=$missionId  ORDER BY users.id ASC";

		}




		$usersPrint = mysql_query($sql);


		if ($usersPrint === FALSE) {
			die(mysql_error()); // TODO:  better error handling
		}


		while ($missionUsers = mysql_fetch_array($usersPrint))      // print user data (closed on the end)
		{
			echo '<br/><center><table border="1" style="width:40%">';
			echo "<tr>";

			echo '<td width="70%"><b>Code:</b> ' . $missionUsers['id'] . " <br/> " .
				"<b>Username:</b> " . $missionUsers['username'] . " <br/> " .
				"<b>Full Name:</b> " . $missionUsers['realname'] . "</td>";
			echo '<td><IMG SRC="./user_photos/' . $missionUsers['photo'] . '" ALT="photo" WIDTH=60 HEIGHT=80></td>';

			echo "</tr> <br/>";
			echo "</table></center><br/>";

			echo "<hr>";





			// <--------------------------------------------------------------------------------------------------->
			//  <----------------------------        EVENTS         ------------------------------->
			// <--------------------------------------------------------------------------------------------------->
	


			echo "<br/><b>Reported events:</b><br/>";


			$sql = "SELECT events.id, time, latitude, longitude,user, event_type.description AS type, event_status_list.description AS description ";
			$sql .= "FROM events INNER JOIN event_status_list ";
			$sql .= "ON events.status = event_status_list.id ";
			$sql .= "LEFT JOIN event_type ";
			$sql .= "ON events.type = event_type.id ";
			$sql .= "where user = " . $missionUsers['id'] . " AND mission=$missionId ORDER BY id ASC";

			$eventsPrint = mysql_query($sql);


			if ($eventsPrint === FALSE) {
				die(mysql_error()); // TODO:  better error handling
			}

			$numResults = mysql_num_rows($eventsPrint);

			if ($numResults == 0)     // check if there are events
				echo "No Events <br/>";
			else {

				echo '<br/><center><table border="1" style="width:70%">';
				echo "<tr>
					<th>Id</th>
					<th>Time</th>
					<th>Type</th>
					<th>Latitude</th>
					<th>Longitude</th>
					<th>Current</th>
					</tr>";


				while ($userEvents = mysql_fetch_array($eventsPrint))    // print the events from a user
				{


					echo "<br/><tr>";

					echo "<td>" . $userEvents['id'] . "<br/></td>" .
						"<td>" . $userEvents['time'] . "<br/> </td>" .
						"<td>" . $userEvents['type'] . "<br/></td> " .
						"<td>" . $userEvents['latitude'] . "<br/></td> " .
						"<td>" . $userEvents['longitude'] . "<br/></td> " .
						"<td>" . $userEvents['description'] . "</td>";
					echo "</tr>";



				}


				echo "</table></center><br/>";
			}

			echo '<hr>';




			// <--------------------------------------------------------------------------------------------------->
			//  <----------------------------         ORDERS          ------------------------------->
			// <--------------------------------------------------------------------------------------------------->
	




			echo "<br/><b>Orders Received:</b><br/>";



			$sql = "SELECT orders.id, time, user, type, latitude, longitude, order_status_list.description AS description, order_type.description AS type ";
			$sql .= "FROM orders LEFT JOIN order_status_list ";
			$sql .= "ON orders.status =order_status_list.id ";
			$sql .= "LEFT JOIN order_type ";
			$sql .= "ON orders.type = order_type.id ";
			$sql .= "where user = " . $missionUsers['id'] . " AND mission=$missionId ORDER BY id ASC";


			$ordersPrint = mysql_query($sql);


			if ($ordersPrint === FALSE) {
				die(mysql_error()); // TODO:  better error handling
			}

			$numResults = mysql_num_rows($ordersPrint);


			if ($numResults == 0)   // check if there are orders
				echo "No Orders <br/>";
			else {

				echo '<br/><center><table border="1" style="width:70%">';

				echo "<tr>
					<th>Id</th>
					<th>Time</th>
					<th>Type</th>
					<th>Latitude</th>
					<th>Longitude</th>
					<th>Description</th>
					</tr>";


				while ($userOrders = mysql_fetch_array($ordersPrint))      // print the orders from a user
				{
					echo "<br/><tr>";

					echo "<td>" . $userOrders['id'] . "<br/></td>" .
						"<td>" . $userOrders['time'] . "<br/></td> " .
						"<td>" . $userOrders['type'] . "<br/></td> " .
						"<td>" . $userOrders['latitude'] . "<br/></td> " .
						"<td>" . $userOrders['longitude'] . "<br/></td> " .
						"<td>" . $userOrders['description'] . "</td>";


					echo "</tr>";
				}
				echo "</table></center><br/>";

			}

			echo "<hr>";





			// <--------------------------------------------------------------------------------------------------->
			//  <----------------------------       MESSAGES        ------------------------------->
			// <--------------------------------------------------------------------------------------------------->
	


			echo "<br/><b>Mensagens:</b><br/>";



			$sql = "SELECT messages.id, time,user, text, message_status_list.description as status, direction.description as direction ";
			$sql .= "FROM messages LEFT JOIN message_status_list ";
			$sql .= "ON messages.status = message_status_list.id ";
			$sql .= "LEFT JOIN direction ";
			$sql .= "ON messages.type = direction.id ";
			$sql .= "WHERE mission =$missionId ";
			$sql .= " AND user = " . $missionUsers['id'] . " ORDER BY messages.time ASC";

			$messagesPrint = mysql_query($sql);


			if ($messagesPrint === FALSE) {
				die(mysql_error()); // TODO:  better error handling
			}


			$numResults = mysql_num_rows($messagesPrint);


			if ($numResults == 0)   // check if there are messages
				echo "No Messages <br/>";
			else {


				echo '<br/><center><table style="width:70%" border="1">';

				echo "<tr>
				<th>Id</th>
				<th>Time</th>
				<th>Direction</th>
				<th>Text</th>
				<th>Status</th>
				</tr>";




				while ($userMessages = mysql_fetch_array($messagesPrint))      // print the user's messages
				{
					echo "<tr>";

					echo "<td>" . $userMessages['id'] . "<br/></td> " .
						"<td>" . $userMessages['time'] . "<br/></td> " .
						"<td>" . $userMessages['direction'] . "<br/></td> " .
						"<td>" . $userMessages['text'] . "<br/> </td>" .
						"<td>" . $userMessages['status'] . "</td> ";


					echo "</tr>";
				}
				echo "</table></center><br/>";



			}   // close else
	


			echo '<hr noshade size="5px">';

		}       // CLOSE WHILE, OF USER.
	



		// <<<-----------------------------------  END OF PRINTS FOR THE REPORT  -------------------------------->>>
	


		echo "<hr>";


		// The following code shows at what time the report was generated on.
	
		echo '<div align="right">';
		date_default_timezone_set("Europe/Lisbon");
		echo "<b>Report Generated On:</b> " . date("G:i:s");
		echo " - " . date("d/m/Y") . "<br>";
		echo '</div>';




	}   // END OF IF, THAT CHECKS IF THERE IS A MISSION.
	else {
		echo "Mission not available!";
	}





	echo "</body></html>";

	mysql_close($connection);


	?>