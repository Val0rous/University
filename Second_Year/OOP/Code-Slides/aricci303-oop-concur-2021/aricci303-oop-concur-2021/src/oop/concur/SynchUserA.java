package oop.concur;

public class SynchUserA extends Thread {

	private SimpleSynchronizer sync;
	
	public SynchUserA(SimpleSynchronizer sync) {
		this.sync = sync;
	}
	
	public void run() {
		a1();
		a2();
		sync.signal();
		a3();
	}
	
	private void a1() { log("a1"); delay(1000);}
	private void a2() { log("a2"); delay(2000);}
	private void a3() { log("a3"); delay(1000);}
	
	private void log(String msg) {
		synchronized (System.out) {
			System.out.println("[" + getName() + "] " + msg);
		}
	}
	
	private void delay(long dt) {
		try {
			sleep(dt);
		} catch (Exception ex) {}
	}
}
