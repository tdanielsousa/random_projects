<HTML>

<meta charset="utf-8" />

<HEAD>

    <link rel='stylesheet' type='text/css' href='style.css' />

</HEAD>

<BODY>

    <h1>Report Generator</h1>

    <br>

    <?php

    include './connection.php';



    echo ' <form method="GET" action="report.php">';
    echo "  Select MISSION :&nbsp ";
    echo '<select name="mission">';



    $sql = "SELECT id,name ";
    $sql .= "FROM missions ";

    $missionsPrint = mysql_query($sql);

    if ($missionsPrint === FALSE) {
        die(mysql_error()); // TODO:  better error handling
    }


    while ($search = mysql_fetch_array($missionsPrint)) {

        echo "<br/>";

        echo '<option value="' . $search['id'] . '">' . $search['id'] . "-" . $search['name'] . " </option>";
    }



    echo "</select>";

    echo "<br>";


    echo 'Select User: <input type="text" name="user">';


    echo '<br> <input type="submit"/>';
    echo "</form>";

    ?>
    <br>


    <h2> Select mission: <h2>


            <?php

            include './connection.php';



            echo ' <form method="GET" action="report.php">';
            echo "  MISSION:&nbsp ";
            echo '<select name="mission">';



            $sql = "SELECT id,name ";
            $sql .= "FROM missions ";

            $missionsPrint = mysql_query($sql);

            if ($missionsPrint === FALSE) {
                die(mysql_error()); // TODO:  better error handling
            }


            while ($search = mysql_fetch_array($missionsPrint)) {

                echo "<br/>";

                echo '<option value="' . $search['id'] . '">' . $search['id'] . "-" . $search['name'] . " </option>";
            }



            echo "</select>";

            echo "<br>";



            echo '<br> <input type="submit"/>';
            echo "</form>";

            ?>





</BODY>

</HTML>