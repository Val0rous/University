package oop.concur;

/**
 * Thread safe Counter.
 * 
 * @ThreadSafe
 * 
 * @author aricci
 *
 */
public class SafeCounter implements Counter {

	private long cont;

	public SafeCounter() {
		cont = 0;
	}

	public synchronized void inc() {
		cont++;
	}

	public synchronized void dec() {
		cont--;
	}

	public synchronized long getValue() {
		return cont;
	}
}
