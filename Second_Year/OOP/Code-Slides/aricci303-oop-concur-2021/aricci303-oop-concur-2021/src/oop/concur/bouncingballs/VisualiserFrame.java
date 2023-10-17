package oop.concur.bouncingballs;

import java.awt.Graphics;
import java.awt.Color;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.*;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.Font;

public class VisualiserFrame extends JFrame {

	private VisualiserPanel panel;
	
	private static final int WINDOW_SIZE_X = 800;
	private static final int WINDOW_SIZE_Y = 600;

	
	public VisualiserFrame(Context ctx) {
		setTitle("Bouncing Balls");
        
		setSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
		setResizable(false);
		panel = new VisualiserPanel();
		getContentPane().add(panel);
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent ev) {
				System.exit(-1);
			}

			public void windowClosed(WindowEvent ev) {
				System.exit(-1);
			}
		});
	}

	public void updatePosition(P2d[] pos) {
		panel.updatePositions(pos);
	}

	public static class VisualiserPanel extends JPanel {
		private P2d[] positions;

	    private Font usedFont;
	    
	    public VisualiserPanel() {
			setSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
			usedFont = new Font("Verdana", Font.PLAIN, 24);
		}

		public void paint(Graphics g) {
			Graphics2D g2 = (Graphics2D) g;
    		g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
    		g2.setRenderingHint(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY);

    		g2.clearRect(0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y);
			int dx = WINDOW_SIZE_X / 2;
			int dy = WINDOW_SIZE_Y / 2;
			
			synchronized (this) {
				if (positions != null) {
					for (int i = 0; i < positions.length; i++) {
						P2d p = positions[i];
						int x0 = (int) (dx + p.x * dx);
						int y0 = (int) (dy - p.y * dy);
						g.drawOval(x0, y0, 20, 20);
					}
				}
			}
			

			g2.setFont(usedFont);
			g2.setColor(Color.BLUE);
			g2.drawString("Num Balls: " + positions.length, 30, 50);
			
			
		}

		public void updatePositions(P2d[] pos) {
			synchronized (this) {
				positions = pos;
			}
			repaint();
		}
	}
}
