package oop.concur.chrono;

import javax.swing.*;

public class ChronoView {

	private ChronoFrame frame;

	public ChronoView(int initialCount, Controller controller) {
		frame = new ChronoFrame(initialCount, controller);
	}

	public void show() {
		try {
			SwingUtilities.invokeAndWait(new Runnable(){
				public void run(){
					frame.setVisible(true);
				}
			});
		} catch (Exception ex) {}
	}
	
	public void updateCount(int value) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				frame.updateCount(value);
			}
		});
	}

}
