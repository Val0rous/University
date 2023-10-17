package oop.lab02.arrays;

public class SeqRecognizer {

    public static boolean checkSeq1(final int[] array) {
        int i = 0;
        for (; i < array.length && array[i] == 1; i++);
        for (; i < array.length && (array[i] == 2 || array[i] == 3); i++);
        return i == array.length;
    }

    public static boolean checkSeq2(final int[] array) {
        if(array[0] != 1) {
            return false;
        }
        int i = 1;
        while(i < array.length && array[i] == 2) {
            i++;
        }
        if(i + 1 == array.length && array[i] == 3) {
            return true;
        }
        return false;
    }

    public static boolean checkSeq3(final int[] array) {
        if(array[0] != 1) {
            return false;
        }
        int i = 1;
        while(i < array.length && array[i] == 2) {
            i++;
        }
        if(array[i] != 3) {
            return false;
        }
        i++;
        while(i < array.length && array[i] == 4) {
            i++;
        }
        if(i == array.length) {
            return true;
        }
        if(i + 1 == array.length && array[i] == 5) {
            return true;
        }
        return false;
    }

    /*
     * Utility method for testing checkSeq1 method
     */
    public static boolean testCheckSeq1() {
        return checkSeq1(new int[] { 1, 1 })                        //true
                && checkSeq1(new int[] { 1, 1, 1, 2 })              //true
                && checkSeq1(new int[] { 1, 1, 1, 2, 3, 2, 3 })     //true
                && !checkSeq1(new int[] { 1, 1, 1, 2, 3, 1, 3 })    //not false
                && !checkSeq1(new int[] { 3, 2, 1, 1 });            //not false
    }   //true

    /*
     * Utility method for testing checkSeq2 method
     */
    public static boolean testCheckSeq2() {
        return checkSeq2(new int[] { 1, 3 })                        //true
                && checkSeq2(new int[] { 1, 2, 3 })                 //true
                && checkSeq2(new int[] { 1, 2, 2, 2, 2, 2, 2, 3 })  //true
                && !checkSeq2(new int[] { 1, 2, 2 })                //not false
                && !checkSeq2(new int[] { 2, 2, 2, 2, 3 });         //not false
    }   //true

    /*
     * Utility method for testing checkSeq3 method
     */
    public static boolean testCheckSeq3() {
        return checkSeq3(new int[] { 1, 3 })                            //true
                && checkSeq3(new int[] { 1, 3, 5 })                     //true
                && checkSeq3(new int[] { 1, 2, 2, 2, 2, 2, 2, 3 })      //true
                && checkSeq3(new int[] { 1, 2, 3, 4, 5 })               //true
                && checkSeq3(new int[] { 1, 2, 2, 3, 4, 4, 4, 5 })      //true
                && !checkSeq3(new int[] { 2, 2, 3, 4, 4, 4 })           //not false
                && !checkSeq3(new int[] { 1, 2, 2, 3, 4, 4, 4, 5, 6 }); //not false
    }   //true

    public static void main(final String[] args) {
        System.out.println("testCheckSeq1: " + testCheckSeq1());
        System.out.println("testCheckSeq2: " + testCheckSeq2());
        System.out.println("testCheckSeq3: " + testCheckSeq3());
    }
}
