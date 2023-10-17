package oop.concur.chrono2;

public class ChronoController implements Controller {

	private ChronoAgent agent;
	private ChronoCount counter;
	
	public ChronoController(ChronoCount counter) {
		this.counter = counter;
	}
	
	
	@Override
	public void notifyStarted() {
		agent = new ChronoAgent(counter);
		agent.start();
	}

	@Override
	public void notifyStopped() {
		agent.notifyStopped();
	}

	@Override
	public void notifyReset() {
		counter.reset();
	}
}
