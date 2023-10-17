package oop.concur;

import java.util.Arrays;

public class SortingWorker extends Thread {

	private int minIndex;
	private int maxIndex;
	private int[] data;

	public SortingWorker(int minIndex, int maxIndex, int[] data) {
		this.minIndex = minIndex;
		this.maxIndex = maxIndex;
		this.data = data;
	}

	public void run() {
		log("starting " + minIndex + "-" + maxIndex);
		Arrays.sort(data, minIndex, maxIndex);
		log("done " + minIndex + "-" + maxIndex);
	}

	private void log(String msg) {
		System.out.println(getName() + " " + msg);
	}

}
