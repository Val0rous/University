package oop.concur.chrono;

public class ChronoAgent extends Thread {

	private ChronoCount counter;
	private ChronoView view;
	private volatile boolean stopped;

	public ChronoAgent(ChronoCount counter, ChronoView view) {
		this.view = view;
		this.counter = counter;
	}

	public void run() {
		stopped = false;
		while (!stopped) {
			counter.inc();
			view.updateCount(counter.getValue());
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
