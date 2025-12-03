#ifndef CIRLE_HPP
# define CIRLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
private:
	double radius;

public:
	Circle(double radius) { this->radius = radius; };
	~Circle() {};

	double areaCalculation() override {
		return (3.14 * (this->radius * this->radius));
	};

	double perimeterCalculation() override {
		return (2 * 3.14 * this->radius);
	
	};
};


#endif