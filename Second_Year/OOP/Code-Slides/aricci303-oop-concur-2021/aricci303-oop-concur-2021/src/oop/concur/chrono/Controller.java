package oop.concur.chrono;

public interface Controller {

	void attachView(ChronoView view);
	void notifyStarted();
	void notifyStopped();
	void notifyReset();

}
