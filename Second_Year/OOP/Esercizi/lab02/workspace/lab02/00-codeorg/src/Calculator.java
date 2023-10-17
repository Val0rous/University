public class Calculator {

    int nOpDone;
    double lastRes;

    void build() {
        nOpDone = 0;
        lastRes = 0;
    }

    double add(final double n1, final double n2) {
        lastRes = n1 + n2;
        nOpDone++;
        return lastRes;
    }

    double sub(final double n1, final double n2) {
        lastRes = n1 - n2;
        nOpDone++;
        return lastRes;
    }

    double mul(final double n1, final double n2) {
        lastRes = n1 * n2;
        nOpDone++;
        return lastRes;
    }

    double div(final double n1, final double n2) {
        lastRes = n1 / n2;
        nOpDone++;
        return lastRes;
    }

    public static void main(final String[] args) {
        final Calculator calc = new Calculator();

        System.out.println("1+2=" + calc.add(1, 2));
        System.out.println("nOpDone=" + calc.nOpDone);
        System.out.println("lastRes=" + calc.lastRes + "\n");

        System.out.println("-1-(+2)=" + calc.sub(-1, 2));
        System.out.println("nOpDone=" + calc.nOpDone);
        System.out.println("lastRes=" + calc.lastRes + "\n");

        System.out.println("6*3=" + calc.mul(6, 3));
        System.out.println("nOpDone=" + calc.nOpDone);
        System.out.println("lastRes=" + calc.lastRes + "\n");

        System.out.println("8/4=" + calc.div(8, 4));
        System.out.println("nOpDone=" + calc.nOpDone);
        System.out.println("lastRes=" + calc.lastRes + "\n");
    }
}
