package oop.concur.chrono2;

import java.util.LinkedList;
import java.util.List;

public class ChronoCount {

	private int cont;
	private int base;
	private List<ChronoCountListener> listeners;

	public ChronoCount(int base) {
		this.cont = base;
		this.base = base;
		listeners = new LinkedList<ChronoCountListener>();
	}

	public void inc() {
		cont++;
		this.notifyChronoCountChanged();
		System.out.println("count " + cont);
	}

	public void reset() {
		cont = base;
		this.notifyChronoCountChanged();
	}

	public int getValue() {
		return cont;
	}
	
	public void addChronoCountListener(ChronoCountListener l) {
		listeners.add(l);
	}
	
	protected void notifyChronoCountChanged() {
		for (ChronoCountListener l: listeners) {
			l.notifyChronoCountChanged(cont);
		}
	}
}
