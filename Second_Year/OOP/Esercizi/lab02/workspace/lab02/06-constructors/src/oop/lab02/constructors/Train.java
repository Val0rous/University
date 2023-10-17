package oop.lab02.constructors;

public class Train {

    int nTotSeats;
    int nFCSeats;
    int nSCSeats;

    int nFCReservedSeats;
    int nSCReservedSeats;

    /*
    void build(final int nTotSeats, final int nFCSeats, final int nSCSeats) {
        this.nTotSeats = nTotSeats;
        this.nFCSeats = nFCSeats;
        this.nSCSeats = nSCSeats;
        this.nFCReservedSeats = 0;
        this.nSCReservedSeats = 0;
    }
    */

    
    Train() {
        this(100, 30, 10, 50);
        /*
        this.nTotSeats = 100;
        this.nFCSeats = 30;
        this.nSCSeats = 70;
        this.nFCReservedSeats = 10;
        this.nSCReservedSeats = 50;
        */
    }
    
    Train(final int nFCSeats, final int nSCSeats) { 
        this((nFCSeats + nSCSeats), nFCSeats, 0, 0);
    }

    Train(final int nTotSeats, final int nFCSeats, final int nFCReservedSeats, final int nSCReservedSeats) {
        this.nTotSeats = nTotSeats;
        this.nFCSeats = nFCSeats;
        this.nSCSeats = nTotSeats - nFCSeats;
        this.nFCReservedSeats = nFCReservedSeats;
        this.nSCReservedSeats = nSCReservedSeats;
    }

    void reserveFCSeats(final int nSeats) {
        this.nFCReservedSeats += nSeats;
    }

    void reserveSCSeats(final int nSeats) {
        this.nSCReservedSeats += nSeats;
    }

    double getTotOccupancyRatio() {
        return (this.nFCReservedSeats + this.nSCReservedSeats) * 100d / this.nTotSeats;
    }

    double getFCOccupancyRatio() {
        return this.nFCReservedSeats * 100d / this.nFCSeats;
    }

    double getSCOccupancyRatio() {
        return this.nSCReservedSeats * 100d / this.nSCSeats;
    }

    void deleteAllReservations() {
        this.nFCReservedSeats = 0;
        this.nSCReservedSeats = 0;
    }

    void printTrainInfo() {
        System.out.println("Train total seats: " + this.nTotSeats);
        System.out.println("Train FC seats: " + this.nFCSeats);
        System.out.println("Train SC seats: " + this.nSCSeats);
        System.out.println("Train reserved FC seats: " + this.nFCReservedSeats);
        System.out.println("Train reserved SC seats: " + this.nSCReservedSeats + "\n");
    }
}
