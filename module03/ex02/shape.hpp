#ifndef SHAPE_HPP
# define SHAPE_HPP

class Shape
{
private:

public:
	Shape() {};
	virtual ~Shape() {};

	virtual double areaCalculation() = 0;
	virtual double perimeterCalculation() = 0;
};



#endif