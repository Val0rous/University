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
                // Connection to database
                private $conn;
                // Variables
                private $A;
                private $B;
                private $O;

                public function __construct($A, $B, $O)
                {
                    $this->A = $A;
                    $this->B = $B;
                    $this->O = $O;
                }

                // Check if the given set is not empty
                private function CheckSetNotEmpty($set_number)
                {
                    $sql = "SELECT COUNT(*) FROM insiemi WHERE insieme=?";
                    $stmt = $this->conn->prepare($sql);
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
                public function CheckVariableA()
                {
                    if ($this->A >= 0 and $this->A != null) {
                        echo "<br/>Variable A is valid";
                    } else {
                        echo "</br>Variable A is NOT valid!";
                        die();
                    }
                    if (CheckSetNotEmpty(1)) {
                        echo " and has values in DB";
                    } else {
                        echo " but has NO values in DB!";
                        die();
                    }
                }
                
                // Check if variable B is valid and has values in DB
                public function CheckVariableB()
                {
                    if ($this->B >= 0 and $this->B != null) {
                        echo "<br/>Variable B is valid";
                    } else {
                        echo "</br>Variable B is NOT valid!";
                        die();
                    }
                    if (CheckSetNotEmpty(2)) {
                        echo " and has values in DB";
                    } else {
                        echo " but has NO values in DB!";
                        die();
                    }
                }
                
                // Check if variable O is valid
                public function CheckVariableO()
                {
                    if ($this->O != null and ($this->O === "i" or $this->O === "u")) {
                        echo "</br>Variable O is valid</br>";
                    } else {
                        echo "</br>Variable O is NOT valid!";
                        die();
                    }
                }
                
                // Connect to database
                public function OpenCon()
                {
                    echo "Connecting to database...</br>";
                    $dbhost = "localhost";
                    $dbuser = "root";
                    $dbpass = "";
                    $dbname = "giugno";
                    $dbport = 3306;
                    $this->conn = new mysqli($dbhost, $dbuser, $dbpass, $dbname, $dbport);
                    // Check if connection was successful
                    if ($this->conn->connect_error) {
                        die("ERROR: connection to database has failed!</br>" . $this->conn->connect_error);
                    } else {
                        echo "Successfully connected to database!</br>";
                    }
                }
                
                // Disconnect from database
                public function CloseCon()
                {
                    echo "<br/>Disconnecting from database...";
                    $this->conn->close();
                    echo "<br/>Successfully disconnected from database!";
                }
                
                // List values in either set A ($set = 1) or B ($set = 2)
                public function ListValuesInSet($set_number)
                {
                    $sql = "SELECT valore FROM insiemi WHERE insieme=?";
                    $stmt = $this->conn->prepare($sql);
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
                function OperateOnSet($arrayA, $arrayB)
                {
                    $newSet = [];
                    switch ($this->O) {
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
                private function GetNextIndex()
                {
                    $sql = "SELECT MAX(id) FROM insiemi";
                    $stmt = $this->conn->prepare($sql);
                    $stmt->execute();
                    $stmt->bind_result($index);
                    $stmt->fetch();
                    return $index+1;
                }

                // Inserts values inside DB
                public function InsertValuesInDB($values)
                {
                    foreach ($values as $value) {
                        $index = GetNextIndex($this->conn);
                        $sql = "INSERT INTO insiemi (id, valore, insieme) VALUES (?, ?, 3)";
                        $stmt = $this->conn->prepare($sql);
                        $stmt->bind_param("ii", $index, $value);
                        $stmt->execute();
                    }
                    echo "<br/>Values in final array have been correctly inserted into DB<br/>";
                }
            }

            // Variable data is passed via URL using GET
            $dbhandler = new DatabaseHandler($_GET["A"], $_GET["B"], $_GET["O"]);
            // Connecting to database
            $dbhandler->OpenCon();
            // Checking if variables are valid
            $dbhandler->CheckVariableA();
            $dbhandler->CheckVariableB();
            $dbhandler->CheckVariableO();
            // Filling arrays with values inside database
            $arrayA = $dbhandler->ListValuesInSet(1);
            $arrayB = $dbhandler->ListValuesInSet(2);
            echo '<br/>This is array A:<pre>', var_dump($arrayA), '</pre>';
            echo '<br/>This is array B:<pre>', var_dump($arrayB), '</pre>';
            // Creating the new array according to rules
            $newArray = $dbhandler->OperateOnSet($arrayA, $arrayB);
            echo '<br/>This is the final array:<pre>', var_dump($newArray), '</pre>';
            // Inserting new array values inside database
            $dbhandler->InsertValuesInDB($newArray);
            // Disconnecting from database
            $dbhandler->CloseCon();
        ?>
    </body>
</html>
