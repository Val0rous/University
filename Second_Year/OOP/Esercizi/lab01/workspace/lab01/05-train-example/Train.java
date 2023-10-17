class Train {

    int nTotSeats;
    int nFirstClassSeats;
    int nSecondClassSeats;
    int nFirstClassReservedSeats;
    int nSecondClassReservedSeats;

    void build() {
        nTotSeats = 100;
        nFirstClassSeats = 30;
        nSecondClassSeats = 70;
        nFirstClassReservedSeats = 0;
        nSecondClassReservedSeats = 0;
    }

    void reserveFirstClassSeats(int num) {
        nFirstClassReservedSeats += num;
    }

    void reserveSecondClassSeats(int num) {
        nSecondClassReservedSeats += num;
    }

    double getTotOccupancyRatio() {
        return ((double)(nFirstClassReservedSeats + nSecondClassReservedSeats)/nTotSeats)*100;
    }

    double getFirstClassOccupancyRatio() {
        return ((double)nFirstClassReservedSeats/nFirstClassSeats)*100;
    }

    double getSecondClassOccupancyRatio() {
        return((double)nSecondClassReservedSeats/nSecondClassSeats)*100;
    }

    void deleteAllReservations() {
        nFirstClassReservedSeats = 0;
        nSecondClassReservedSeats = 0;
    }
}