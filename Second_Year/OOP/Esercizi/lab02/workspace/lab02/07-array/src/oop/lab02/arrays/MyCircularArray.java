package oop.lab02.arrays;

public class MyCircularArray {

    public static final int ARRAY_DEF_SIZE = 10;
    int[] array;
    int addPos = 0;

    MyCircularArray(int size) {
        this.array = new int[size];
    }

    MyCircularArray() {
        this(ARRAY_DEF_SIZE);
    }

    public void addElem(final int element) {
        if(this.addPos < this.array.length) {
            this.array[addPos] = element;
            this.addPos++;
        } else {
            addPos = 0;
            this.array[addPos] = element;
            this.addPos++;
        }
    }

    public void reset() {
        for(int i = 0; i < this.array.length; i++) {
           this.array[i] = 0;
        }
        this.addPos = 0;
    }

    public void printArray() {
        System.out.print("[");
        for (int i = 0; i < this.array.length - 1; i++) {
            System.out.print(this.array[i] + ",");
        }
        System.out.println(this.array[this.array.length - 1] + "]");
    }

    public static void main(final String[] args) {
        /*
         * 1) Creare un array circolare di dieci elementi
         * 
         * 2) Aggiungere gli elementi da 1 a 10 e stampare il contenuto
         * dell'array circolare
         * 
         * 3) Aggiungere gli elementi da 11 a 15 e stampare il contenuto
         * dell'array circolare
         * 
         * 4) Invocare il metodo reset
         * 
         * 5) Stampare il contenuto dell'array circolare
         * 
         * 6) Aggiungere altri elementi a piacere e stampare il contenuto
         * dell'array circolare
         */

        final MyCircularArray circularArray = new MyCircularArray(10);

        for(int i = 1; i <= 10; i++) {
            circularArray.addElem(i);
        }
        circularArray.printArray();

        for(int i = 11; i <= 15; i++) {
            circularArray.addElem(i);
        }
        circularArray.printArray();

        circularArray.reset();

        circularArray.printArray();

        for(int i = 0; i <= 20; i++) {
            circularArray.addElem(i);
        }
        circularArray.printArray();

    }
}
