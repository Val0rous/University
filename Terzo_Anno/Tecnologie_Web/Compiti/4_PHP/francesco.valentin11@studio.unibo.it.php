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
                if ($conn) {
                    echo "Successfully connected to database</br>";
                } else {
                    echo "ERROR: connection to database has failed!</br>";
                }
                
                return $conn;
            }
            
            // Disconnect from database
            function CloseCon($conn) {
                $conn->close();
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

            //$arrayA;
            $fillA = $conn->prepare("SELECT valore FROM insiemi WHERE insieme=1");
            $fillA->execute();
            //$arrayA = mysqli_fetch_array($resultA, MYSQL_NUM);
            $resultA = $fillA->get_result();

            var_dump($resultA->fetch_num());

            foreach ($resultA as $item) {
                static $index = 0;
                $arrayA[$index] = $resultA->fetch_num();
                $index++;
            }

            var_dump($arrayA);
            
            //$arrayB;
            //$fillB = $conn->prepare("SELECT valore FROM tabelle WHERE insieme=2");
            //$fillA->bind_param("i", $arrayB);
            //mysql_free_result($resultA);
            ////var_dump($arrayA);
            


            echo "<br/>Second round!<br/><br/>";

            //declaring variables #2 (test)
            $A = 1;
            $B = 2;
            $O = "i";

            CheckVariableA();
            CheckVariableB();
            CheckVariableO();

            CloseCon($conn);


        ?>
    </body>
</html>