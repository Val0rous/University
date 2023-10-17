package oop.concur;

public class TestConcurrentUnsafeCounterWithTime {
	public static void main(String[] args) throws Exception {
		Counter c = new UnsafeCounter();
		long ntimes = Long.parseLong(args[0]);
		CounterUser agentA = new CounterUser("agent-A", c, ntimes);
		CounterUser agentB = new CounterUser("agent-B", c, ntimes);
		long t0 = System.currentTimeMillis();
		agentA.start();
		agentB.start();
		agentA.join();
		agentB.join();
		long t1 = System.currentTimeMillis();
		System.out.println("Count value: " + c.getValue());
		System.out.println("Time elapsed: " + (t1 - t0) + "ms.");
	}
}
