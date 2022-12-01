<!DOCTYPE html>
<html>
    <head>
        <title>
            Esercizio PHP
        </title>
    </head>
    <body>
        <?php
            //declaring variables
            $A = 4;
            $B;
            $O = "i"; //it's not a zero, mind that

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
                if ($conn) {
                    echo "Successfully connected to database</br>";
                } else {
                    echo "ERROR: connection to database has failed!</br>";
                }

                return $conn;
            }
            
            // Disconnect from database
            function CloseCon() {
                $conn->close();
            }

            OpenCon();
            CheckVariableA();
            CheckVariableB();
            CheckVariableO();

            CloseCon();


        ?>
    </body>
</html>