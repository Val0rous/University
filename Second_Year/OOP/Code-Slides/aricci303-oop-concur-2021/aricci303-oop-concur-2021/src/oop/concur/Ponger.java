package oop.concur;

public class Ponger extends Thread {

	private SimpleSynchronizer mySync, otherSync;
	
	public Ponger(SimpleSynchronizer mySync, SimpleSynchronizer otherSync) {
		this.mySync = mySync;
		this.otherSync = otherSync;
	}
	
	public void run() {
		try {
			while (true) {
				mySync.waitForSignal();
				log("pong");
				otherSync.signal();
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}
	
	private void log(String msg) {
		synchronized (System.out) {
			System.out.println("[" + getName() + "] " + msg);
		}
	}
}
