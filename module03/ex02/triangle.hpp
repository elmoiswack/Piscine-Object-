#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
private:
	double base;
	double leg;
	double hypotenuse;

public:
	Triangle(double base, double leg, double hypotenuse) {
		this->base = base;
		this->leg = leg;
		this->hypotenuse = hypotenuse;
	};
	~Triangle() {};

	double areaCalculation() override {
		return ((this->base * this->leg) / 2);
	};

	double perimeterCalculation() override {
		return (this->base + this->leg + this->hypotenuse);
	};
};




#endif