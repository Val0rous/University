package oop.lab03.shapes;

import oop.lab03.shapes.interfaces.Shape;

public class WorkWithShapes {

	protected static String printPerimeterAndArea(Shape shape) {
		return "Perimeter: " + shape.computePerimeter() +
				", Area: " + shape.computeArea();
	}
	
	public static void main(String[] args) {
		Circle circle = new Circle(10);
		Rectangle rectangle = new Rectangle(5, 4);
		Square square = new Square(3);
		Triangle triangle = new Triangle(3, 4, 5);
		
		System.out.println("[Circle]: " + printPerimeterAndArea(circle));
		System.out.println("[Rectangle]: " + printPerimeterAndArea(rectangle));
		System.out.println("[Square]: " + printPerimeterAndArea(square));
		System.out.println("[Triangle]: " + printPerimeterAndArea(triangle));
	}

}
