package oop.lab03.shapes;

import oop.lab03.shapes.interfaces.Polygon;

public class Square implements Polygon {

	private final double side;
	
	public Square(final double side) {
		this.side = side;
	}
	
	@Override
	public double computePerimeter() {
		return (4 * this.side);
	}

	@Override
	public double computeArea() {
		return (this.side * this.side);
	}

	@Override
	public int getEdgeCount() {
		return 4;
	}

	@Override
	public boolean isRegular() {
		return true;
	}

	public double getSide() {
		return this.side;
	}
	
}
