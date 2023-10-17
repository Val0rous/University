/* Creating Objects */
String s = new String("vaffanculo");
Point2D p = new Point2D(10.5, 20.3);
Object o = new Object();

String s4;          //declaring variable
s4 = "stronzo";     //init variable
int i = 5;          //assignments are C-like

/* Assignments with primitive types */
double d = 145e-20;
boolean b = true;
int other = i;

/* Assignments with Classes */
Object o = new Object();
String s = "Vaffanculo";
Point2D p = new Point2D(10.4, 20.3);

Point2D q = p;      //Assignment with variable
Object on = null;   //Assignment with NULL

/* var: local variable type inference */
//var va messo al posto del tipo della variabile, per dedurlo automaticamente
var i = 5;

/* Creating a Class with Fields and Methods and this keyword*/
class A {
    int i;
    int j = 2;
    Object o;

    void aggiungi(int a) {
        this.i = this.i + a;
    }

    int restituisciValore() {
        return i;
    }
}

/* Creating an Object of a Class*/
A obj = new A();

/* Accessing fields */
int a = obj.i;
obj.i = 10;

/* Using Methods */
obj.aggiungi(10);
int a = restituisciValore();

//this: refers to current object

/* Main Declaration */
public static void main(String[] args) {...}

/* Importing a Library Class (all'inizio del sorgente) */
import java.util.Date;      //single class
import java.util.*;         //whole package
import java.lang.*;         //default

System.out.println("Number value is: " + this.i);           //prints a message and goes into new line
System.out.print("This makes it go into a new line: \n");   //prints a message and doesn't go into new line
System.out.format("Number value is: %d", this.i);           //printf-like function (C-like)

/* Compiling and Executing */
javac Hello.java    //compiles a class, generating bytecode Hello.class
javac *.java        //compiles all classes inside a folder
java Hello          //executes program (from main class)

import java.util.Date;
import java.util.Random;
import java.lang.System;    //Questa classe non va importata

/* Some methods of Library Classes */
Date.getTime();
Random.nextInt();
vjava;      //Java version
osname;     //OS Name
usrdir;     //User Directory