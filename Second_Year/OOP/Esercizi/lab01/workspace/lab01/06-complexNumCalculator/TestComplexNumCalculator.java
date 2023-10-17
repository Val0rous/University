import java.net.CookieManager;

class TestComplexNumCalculator {
    public static void main(String[] args) {
        /*
         * 1) Testare la classe ComplexNumCalculator con le seguenti operazioni
         *    tra numeri complessi:
         *
         * - add(1+2i, 2+3i) = 3+5i
         *
         * - sub(4+5i, 6+7i) = -2-2i
         *
         * - mul(8+2i, 3-i) = 26 - 2i
         *
         * - ... altre a piacere
         *
         * 2) Verificare il corretto valore dei campi nOpDone, lastRes
         *
         * 3) Fare altre prove con operazioni a piacere
         */

        //La rappresentazione di lastRes è marocchina ma essendo inutile va benissimo lasciarla così
        ComplexNum a = new ComplexNum();
        ComplexNum b = new ComplexNum();
        ComplexNumCalculator result = new ComplexNumCalculator();
        result.build();
        
        a.build(1, 2);
        b.build(2, 3);
        result.add(a,b);
        System.out.println(result.lastRes.toStringRep() + " nOpDone: " + ComplexNumCalculator.nOpDone + " lastRes: " + result.lastRes);

        a.build(4, 5);
        b.build(6, 7);
        result.sub(a,b);
        System.out.println(result.lastRes.toStringRep() + " nOpDone: " + ComplexNumCalculator.nOpDone + " lastRes: " + result.lastRes);

        a.build(8, 2);
        b.build(3, -1);
        result.mul(a,b);
        System.out.println(result.lastRes.toStringRep() + " nOpDone: " + ComplexNumCalculator.nOpDone + " lastRes: " + result.lastRes);

        a.build(3, 4);
        b.build(8, -2);
        result.div(a,b);
        System.out.println(result.lastRes.toStringRep() + " nOpDone: " + ComplexNumCalculator.nOpDone + " lastRes: " + result.lastRes);
    }
}
