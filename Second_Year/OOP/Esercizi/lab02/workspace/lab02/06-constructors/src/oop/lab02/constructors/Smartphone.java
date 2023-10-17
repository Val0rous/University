package oop.lab02.constructors;

public class Smartphone {

    public static final boolean DEF_HAS_GPS = true;
    public static final boolean DEF_HAS_3G = true;
    public static final boolean DEF_HAS_NFC = true;
    public static final int DEF_SD_SIZE = 8192;
    public static final int DEF_RAM_SIZE = 1024;
    public static final int DEF_N_CPU = 2;

    public int nCPU;
    public int ram;
    public int sdSize;
    public String brand;
    public String model;
    public boolean hasGPS;
    public boolean has3G;
    public boolean hasNFC;

    public Smartphone(final String brand, final String model) {
        this.brand = brand;
        this.model = model;
        
        this.nCPU = DEF_N_CPU;
        this.ram = DEF_RAM_SIZE;
        this.sdSize = DEF_SD_SIZE;
        this.hasGPS = DEF_HAS_GPS;
        this.has3G = DEF_HAS_3G;
        this.hasNFC = DEF_HAS_NFC;
    }

    public Smartphone(final String brand, final String model, final int sdSize, 
            final boolean hasGPS, final boolean has3G) {
        this(brand, model, sdSize);
        this.hasGPS = hasGPS;
        this.has3G = has3G;
    }

    public Smartphone(final String brand, final String model, final int sdSize) {
        this(brand, model);
        this.sdSize = sdSize;
    }

    public Smartphone(final String brand, final String model, final boolean hasNFC) {
        this(brand, model);
        this.hasNFC = hasNFC;
    }

    public Smartphone(final String brand, final String model, final int sdSize, 
            final boolean hasGPS, final boolean has3G, final boolean hasNFC, 
            final int nCPU, final int ram) {
        this(brand, model, sdSize, hasGPS, has3G);
        this.hasNFC = hasNFC;
        this.nCPU = nCPU;
        this.ram = ram;
    }

    public void printStringRep() {
        System.out.println("n CPU(s): " + this.nCPU);
        System.out.println("RAM amount: " + ram);
        System.out.println("SD size: " + this.sdSize);
        System.out.println("brand: " + this.brand);
        System.out.println("model: " + this.model);
        System.out.println("hasGPS: " + this.hasGPS);
        System.out.println("has3G: " + this.has3G);
        System.out.println("hasNFC: " + this.hasNFC + "\n");
    }

    public static void main(final String[] args) {
        /*
         * 1) Creare lo smarthpone HTC One sdSize:1024
         * 
         * 2) Creare lo smarthpone Samsung Galaxy Note 3 nCPU:4 ram:2048
         * sdSize:8192 gps:true nfc:true 3g:true
         * 
         * 3) Creare lo smarthpone iPhone 5S nfc:false
         * 
         * 4) Creare lo smarthpone Google Nexus 4 gps:true 3g:true
         * 
         * 5) Utilizzare il metodo printStringRep per stampare in standard
         * output le informazioni di ciascun telefono
         */

        Smartphone htc = new Smartphone("HTC", "One", 1024);
        Smartphone samsung = new Smartphone("Samsung", "Galaxy Note 3", 8192, 
                                            true, true, true, 4, 2048);
        Smartphone apple = new Smartphone("Apple", "iPhone 5S", false);
        Smartphone google = new Smartphone("Google", "Nexus 4", DEF_SD_SIZE, true, true);

        htc.printStringRep();
        samsung.printStringRep();
        apple.printStringRep();
        google.printStringRep();
    }
}
