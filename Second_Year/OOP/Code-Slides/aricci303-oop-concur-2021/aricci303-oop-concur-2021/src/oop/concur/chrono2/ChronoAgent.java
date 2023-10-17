package oop.concur.chrono2;

public class ChronoAgent extends Thread {

	private ChronoCount counter;
	private volatile boolean stopped;

	public ChronoAgent(ChronoCount counter) {
		this.counter = counter;
	}

	public void run() {
		stopped = false;
		while (!stopped) {
			counter.inc();
			System.out.println(counter.getValue());
			try {
				Thread.sleep(10);
			} catch (Exception ex) {
			}
		}
	}

	public void notifyStopped() {
		this.interrupt();
		stopped = true;		
	}
}
