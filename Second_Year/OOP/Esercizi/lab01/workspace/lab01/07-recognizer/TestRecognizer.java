class TestRecognizer {
    public static void main(String args[]) {
        /*
         * 1) Creare un oggetto della classe Recognizer
         *
         * 2) Realizzare i metodi check1, check2, check3 e check4, che accettano in
         * ingresso un intero, restituendo true soltanto se il valore passato e uguale
         * rispettivamente a 1, 2, 3, 4
         *
         * 3) Invocare i metodi check1, check2, ... passando in input una sequenza
         * corretta e stampando in output il valore di ritorno relativo all'invocazione
         * di ciascun metodo - far precedere l'invocazione di ogni metodo check
         * dall'invocazione di nextExpectedInt
         *
         * 4) Invocare il metodo reset al termine del test su ogni sequenza
         *
         * 5) Testare il riconoscimento per le seguenti sequenze con procedimento
         * analogo a quello appena descritto - 1,2,3,4,1,2 - 1,2,3,4,5 - 1,2,3,4,5,2,3 -
         * ...
         *
         * ESEMPIO DI INVOCAZIONE: riconoscimento sequenza 1,2,3,4,5
         * System.out.println("Next expected int is: " + recognizer.nextExpectedInt());
         *
         * System.out.println("Now the result of the check is: " +
         * recognizer.check1(1)); System.out.println("Next expected int is: " +
         * recognizer.nextExpectedInt());
         *
         * System.out.println("Now the result of the check is: " +
         * recognizer.check2(2)); System.out.println("Next expected int is: " +
         * recognizer.nextExpectedInt());
         *
         * System.out.println("Now the result of the check is: " +
         * recognizer.check3(3)); System.out.println("Next expected int is: " +
         * recognizer.nextExpectedInt());
         *
         * System.out.println("Now the result of the check is: " +
         * recognizer.check4(4)); System.out.println("Next expected int is: " +
         *
         * System.out.println("Now the result of the check is: " +
         * recognizer.check1(5));
         *
         */

        Recognizer recognizer = new Recognizer();
        int sequence1[] = { 1, 2, 3, 4, 1, 2, 3, 4 };
        int sequence2[] = { 1, 2, 3, 4, 1, 2 };
        int sequence3[] = { 1, 2, 3, 4, 5 };
        int sequence4[] = { 1, 2, 3, 4, 5, 2, 3 };

        recognizer.sequence = sequence1;
        recognizer.test();

        recognizer.sequence = sequence2;
        recognizer.test();

        recognizer.sequence = sequence3;
        recognizer.test();

        recognizer.sequence = sequence4;
        recognizer.test();
    }
}
