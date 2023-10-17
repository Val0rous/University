package oop.lab03.shapes;

import oop.lab03.shapes.interfaces.Shape;

import java.lang.Math;

public class Circle implements Shape {

	private final double radius;
	
	public Circle(double radius) {
		this.radius = radius;
	}
	
	public double getRadius() {
		return this.radius;
	}
	
	public double getDiameter() {
		return (2 * this.radius);
	}
	
	@Override
	public double computePerimeter() {
		return (2 * Math.PI * this.radius);
	}

	@Override
	public double computeArea() {
		return (Math.PI * (this.radius * this.radius));
	}

}
