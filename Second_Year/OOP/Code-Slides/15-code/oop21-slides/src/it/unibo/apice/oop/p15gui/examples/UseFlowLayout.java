package it.unibo.apice.oop.p15gui.examples;

import java.awt.*;
import javax.swing.*;

public class UseFlowLayout{
	public static void main(String[] args){
		final FlowLayout lay = new FlowLayout(FlowLayout.CENTER);
		final MyFrame frame = new MyFrame("FlowLayout Example",lay);
		frame.getMainPanel().add(new JButton("A"));
		frame.getMainPanel().add(new JButton("BCD"));
		frame.getMainPanel().add(new JButton("EDFGHI"));
		frame.getMainPanel().add(new JButton("L"));
		frame.getMainPanel().add(new JButton("MNO"));
		frame.getMainPanel().add(new JButton("PQRSTU"));
		frame.getMainPanel().add(new JButton("V"));
		frame.getMainPanel().add(new JButton("ZZZZZZZ"));
		//frame.pack(); ridimensiona la finestra: da provare!
		frame.setVisible(true);
	}
	/* Note sul FlowLayout:
	 * - Di default mette i componenti da sx a dx, centrati
	 * - usa le loro dim preferite
	 * - va a capo quando necessario, partendo dall'alto 
	 * .. tutti aspetti modificabili agendo sull'oggetto Layout
	 */
}
