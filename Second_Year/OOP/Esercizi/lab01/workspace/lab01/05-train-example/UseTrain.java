class UseTrain {
    public static void main(String[] args) {
        /*
         * Premesse per un corretto testing della classe. Per ragioni di
         * coerenza e semplicità:
         * - I vari metodi siano sempre invocati passando dei parametri di input
         * validi e consistenti (p.e. non invocare i metodi per effettuare delle
         * prenotazioni specificando un numero di posti superiore alla capienza
         * del treno, ai posti disponibili per la classe (prima/seconda)
         * considerata, al numero di posti correntemente liberi
         *
         *
         * Testing: 1) Creare un oggetto della classe Train specificando valori
         * a piacere per i parametri
         *
         * 2) Effettuare delle prenotazioni in prima e seconda classe
         * specificando un numero di posti da prenotare consistente
         *
         * 3) A seguito di ciascuna prenotazione stampare la ratio di
         * occupazione totale e per ciascuna classe.
         *
         * 4) Cancellare tutte le prenotazioni
         *
         * 5) Prenotare nuovamente dei posti e stampare le nuove percentuali di
         * occupazione
         */

        Train train = new Train();
        train.build();

        train.reserveFirstClassSeats(15);
        System.out.println("total occupied seats: " + train.getTotOccupancyRatio() 
                + "%, 1st class occupancy ratio: " + train.getFirstClassOccupancyRatio() 
                + "%, 2nd class occupancy ratio: " + train.getSecondClassOccupancyRatio() + "%");

        train.reserveSecondClassSeats(50);
        System.out.println("total occupied seats: " + train.getTotOccupancyRatio() 
                + "%, 1st class occupancy ratio: " + train.getFirstClassOccupancyRatio() 
                + "%, 2nd class occupancy ratio: " + train.getSecondClassOccupancyRatio() + "%");

        train.deleteAllReservations();

        train.reserveFirstClassSeats(2);
        train.reserveSecondClassSeats(69);
        System.out.println("total occupied seats: " + train.getTotOccupancyRatio() 
                + "%, 1st class occupancy ratio: " + train.getFirstClassOccupancyRatio() 
                + "%, 2nd class occupancy ratio: " + train.getSecondClassOccupancyRatio() + "%");
    }
}
