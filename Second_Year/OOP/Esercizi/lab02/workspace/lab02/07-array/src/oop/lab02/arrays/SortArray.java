package oop.lab02.arrays;

import java.lang.Math;

public class SortArray {

    // A utility function to swap two elements
    static void swap(double[] arr, int i, int j)
    {
        double temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    /* This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right
    of pivot */
    static double partition(double[] arr, int low, int high, boolean desc)
    {
        
        // pivot
        double pivot = arr[high]; 
        
        // Index of smaller element and
        // indicates the right position
        // of pivot found so far
        int i = (low - 1); 
    
        for(int j = low; j < high; j++)
        {
            if(desc == true) {
                // If current element is smaller 
                // than the pivot
                if (arr[j] <= pivot) 
                {
                    
                    // Increment index of 
                    // smaller element
                    i++; 
                    swap(arr, i, j);
                }
            } else if(desc == false) {
                // If current element is smaller 
                // than the pivot
                if (arr[j] >= pivot) 
                {
                    
                    // Increment index of 
                    // smaller element
                    i++; 
                    swap(arr, i, j);
                }
            }
        }
        swap(arr, i + 1, high);
        return (i + 1);
    }
    
    /* The main function that implements QuickSort
            arr[] --> Array to be sorted,
            low --> Starting index,
            high --> Ending index
    */
    static void quickSort(double[] arr, int low, int high, boolean desc)
    {
        if (low < high) 
        {
            
            // pi is partitioning index, arr[p]
            // is now at right place 
            int pi = (int)partition(arr, low, high, desc);
    
            // Separately sort elements before
            // partition and after partition
            quickSort(arr, low, pi - 1, desc);
            quickSort(arr, pi + 1, high, desc);
        }
    }
    
    // Function to print an array 
    static void printArray(double[] arr, int size)
    {
        for(int i = 0; i < size; i++)
            System.out.print(arr[i] + " ");
            
        System.out.println();
    }

    public static double[] sortArray(double[] array, boolean desc) {
        //if desc == true, sorts into ascending order
        //if desc == false, sorts into descending order

        double[] temp = new double[array.length];
        for(int i = 0; i < array.length; i++) {
            //copying elements
            temp[i] = array[i];
        }
        quickSort(temp, 0, temp.length - 1, desc);
        return temp;
    }

    private static double computeMean(double[] array) {
        double sum = 0;
        for(int i = 0; i < array.length; i++) {
            sum += array[i];
        }
        sum /= array.length;
        return sum;
    }

    public static double computeVariance(double[] array) {
        double mean = computeMean(array);
        double sum = 0;
        for(int i = 0; i < array.length; i++) {
            sum += Math.pow((array[i] - mean), 2);
        }
        sum /= array.length;
        return sum;
    }

    public static void main(String args[]) {
        double[] array0 = new double[] {7, 2, 6, 8, 4};
        double[] array1 = sortArray(array0, true);
        double[] array2 = sortArray(array0, false);

        printArray(array0, array0.length);
        printArray(array1, array1.length);
        printArray(array2, array2.length);

        System.out.println("Mean: " + computeMean(array0));
        System.out.println("Variance: " + computeVariance(array0));
        System.out.println("Standard Deviation: " + Math.sqrt(computeVariance(array0)));
    }
}