package oop.lab02.arrays;

public class RevertUpTo {

    public static int[] revertUpTo(int[] array, int stopElement) {
        int[] temp = new int[array.length];
        int firstOccurrence = 0;    //if there's no element, it doesn't reverse anything
        for(int i = 0; i < array.length; i++) {
            if(array[i] == stopElement) {
                firstOccurrence = i;
                break;
            }
        }
        int k = 0;
        for(int i = firstOccurrence; i >= 0; i--) {
            temp[k] = array[i];
            k++;
        }
        for(int i = firstOccurrence + 1; i < array.length; i++) {
            temp[i] = array[i];
        }
        return temp;
    }

    public static void main(final String[] args) {
        int[] array1 = new int[] {1, 2, 3, 4, 5, 6, 7};
        array1 = revertUpTo(array1, 5);
        for(int i = 0; i < array1.length; i++) {
            System.out.print(array1[i] + " ");
        }
    }
}