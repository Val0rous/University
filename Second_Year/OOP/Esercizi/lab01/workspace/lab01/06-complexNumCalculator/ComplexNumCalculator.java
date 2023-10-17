public class ComplexNumCalculator {
    static int nOpDone;
    ComplexNum lastRes = new ComplexNum();

    void build() {
        nOpDone = 0;
        this.lastRes.build(0,0);
    }

    ComplexNum add(ComplexNum a, ComplexNum b) {
        ////ComplexNum sum = new ComplexNum();
        this.lastRes.re = a.re + b.re;
        this.lastRes.im = a.im + b.im;
        nOpDone++;
        return lastRes;
    }

    ComplexNum sub(ComplexNum a, ComplexNum b) {
        ////ComplexNum difference = new ComplexNum();
        this.lastRes.re = a.re - b.re;
        this.lastRes.im = a.im - b.im;
        nOpDone++;
        return lastRes;
    }

    ComplexNum mul(ComplexNum a, ComplexNum b) {
        ////ComplexNum product = new ComplexNum();
        this.lastRes.re = a.re * b.re - a.im * b.im;
        this.lastRes.im = a.im * b.re + a.re * b.im;
        nOpDone++;
        return lastRes;
    }

    ComplexNum div(ComplexNum a, ComplexNum b) {
        ////ComplexNum quotient = new ComplexNum();
        this.lastRes.re = (a.re * b.re + a.im * b.im)/(b.re * b.re + b.im * b.im);
        this.lastRes.im = (a.im * b.re - a.re * b.im)/(b.re * b.re + b.im * b.im);
        nOpDone++;
        return lastRes;
    }
}
