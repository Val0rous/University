package oop.concur.chrono2;

public class TestChrono {
	public static void main(String[] args) {

		ChronoCount count = new ChronoCount(0);
		Controller controller = new ChronoController(count);
		ChronoView view = new ChronoView(count.getValue(), controller);
		count.addChronoCountListener(view);
		view.show();

	}
}
