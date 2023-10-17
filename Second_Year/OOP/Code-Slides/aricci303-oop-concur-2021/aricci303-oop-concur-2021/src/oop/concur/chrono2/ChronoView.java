package oop.concur.chrono2;

import javax.swing.*;

public class ChronoView implements ChronoCountListener {

	private ChronoFrame frame;

	public ChronoView(int initialCount, Controller controller) {
		frame = new ChronoFrame(initialCount, controller);
	}
	
	public void show() {
		try {
			SwingUtilities.invokeAndWait(new Runnable() {
				public void run() {
					frame.setVisible(true);
				}
			});
		} catch (Exception ex) {}
	}
	
	@Override
	public void notifyChronoCountChanged(int newValue) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				frame.updateCount(newValue);
			}
		});
	}

}
