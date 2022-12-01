<!DOCTYPE html>
<html>
    <head>
        <title>
            Esercizio PHP
        </title>
    </head>
    <body>
        <?php
            // Check if variable A is valid and has values in DB
            function CheckVariableA($A, $conn) {
                if ($A >= 0 and $A != NULL) {
                    echo "Variable A is valid<br/>";
                } else {
                    die("Variable A is NOT valid!");
                }
                if (CheckSetNotEmpty(1, $conn)) {
                    echo "Variable A has values in DB<br/>";
                } else {
                    die("Variable A has NO values in DB!");
                }
            }
            
            // Check if variable B is valid and has values in DB
            function CheckVariableB($B, $conn) {
                if ($B >= 0 and $B != NULL) {
                    echo "Variable B is valid<br/>";
                } else {
                    die("Variable B is NOT valid!");
                }
                if (CheckSetNotEmpty(2, $conn)) {
                    echo "Variable B has values in DB<br/>";
                } else {
                    die("Variable B has NO values in DB!");
                }
            }
            
            // Check if variable O is valid
            function CheckVariableO($O) {
                if ($O != NULL and ($O === "i" or $O === "u")) {
                    echo "Variable O is valid</br>";
                } else {
                    die("Variable O is NOT valid!");
                }
            }
            
            // Connect to database
            function OpenCon() {
                $dbhost = "localhost";
                $dbuser = "root";
                $dbpass = "";
                $dbname = "giugno";
                $dbport = 3306;
                $conn = new mysqli($dbhost, $dbuser, $dbpass, $dbname, $dbport);

                if ($conn->connect_error) {
                    die("ERROR: connection to database has failed!</br>" . $conn->connect_error);
                } else {
                    echo "Successfully connected to database</br>";
                }
                
                return $conn;
            }
            
            // Disconnect from database
            function CloseCon($conn) {
                $conn->close();
            }
            
            // List values in either set A ($set = 1) or B ($set = 2)
            function ListValuesInSet($set_number, $conn) {
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
            function OperateOnSet($arrayA, $arrayB) {
                global $O;
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
            function GetNextIndex($conn) {
                $sql = "SELECT MAX(id) FROM insiemi";
                $stmt = $conn->prepare($sql);
                $stmt->execute();
                $stmt->bind_result($index);
                $stmt->fetch();

                return $index+1;
            }

            // Check if the given set is not empty
            // If set is not empty, returns true
            // If set is empty, returns false
            function CheckSetNotEmpty($set_number, $conn) {
                $sql = "SELECT COUNT(*) FROM insiemi WHERE insieme=?";
                $stmt = $conn->prepare($sql);
                $stmt->bind_param("i", $set_number);
                $stmt->execute();
                $stmt->bind_result($num_rows);
                $stmt->fetch();

                // only returns true if number of rows is valid
                if ($num_rows > 0) {
                    return true;
                }
                
                return false;
            }

            // Inserts values inside DB
            function InsertValuesInDB($values, $conn) {
                foreach ($values as $value) {
                    $index = GetNextIndex($conn);
                    $sql = "INSERT INTO insiemi (id, valore, insieme) VALUES (?, ?, 3)";
                    $stmt = $conn->prepare($sql);
                    $stmt->bind_param("ii", $index, $value);
                    $stmt->execute();
                }
                echo "Values have been correctly inserted into DB";
            }

            $conn = OpenCon();

            // variable data is passed via URL using GET
            $A = $_GET["A"];
            $B = $_GET["B"];
            $O = $_GET["O"];

            CheckVariableA($A, $conn);
            CheckVariableB($B, $conn);
            CheckVariableO($O);

            $arrayA = ListValuesInSet(1, $conn);
            $arrayB = ListValuesInSet(2, $conn);
            ////echo '<pre>', var_dump($arrayA), '</pre>';
            ////echo '<pre>', var_dump($arrayB), '</pre>';

            $newArray = OperateOnSet($arrayA, $arrayB);
            echo '<pre>', var_dump($newArray), '</pre>';

            InsertValuesInDB($newArray, $conn);

            ////echo "The next index in database is ".GetNextIndex($conn);
            ////echo CheckSetNotEmpty(1, $conn);
            
            CloseCon($conn);
        ?>
    </body>
</html>