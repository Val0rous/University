<!DOCTYPE html>
<html>
    <head>
        <title>
            Esercizio PHP
        </title>
    </head>
    <body>
        <?php
            // Check if variable A is valid
            function CheckVariableA() {
                global $A;
                if ($A >= 0 and $A != NULL) {
                    echo "Variable A is valid<br/>";
                } else {
                    echo "Variable A is NOT valid!<br/>";
                }
            }
            
            // Check if variable B is valid
            function CheckVariableB() {
                global $B;
                if ($B >= 0 and $B != NULL) {
                    echo "Variable B is valid<br/>";
                } else {
                    echo "Variable B is NOT valid!<br/>";
                }
            }
            
            // Check if variable O is valid
            function CheckVariableO() {
                global $O;
                if ($O != NULL and ($O === "i" or $O === "u")) {
                    echo "Variable O is valid</br>";
                } else {
                    echo "Variable O is NOT valid!<br/>";
                }
            }
            
            // Connect to database
            function OpenCon() {
                $dbhost = "localhost";
                $dbuser = "root";
                $dbpass = "";
                $dbname = "giugno";
                $conn = new mysqli($dbhost, $dbuser, $dbpass, $dbname);
                //// or die("Connect failed: %s\n". $conn -> error)
                ////var_dump($conn);
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
                //echo '<pre>', var_dump($array), '</pre>';
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

            // Get next usable index in the database
            function DBGetNextIndex($conn) {
                $sql = "SELECT MAX(id) FROM insiemi";
                $stmt = $conn->prepare($sql);
                $stmt->execute();
                $stmt->bind_result($index);
                $stmt->fetch();

                return $index+1;
            }


            //THEY'RE GONNA BE PASSED VIA A GET FUNCTION LATER ON: YOU'LL LIKELY HAVE TO SEND IT HERE TO LOCALHOST
            //declaring variables #1 (test)
            $A = 1;
            $B = 2;
            $O = "u";

            $conn = OpenCon();

            CheckVariableA();
            CheckVariableB();
            CheckVariableO();

            $arrayA = ListValuesInSet(1, $conn);
            //echo '<pre>', var_dump($arrayA), '</pre>';
            $arrayB = ListValuesInSet(2, $conn);
            //echo '<pre>', var_dump($arrayB), '</pre>';

            $newArray = OperateOnSet($arrayA, $arrayB);
            echo '<pre>', var_dump($newArray), '</pre>';

            ////echo "The next index in database is ".DBGetNextIndex($conn);
            
            CloseCon($conn);




            echo "<br/>SECOND ROUND!<br/><br/>";




            //declaring variables #2 (test)
            $A = 1;
            $B = 2;
            $O = "i";

            $conn = OpenCon();

            CheckVariableA();
            CheckVariableB();
            CheckVariableO();

            $arrayA = ListValuesInSet(1, $conn);
            //echo '<pre>', var_dump($arrayA), '</pre>';
            $arrayB = ListValuesInSet(2, $conn);
            //echo '<pre>', var_dump($arrayB), '</pre>';

            $newArray = OperateOnSet($arrayA, $arrayB);
            echo '<pre>', var_dump($newArray), '</pre>';

            CloseCon($conn);


        ?>
    </body>
</html>