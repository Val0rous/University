package oop.concur;

import static org.fusesource.jansi.Ansi.ansi;

import org.fusesource.jansi.AnsiConsole;
import org.fusesource.jansi.Ansi.Color;

public class Screen {
	
	private static Screen instance = null;
	
	public static Screen getInstance() {
		synchronized (Screen.class) {
			if (instance == null) {
				instance = new Screen();
			}				
		}
		return instance;
	}

	protected Screen() {
		AnsiConsole.systemInstall();
	}
	
	public void clear() {
		synchronized (this) {
			System.out.println( ansi().eraseScreen().reset());
		}		
	}
	
	public void writeStringAt(int line, int column, Color color, String msg) {
		synchronized (this) {
			System.out.println( ansi().cursor(line,column).fg(color).a(msg).reset() );
		}
	}
	
}
