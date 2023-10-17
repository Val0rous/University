package oop.concur;

import java.io.*;

public class TestClock {
	static public void main(String[] args) throws Exception {
		Clock clock = new Clock(1000);
		clock.start();

		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String input = null;
		System.out.println("READY");
		do {
			input = reader.readLine();
			System.out.println("eco: " + input);
		} while (!input.equals("exit"));
		System.exit(0);
	}
}
