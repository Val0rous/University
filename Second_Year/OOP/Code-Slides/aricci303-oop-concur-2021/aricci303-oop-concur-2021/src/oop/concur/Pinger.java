package oop.concur;

public class Pinger extends Thread {

	private SimpleSynchronizer mySync, otherSync;
	
	public Pinger(SimpleSynchronizer mySync, SimpleSynchronizer otherSync) {
		this.mySync = mySync;
		this.otherSync = otherSync;
	}
	
	public void run() {
		try {
			while (true) {
				mySync.waitForSignal();
				log("ping");
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
