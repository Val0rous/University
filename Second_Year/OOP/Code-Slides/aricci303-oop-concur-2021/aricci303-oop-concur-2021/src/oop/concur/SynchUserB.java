package oop.concur;

public class SynchUserB extends Thread {

	private SimpleSynchronizer sync;
	
	public SynchUserB(SimpleSynchronizer sync) {
		this.sync = sync;
	}
	
	public void run() {
		b1();
		try {
			sync.waitForSignal();
			b2();
			b3();
		} catch (Exception ex) {
			log("interrupted");
		}
	}
	
	private void b1() { log("b1"); }
	private void b2() { log("b2"); }
	private void b3() { log("b3"); }
	
	private void log(String msg) {
		synchronized (System.out) {
			System.out.println("[" + getName() + "] " + msg);
		}
	}
}
