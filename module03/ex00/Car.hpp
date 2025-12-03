#include <iostream>
#include "Engine.hpp"
#include "GasPedal.hpp"
#include "Gears.hpp"
#include "Wheels.hpp"
#include "BrakePedal.hpp"


class Car: public Engine, public GasPedal, public Gears, public Wheels, public BrakePedal
{
	public:
		Car() {};
		~Car() {};

	friend std::ostream& operator<<(std::ostream &out, Car &in) {
		out << "engine running = " << in.getIsActive() << std::endl;
		out << "current speed = " << in.getSpeed() << std::endl;
		out << "current gear = " << in.getGear() << std::endl;
		out << "current angle = " << in.getAngle() << std::endl;
		out << "current force = " << in.getForce() << std::endl;
		return out;
	}
};
