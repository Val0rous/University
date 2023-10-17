package oop.concur;

public class TestConcurrentSafeCounter {
	public static void main(String[] args) throws Exception {
		// CounterInterface c = new Counter();
		Counter c = new SafeCounter();
		long ntimes = Long.parseLong(args[0]);
		CounterUser agentA = new CounterUser("agent-A", c, ntimes);
		CounterUser agentB = new CounterUser("agent-B", c, ntimes);
		agentA.start();
		agentB.start();
		agentA.join();
		agentB.join();
		System.out.println("Count value: " + c.getValue());
	}
}
