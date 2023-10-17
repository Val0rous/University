jshell      //Java CLI Shell

/* Creating an Array by List and Size */
int[] ar1 = new int[]{1,2,3,4,5};
int[] ar2 = new int[200];           //new int[]{0,...,0}
var ar3 = new int[]{1,2,3,4,5};     //var variant
int[] ar4 = {1,2,3,4,5};            //new-less variant

/* Creating Multi-Dimensional Arrays */
int[][] m = new int[][]{new int[]{...}, ...};
int[][] m2 = new int[200][200];

/* Accessing an Array */
ar1.length;      //length
ar2[pos];        //reading (pos+1)th element
ar2[pos] = 10;   //assigning (pos+1)th element
m[row][column] = 10;   //assigning by row and column

/* Creating an Array of Objects by List and Size */
Object[] ar = new Object[]{new Object(), new Object()};
Object[] ar2 = new Object[200];
// GLI OGGETTI NON SONO INIZIALIZZATI!!

for(int i=0; i<10; i++){...}

import java.util.Arrays;    //yet another Library
Math.random();              //genertates a random number in [0,1]
Math.pi                     //PI number
Arrays.toString("String");

/* For-Each */
for(int v: array){...}
for(var v: array){...}

Integer.parseInt();

java.io.Console.readLine;
java.lang.Integer.parseInt;
java.util.Random.nextInt;

import Java.io.Console;
