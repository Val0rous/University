package oop.concur;

import org.fusesource.jansi.Ansi.Color;

public class WordFallingAgent extends Thread {
	
	private String word;
	private int startLine, startColumn, endLine;
	private long delay;
	
	public WordFallingAgent(String word, int startLine, int startColumn, int endLine, long delay) {
		this.word = word;
		this.startLine = startLine;
		this.startColumn = startColumn;
		this.endLine = endLine;
		this.delay = delay;
	}
	
	public void run() {
		Screen sc = Screen.getInstance();
		int line = startLine;
		String blankString = makeBlank(word.length());
		while (line < endLine) {
			sc.writeStringAt(line, startColumn, Color.WHITE, word);
			delay(delay);
			sc.writeStringAt(line, startColumn, Color.WHITE, blankString);
			line++;
		}
		sc.writeStringAt(line, startColumn, Color.WHITE, word);
	}

	private String makeBlank(int len) {
		StringBuffer sb = new StringBuffer("");
		for (int i = 0; i < len; i++) {
			sb.append(" ");
		}
		return sb.toString();
	}
	
	private void delay(long dt) {
		try {
			Thread.sleep(dt);
		} catch (Exception ex) {}
	}
}
