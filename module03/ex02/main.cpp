#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

#include <iostream>

int main(void)
{
	Shape* circle = new Circle(2.45);
	Shape* triangle = new Triangle(3, 4, 7);
	Shape *rectangle = new Rectangle(4, 6);

	std::cout << "Circle area = " << circle->areaCalculation() << ", perimeter = " << circle->perimeterCalculation() << std::endl;
	std::cout << "Triangle area = " << triangle->areaCalculation() << ", perimeter = " << triangle->perimeterCalculation() << std::endl;
	std::cout << "Rectangle area = " << rectangle->areaCalculation() << ", perimeter = " << rectangle->perimeterCalculation() << std::endl;

	delete circle;
	delete triangle;
	delete rectangle;
}