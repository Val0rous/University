<!DOCTYPE html>
<html>
    <head>
        <title>
            Esercizio PHP
        </title>
    </head>
    <body>
        <?php
            class DatabaseHandler
            {
                // Check if the given set is not empty
                function CheckSetNotEmpty($set_number, $conn)
                {
                    $sql = "SELECT COUNT(*) FROM insiemi WHERE insieme=?";
                    $stmt = $conn->prepare($sql);
                    $stmt->bind_param("i", $set_number);
                    $stmt->execute();
                    $stmt->bind_result($num_rows);
                    $stmt->fetch();
                    // Only return true if the number of rows is valid
                    if ($num_rows > 0) {
                        // Set is not empty
                        return true;
                    }
                    // Set is empty
                    return false;
                }

                // Check if variable A is valid and has values in DB
                function CheckVariableA($A, $conn)
                {
                    if ($A >= 0 and $A != null) {
                        echo "<br/>Variable A is valid";
                    } else {
                        echo "</br>Variable A is NOT valid!";
                        die();
                    }
                    if (CheckSetNotEmpty(1, $conn)) {
                        echo " and has values in DB";
                    } else {
                        echo " but has NO values in DB!";
                        die();
                    }
                }
                
                // Check if variable B is valid and has values in DB
                function CheckVariableB($B, $conn)
                {
                    if ($B >= 0 and $B != null) {
                        echo "<br/>Variable B is valid";
                    } else {
                        echo "</br>Variable B is NOT valid!";
                        die();
                    }
                    if (CheckSetNotEmpty(2, $conn)) {
                        echo " and has values in DB";
                    } else {
                        echo " but has NO values in DB!";
                        die();
                    }
                }
                
                // Check if variable O is valid
                function CheckVariableO($O)
                {
                    if ($O != null and ($O === "i" or $O === "u")) {
                        echo "</br>Variable O is valid</br>";
                    } else {
                        echo "</br>Variable O is NOT valid!";
                        die();
                    }
                }
                
                // Connect to database
                function OpenCon()
                {
                    echo "Connecting to database...</br>";
                    $dbhost = "localhost";
                    $dbuser = "root";
                    $dbpass = "";
                    $dbname = "giugno";
                    $dbport = 3306;
                    $conn = new mysqli($dbhost, $dbuser, $dbpass, $dbname, $dbport);
                    // Check if connection was successful
                    if ($conn->connect_error) {
                        die("ERROR: connection to database has failed!</br>" . $conn->connect_error);
                    } else {
                        echo "Successfully connected to database!</br>";
                    }
                    return $conn;
                }
                
                // Disconnect from database
                function CloseCon($conn)
                {
                    echo "<br/>Disconnecting from database...";
                    $conn->close();
                    echo "<br/>Successfully disconnected from database!";
                }
                
                // List values in either set A ($set = 1) or B ($set = 2)
                function ListValuesInSet($set_number, $conn)
                {
                    $sql = "SELECT valore FROM insiemi WHERE insieme=?";
                    $stmt = $conn->prepare($sql);
                    $stmt->bind_param("i", $set_number);
                    $stmt->execute();
                    $stmt->bind_result($row);
                    // creating array
                    $array = [];
                    while($stmt->fetch()) {
                        static $index = 0;
                        $array[$index] = $row;
                        $index++;
                    }
                    return $array;
                }

                // Operate Union or Intersection on the two arrays based on the value of $O
                function OperateOnSet($arrayA, $arrayB, $O)
                {
                    $newSet = [];
                    switch ($O) {
                        case "u":
                            // Set Union
                            $newSet = array_unique(array_merge($arrayA, $arrayB));
                            break;
                        case "i":
                            // Set Intersection
                            $newSet = array_intersect($arrayA, $arrayB);
                            break;
                        default:
                            die("No operation is possible!");
                    }
                    return $newSet;
                }

                // Get next usable index in the database, useful to insert values in DB
                function GetNextIndex($conn)
                {
                    $sql = "SELECT MAX(id) FROM insiemi";
                    $stmt = $conn->prepare($sql);
                    $stmt->execute();
                    $stmt->bind_result($index);
                    $stmt->fetch();
                    return $index+1;
                }

                // Inserts values inside DB
                function InsertValuesInDB($values, $conn)
                {
                    foreach ($values as $value) {
                        $index = GetNextIndex($conn);
                        $sql = "INSERT INTO insiemi (id, valore, insieme) VALUES (?, ?, 3)";
                        $stmt = $conn->prepare($sql);
                        $stmt->bind_param("ii", $index, $value);
                        $stmt->execute();
                    }
                    echo "<br/>Values in final array have been correctly inserted into DB<br/>";
                }
            }

            // Connecting to database
            $conn = OpenCon();
            // Variable data is passed via URL using GET
            $A = $_GET["A"];
            $B = $_GET["B"];
            $O = $_GET["O"];
            // Checking if variables are valid
            CheckVariableA($A, $conn);
            CheckVariableB($B, $conn);
            CheckVariableO($O);
            // Filling arrays with values inside database
            $arrayA = ListValuesInSet(1, $conn);
            $arrayB = ListValuesInSet(2, $conn);
            echo '<br/>This is array A:<pre>', var_dump($arrayA), '</pre>';
            echo '<br/>This is array B:<pre>', var_dump($arrayB), '</pre>';
            // Creating the new array according to rules
            $newArray = OperateOnSet($arrayA, $arrayB, $O);
            echo '<br/>This is the final array:<pre>', var_dump($newArray), '</pre>';
            // Inserting new array values inside database
            InsertValuesInDB($newArray, $conn);
            // Disconnecting from database
            CloseCon($conn);
        ?>
    </body>
</html>
