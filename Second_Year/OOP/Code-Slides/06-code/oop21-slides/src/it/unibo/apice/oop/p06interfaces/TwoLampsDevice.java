package it.unibo.apice.oop.p06interfaces;

public class TwoLampsDevice {

	/* Composizione immutabile di due Lamp! */
	private final Lamp l1;
	private final Lamp l2;

	/* Composizione inizializzata al momento della costruzione */
	public TwoLampsDevice() {
		this.l1 = new Lamp();
		this.l2 = new Lamp();
	}

	/* Metodi getter */
	public Lamp getFirst() {
		return this.l1;
	}

	public Lamp getSecond() {
		return this.l2;
	}

	/* Altri metodi */
	public void switchOnBoth() {
		this.l1.switchOn();
		this.l2.switchOn();
	}

	public void switchOffBoth() {
		this.l1.switchOff();
		this.l2.switchOff();
	}

	public void ecoMode() {
		this.l1.switchOff();
		this.l2.switchOn();
		this.l2.setIntensity(0.5);
	}
	
	
}
