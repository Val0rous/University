package oop.concur.chrono;

public class ChronoController implements Controller {

	private ChronoAgent agent;
	private ChronoCount counter;
	private ChronoView view;
	
	public ChronoController(ChronoCount counter) {
		this.counter = counter;
	}
	
	public void attachView(ChronoView view) {
		this.view = view;
	}
	
	@Override
	public void notifyStarted() {
		agent = new ChronoAgent(counter, view);
		agent.start();
	}

	@Override
	public void notifyStopped() {
		agent.notifyStopped();
	}

	@Override
	public void notifyReset() {
		counter.reset();
		view.updateCount(counter.getValue());
	}
}
