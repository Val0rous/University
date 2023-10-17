package it.unibo.apice.oop.p20patterns.factory;

import java.awt.Color;
import java.awt.Font;

import javax.swing.*;

public class MyGUIFactory implements GUIFactory{
	
	private static final Font MY_FONT = new Font("Garuda",Font.BOLD,12);
	private static final Color MY_COLOR = new Color(255,255,0);
	
	@Override
	public JPanel createPanel(String text) {
		final JPanel p = new JPanel();
		p.setBorder(new javax.swing.border.TitledBorder(text));
		return p;
	}

	@Override
	public JComponent createButton(String text) {;
	    final JButton b = new JButton(text);
	    b.setFont(MY_FONT);
	    b.setBackground (MY_COLOR);
	    return b;
	}

	@Override
	public JComponent createLabel(String text) {
		final JLabel j = new JLabel(text);
		j.setFont(MY_FONT);
		return j;
	}
}
