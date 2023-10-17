package it.unibo.apice.oop.p08polymorphism.abs;

/* Il nome ExtendibleCounter è di comodo, più propriamente
 andrebbe chiamata semplicemente Counter */

public class ExtendibleCounter {

	/* campo counter protetto */
	protected int counter;

	public ExtendibleCounter(final int initialValue) {
		this.counter = initialValue;
	}

	public void increment() {
		this.counter++;
	}

	public int getValue() {
		return counter;
	}
}
