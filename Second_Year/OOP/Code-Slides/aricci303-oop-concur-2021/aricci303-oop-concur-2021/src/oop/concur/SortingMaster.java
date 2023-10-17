package oop.concur;

public class SortingMaster extends Thread {

	private int[] vectorToSort;

	public SortingMaster(int[] v) {
		vectorToSort = v;
	}
	
	public void run() {
		int middle = vectorToSort.length / 2;
		SortingWorker w1 = new SortingWorker(0, middle, vectorToSort);
		SortingWorker w2 = new SortingWorker(middle, vectorToSort.length, vectorToSort);
		w1.start();
		w2.start();
		try {
			w1.join();
			w2.join();
			merge(vectorToSort, 0, middle, middle, vectorToSort.length);
		} catch (InterruptedException ex) {
		}
	}

	private void merge(int[] vectorToSort, int from1, int to1, int from2, int to2) {
		int index1 = from1;
		int index2 = from2;
		int i = 0;
		while (index1 < to1 && index2 < to2) {
			int a = vectorToSort[index1];
			int b = vectorToSort[index2];
			if (a < b) {
				vectorToSort[i] = a;
				index1++;
			} else {
				vectorToSort[i] = b;
				index2++;
			}
			i++;
		}
		for (int j = index1; j < to1; j++) {
			vectorToSort[i++] = vectorToSort[j];
		}
		for (int j = index2; j < to2; j++) {
			vectorToSort[i++] = vectorToSort[j];
		}

	}

}
