package oop.lab02.arrays;

import oop.lab02.arrays.Smartphone;

public class PlayWithSmartphoneArrays{

    static int search(final Smartphone[] array, final String brand) {
        int counter = 0;
        for(Smartphone i : array) {
            if(i.brand == brand) {
                counter++;
            }
        }
        return counter;
    }

    static int search(final Smartphone[] array, final boolean hasNFC, final boolean hasGPS) {
        int counter = 0;
        for(Smartphone i : array) {
            if(i.hasNFC == hasNFC && i.hasGPS == hasGPS) {
                counter++;
            }
        }
        return counter;
    }

    static int search(final Smartphone[] array, final int nCPUs, final int sdSize, final boolean has3G) {
        int counter = 0;
        for(Smartphone i : array) {
            if(i.nCPU == nCPUs && i.sdSize == sdSize && i.has3G == has3G) {
                counter++;
            }
        }
        return counter;
    }

    public static void main(final String[] args) {
        /*
         * 1) Creare lo smarthpone HTC One ram:1024 sdSize
         * 
         * 2) Creare lo smarthpone Samsung Galaxy Note 3 ram:2048 sdSize:8192
         * gps:true nfc:true 3g:true
         * 
         * 3) Creare lo smarthpone iPhone 5S nfc:false
         * 
         * 4) Creare lo smarthpone Google Nexus 4 gps:true 3g:true
         * 
         * 5) Creare lo smarthpone Acer Liquid cpu:2 ram:512 sdSize:8192 gps:
         * true 3g:true nfc: false
         * 
         * 6) Eseuguire diverse operazioni di ricerca con i metodi search
         * implementati e controllare la corrispondenza del numero dei telefoni
         * facenti match
         */
        
        final Smartphone[] smartphoneList = new Smartphone[5];
        smartphoneList[0] = new Smartphone("HTC", "One", 1024);
        smartphoneList[1] = new Smartphone("Samsung", "Galaxy Note 3", 8192, 
                                                true, true, true, 4, 2048);
        smartphoneList[2] = new Smartphone("Apple", "iPhone 5S", false);
        smartphoneList[3] = new Smartphone("Google", "Nexus 4", Smartphone.DEF_SD_SIZE, true, true);
        smartphoneList[4] = new Smartphone("Acer", "Liquid", 8192, true, true, false, 2, 2048);

        System.out.println("#Apple: " + search(smartphoneList, "Apple"));
        System.out.println("#Phones with GPS and NFC: " + search(smartphoneList, true, true));
        System.out.println("#Phones with 2 CPUs, 8192MB SD and 3G: " + search(smartphoneList, 2, 8192, true));
    }
}
