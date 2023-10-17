package oop.lab03.shapes;

import oop.lab03.shapes.interfaces.Polygon;

public class Rectangle implements Polygon {

	private final double base;
	private final double height;
	
	public Rectangle(final double base, final double height) {
		this.base = base;
		this.height = height;
	}
	
	@Override
	public double computePerimeter() {
		return (2 * (this.base + this.height));
	}

	@Override
	public double computeArea() {
		return (this.base * this.height);
	}

	@Override
	public int getEdgeCount() {
		return 4;
	}

	@Override
	public boolean isRegular() {
		//it's only regular if it's actually a square
		if(this.base == this.height) {
			return true;
		}
		return false;
	}
	
	public double getBase() {
		return this.base;
	}
	
	public double getHeight() {
		return this.height;
	}

}
