package oop.concur;

import java.util.*;

public class SequentialSortTest {

	static final int VECTOR_SIZE = 100000000;

	public static void main(String[] args) {

		log("Generating array...");
		int[] v = genArray(100000000);
		
		log("Array generated.");

		log("Sequential sorting (" + VECTOR_SIZE + " elements)...");
		long t0 = System.nanoTime();

		/* sequential sorting */
		Arrays.sort(v, 0, v.length);

		long t1 = System.nanoTime();
		log("Done. Time elapsed: " + ((t1 - t0) / 1000000) + " ms");
		if (check(v)) {
			log("SORTING OK.");
		} else {
			log("SORTING NOT OK.");
		}
	}

	private static boolean check(int[] v) {
		double a = v[0];
		for (int i = 1; i < v.length; i++) {
			if (a > v[i]) {
				return false;
			}
			a = v[i];
		}
		return true;
	}

	private static int[] genArray(int n) {
		Random gen = new Random(10000);
		int v[] = new int[n];
		for (int i = 0; i < v.length; i++) {
			v[i] = gen.nextInt();
		}
		return v;
	}

	private static void log(String msg) {
		System.out.println(msg);
	}
}
