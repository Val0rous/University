package oop.concur;

import java.util.Random;

import org.fusesource.jansi.Ansi.Color;

public class TestFallingWords {

	public static void main(String[] args) {
		Screen sc = Screen.getInstance();

		String sentence = "This is a long falling sentence from the top of the screen to the bottom";
		
		int startPos = 10;
		int startLine = 1;
		int endLine = 40;
		
		sc.clear();
		sc.writeStringAt(startLine, startPos, Color.WHITE, sentence);
		
		try {
			Thread.sleep(1000);
		} catch (Exception ex) {};
		
		Random gen = new Random(1000);
		
		String[] words = sentence.split(" ");
		int currentPos = startPos;
		for (String w: words) {
			new WordFallingAgent(w, startLine, currentPos, endLine, 10 + gen.nextInt(30)).start();
			currentPos += w.length() + 1;
		}
	}

}
