package oop.concur;

public class TestPingPong {

	public static void main(String[] args) {

		SimpleSynchronizer s0 = new SimpleSynchronizer();
		SimpleSynchronizer s1 = new SimpleSynchronizer();
		
		new Pinger(s0, s1).start();
		new Ponger(s1, s0).start();
		
		s0.signal();
	}

}
