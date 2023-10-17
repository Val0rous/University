package oop.lab03.shapes;

import oop.lab03.shapes.interfaces.Polygon;

import java.lang.Math;

public class Triangle implements Polygon {

	private final double side1;
	private final double side2;
	private final double side3;
	
	public Triangle(final double side1, final double side2, final double side3) {
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
	}
	
	@Override
	public double computePerimeter() {
		return (side1 + side2 + side3);
	}
	
	public double computeSemiPerimeter() {
		return (this.computePerimeter()/2);
	}

	@Override
	public double computeArea() {
		double s = this.computeSemiPerimeter();
		return (Math.sqrt(s * (s - this.side1) * (s - this.side2) * (s - this.side3)));
	}

	@Override
	public int getEdgeCount() {
		return 3;
	}

	@Override
	public boolean isRegular() {
		return ((this.side1 == this.side2) && (this.side1 == this.side3));
	}

}
