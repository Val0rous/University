public class Recognizer {
    int sequence[];
    static int counter = 0;
    static boolean last = true;

    boolean check1(int a) {
        if (a == 1) {
            return true;
        }
        return false;
    }

    boolean check2(int a) {
        if (a == 2) {
            return true;
        }
        return false;
    }

    boolean check3(int a) {
        if (a == 3) {
            return true;
        }
        return false;
    }

    boolean check4(int a) {
        if (a == 4) {
            return true;
        }
        return false;
    }

    int nextExpectedInt() {
        return sequence[counter];
    }

    void reset() {
        counter = 0;
        last = true;
    }

    void test() {
        while (counter < this.sequence.length) {
            System.out.println("Next expected int is: " + this.nextExpectedInt());
            if ((counter % 4) == 0) {
                System.out.println("Now the result of the check is: " + (this.check1(this.sequence[counter]) && last));
                if (this.check1(this.sequence[counter]) == false) {
                    last = false;
                }
            } else if ((counter % 4) == 1) {
                System.out.println("Now the result of the check is: " + (this.check2(this.sequence[counter]) && last));
                if (this.check2(this.sequence[counter]) == false) {
                    last = false;
                }
            } else if ((counter % 4) == 2) {
                System.out.println("Now the result of the check is: " + (this.check3(this.sequence[counter]) && last));
                if (this.check3(this.sequence[counter]) == false) {
                    last = false;
                }
            } else if ((counter % 4) == 3) {
                System.out.println("Now the result of the check is: " + (this.check4(this.sequence[counter]) && last));
                if (this.check4(this.sequence[counter]) == false) {
                    last = false;
                }
            }
            counter++;
        }
        this.reset();
    }
}
