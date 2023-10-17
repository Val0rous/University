package oop.concur;

public class InfiniteLoops {
	public static void main(String[] args) {
		for (int i = 0; i < Integer.parseInt(args[0]); i++) {
			System.out.println("Spawning #" + i + "...");
			new Thread(new Runnable() {
				public void run() {
					while (true) {}
				}
			}).start();
		}
	}
}
