package oop.concur.chrono2;

import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

class ChronoFrame extends JFrame implements ActionListener {

	private static final long serialVersionUID = 1L;
	private JButton start;
	private JButton stop;
	private JButton reset;
	private JTextField display;
	private Controller controller;
	
	public ChronoFrame(int initialCount, Controller controller) {
		setTitle("Chrono GUI");
		setSize(300, 100);
		
		this.controller = controller;
		display = new JTextField(5);
		display.setEditable(false);
		display.setText("" + initialCount);
		start = new JButton("start");
		stop = new JButton("stop");
		reset = new JButton("reset");
		stop.setEnabled(false);

		Container cp = getContentPane();
		JPanel panel = new JPanel();

		Box p0 = new Box(BoxLayout.X_AXIS);
		p0.add(display);
		Box p1 = new Box(BoxLayout.X_AXIS);
		p1.add(start);
		p1.add(stop);
		p1.add(reset);
		Box p2 = new Box(BoxLayout.Y_AXIS);
		p2.add(p0);
		p2.add(Box.createVerticalStrut(10));
		p2.add(p1);

		panel.add(p2);
		cp.add(panel);

		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent ev) {
				System.exit(-1);
			}

			public void windowClosed(WindowEvent ev) {
				System.exit(-1);
			}
		});

		start.addActionListener(this);
		stop.addActionListener(this);
		reset.addActionListener(this);
		
		setVisible(true);	
	}
	
	public void updateCount(int value) {
		display.setText("" + value);
	}
		
	public void actionPerformed(ActionEvent ev) {
		Object src = ev.getSource();
		if (src == start) {
			start.setEnabled(false);
			stop.setEnabled(true);
			reset.setEnabled(false);
			controller.notifyStarted();
		} else if (src == stop) {
			controller.notifyStopped();
			start.setEnabled(true);
			stop.setEnabled(false);
			reset.setEnabled(true);
		} else if (src == reset) {
			controller.notifyReset();
		}
	}
	
}
