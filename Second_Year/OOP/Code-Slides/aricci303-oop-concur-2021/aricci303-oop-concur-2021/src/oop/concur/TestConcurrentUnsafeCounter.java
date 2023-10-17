package oop.concur;

public class TestConcurrentUnsafeCounter {
	public static void main(String[] args) throws Exception {
		Counter c = new UnsafeCounter();
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
