package oop.concur;

import javax.swing.*;
import java.awt.event.*;

class MyFrame extends JFrame implements ActionListener {

	private static final long serialVersionUID = 1L;

	public MyFrame() {
		super("Test Swing thread");
		setSize(200, 60);
		setVisible(true);
		JButton button = new JButton("test");
		button.addActionListener(this);
		getContentPane().add(button);
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent ev) {
				System.exit(-1);
			}
		});
	}

	public void actionPerformed(ActionEvent e) {
		System.out.println("reacting...");
		while (true) {}
		/*
		try {
			Thread.sleep(10000);
		} catch (Exception ex) {}
		*/
	}
}

public class TestSwingThread {
	static public void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			new MyFrame();
			new MyFrame();
		});
	}
}
