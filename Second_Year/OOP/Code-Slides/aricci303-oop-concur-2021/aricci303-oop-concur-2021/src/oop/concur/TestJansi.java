package oop.concur;

import static org.fusesource.jansi.Ansi.*;

public class TestJansi {

	public static void main(String[] args) {
		Screen screen = Screen.getInstance();
		screen.clear();
		screen.writeStringAt(10, 20, Color.RED, "Hello");
	
	}

}
