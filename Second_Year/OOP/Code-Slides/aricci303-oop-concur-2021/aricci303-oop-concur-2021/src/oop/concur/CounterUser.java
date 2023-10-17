package oop.concur;

public class CounterUser extends Thread {
	private long ntimes;
	private Counter counter;

	public CounterUser(String name, Counter c, long n) {
		super(name);
		ntimes = n;
		counter = c;
	}

	public void run() {
		log("starting - counter value is " + counter.getValue());
		for (long i = 0; i < ntimes; i++) {
			counter.inc();
		}
		log("completed - counter value is " + counter.getValue());
	}

	private void log(String msg) {
		System.out.println("[COUNTER USER " + getName() +"] " + msg);
	}

}
