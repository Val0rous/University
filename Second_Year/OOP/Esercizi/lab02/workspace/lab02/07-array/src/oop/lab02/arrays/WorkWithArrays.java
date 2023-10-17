package oop.lab02.arrays;

import java.util.Arrays;

public class WorkWithArrays {

    /*
    * ADVICE:
    * If your method implements an algorithm, it doesn't necessarly need to contain
    * the whole code! You can decomopose your problem into simpler (non-trivial) ones,
    * writing a *private* utility method for each sub problem.
    * Moreover, if your utility method solves a common sub-problem, it may be
    * re-used by other methods within the same class.
    */


    public static int countOccurrencies(final int[] array, final int elem) {
        int nOccur = 0;
        for (final int currElem : array) {
            if (currElem == elem) {
                nOccur++;
            }
        }
        return nOccur;
    }

    public static int[] evenElements(final int[] array) {
        int length;
        if ((array.length % 2) == 0) {
            //even length
            length = array.length / 2;
        } else {
            //odd length
            length = (array.length + 1) / 2;
        }
        int[] temp = new int[length];
        for(int i = 0; i < length; i++) {
            temp[i] = array[i*2];
        }
        return temp;
    }

    public static int[] oddElements(final int[] array) {
        int length;
        if ((array.length % 2) == 0) {
            //even length
            length = array.length / 2;
        } else {
            //odd length
            length = (array.length - 1) / 2;
        }
        int[] temp = new int[length];
        for(int i = 0; i < length; i++) {
                temp[i] = array[i*2 + 1];
        }
        return temp;
    }

    //NON TORNA
    public static int mostRecurringElement(final int[] array) {
        ////int[] temp = new int[array.length];
        
        Arrays.sort(array);

        int max_count = 1;
        int res = array[0];
        int curr_count = 1;
         
        for (int i = 1; i < array.length; i++) {
            if (array[i] == array[i - 1]) {
                curr_count++;
            } else {
                if (curr_count > max_count) {
                    max_count = curr_count;
                    res = array[i - 1];
                }
                curr_count = 1;
            }
        }
     
        // If last element is most frequent
        if (curr_count > max_count) {
            max_count = curr_count;
            res = array[array.length - 1];
        }
     
        return res;
    }

    /*
     * Testing methods
     */

    public static boolean testCountOccurrencies() {
        return countOccurrencies(new int[] { 1, 2, 3, 4 }, 1) == 1              //true
                && countOccurrencies(new int[] { 0, 2, 3, 4 }, 1) == 0          //true
                && countOccurrencies(new int[] { 7, 4, 1, 9, 3, 1, 5 }, 2) == 0 //true
                && countOccurrencies(new int[] { 1, 2, 1, 3, 4, 1 }, 1) == 3    //true
                && countOccurrencies(new int[] { 1, 2, 3, 4}, 5) == 0;
    }   //true

    public static boolean testEvenElements() {
        return Arrays.equals(evenElements(new int[] { 1, 2, 3, 4 }), new int[] { 1, 3 })
                && Arrays.equals(
                        evenElements(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 }),
                        new int[] { 1, 3, 5, 7, 9 })
                && Arrays.equals(
                        evenElements(new int[] { 4, 6, 7, 9, 1, 5, 23, 11, 73 }),
                        new int[] { 4, 7, 1, 23, 73 })
                && Arrays.equals(
                        evenElements(new int[] { 7, 5, 1, 24, 12, 46, 23, 11, 54, 81 }),
                        new int[] { 7, 1, 12, 23, 54 });
    }   //true

    public static boolean testOddElements() {
        return Arrays.equals(oddElements(new int[] { 1, 2, 3, 4 }),
                new int[] { 2, 4 })
                && Arrays.equals(
                        oddElements(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 }),
                        new int[] { 2, 4, 6, 8 })
                && Arrays.equals(
                        oddElements(new int[] { 4, 6, 7, 9, 1, 5, 23, 11, 73 }),
                        new int[] { 6, 9, 5, 11 })
                && Arrays.equals(
                        oddElements(new int[] { 7, 5, 1, 24, 12, 46, 23, 11, 54, 81 }),
                        new int[] { 5, 24, 46, 11, 81 });
    }   //true

    public static boolean testMostRecurringElement() {
        return mostRecurringElement(new int[] { 1, 2, 1, 3, 4 }) == 1               //{1, 1, 2, 3, 4}
                && mostRecurringElement(new int[] { 7, 1, 5, 7, 7, 9 }) == 7        //{1, 5, 7, 7, 7, 9}
                && mostRecurringElement(new int[] { 1, 2, 3, 1, 2, 3, 3 }) == 3     //{1, 1, 2, 2, 3, 3, 3}
                && mostRecurringElement(new int[] { 5, 11, 2, 11, 7, 11 }) == 11;   //{2, 5, 7, 11, 11, 11}
    }   //true

    public static void main(final String[] args) {
        System.out.println("testCountOccurrencies: " + testCountOccurrencies());
        System.out.println("testEvenElems: " + testEvenElements());
        System.out.println("testOddElems: " + testOddElements());
        System.out.println("testGetMostRecurringElem: " + testMostRecurringElement());
        /*
        //DEBUG
        System.out.println("most recurring elements: " + mostRecurringElement(new int[] { 1, 2, 1, 3, 4 }) + ", " 
                + mostRecurringElement(new int[] { 7, 1, 5, 7, 7, 9 }) + ", "
                + mostRecurringElement(new int[] { 1, 2, 3, 1, 2, 3, 3 }) + ", "
                + mostRecurringElement(new int[] { 5, 11, 2, 11, 7, 11 }));
        */
    }
}
