package oop.concur.chrono;

public class ChronoCount {

	private int cont;
	private int base;

	public ChronoCount(int base) {
		this.cont = base;
		this.base = base;
	}

	public void inc() {
		cont++;
		System.out.println("count " + cont);
	}

	public void reset() {
		cont = base;
	}

	public int getValue() {
		return cont;
	}
}
