package it.unibo.apice.oop.p08polymorphism.abs;

/* Si esaurisce all'n-esima accensione */
public class CountdownLamp extends LimitedLamp {

	/* Quanti switch mancano */
	private int countdown;

	public CountdownLamp(final int countdown) {
		super();
		this.countdown = countdown;
	}

	/* Allo switchOn.. decremento il count */
	protected void okSwitch() {
		this.countdown--;
	}

	/* Finito il count.. lamp esaurita */
	public boolean isOver() {
		return this.countdown == 0;
	}
}
