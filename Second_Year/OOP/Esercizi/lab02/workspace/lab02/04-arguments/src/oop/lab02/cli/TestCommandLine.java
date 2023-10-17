package oop.lab02.cli;

public class TestCommandLine {

    public static void main(final String[] args) {
        /*
         * Write the main method in such a way that it iterates through the
         * array of arguments, printing each one along with the length of the
         * string - the String class provides a
         *
         * int length()
         *
         * method that returns the length of the String.
         *
         * Example output:
         *
         * $ java oop.lab02.cli.TestCommandLine it's a trap
         *
         * The provided arguments are:
         *  * it's, 4 characters long
         *  * a, 1 characters long
         *  * trap, 4 characters long
         *
         * NB: depending on the shell in use, the quote symbol may open a string
         * and create issues with the interpretation of the above command.
         * In that case, close the string or use Ctrl+C to interrupt
         * the current command. If you do want to provide an argument "it's",
         * you might be able to solve the issue in the following two ways:
         *   1) By using quotes to wrap the argument
         *   $ java oop.lab02.cli.TestCommandLine "it's" a trap
         *   2) By escaping the single quote
         *   $ java oop.lab02.cli.TestCommandLine it\'s a trap
         */

        //DEBUG: System.out.println("Args length is: " + args.length);
        System.out.println("The provided arguments are:");
        
        for(int i = 0; i < args.length; i++) {
            System.out.println(args[i] + ", " + args[i].length() + " character(s) long");
        }
    }

}
