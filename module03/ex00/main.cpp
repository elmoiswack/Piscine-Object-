#include "Car.hpp"


int main(void) {

	Car audi = Car();

	std::cout << audi << std::endl;

	audi.start();

	std::cout << audi << std::endl;

	audi.accelerate(24.61);
	
	std::cout << audi << std::endl;
	
	audi.reverse();

	std::cout << audi << std::endl;

	audi.shift_gears_up();
	audi.shift_gears_up();

	std::cout << audi << std::endl;

	audi.shift_gears_down();

	std::cout << audi << std::endl;

	audi.turn_wheel(35.32);

	std::cout << audi << std::endl;

	audi.turn_wheel(82);

	std::cout << audi << std::endl;

	audi.turn_wheel(82);

	std::cout << audi << std::endl;

	audi.straighten_wheels();

	std::cout << audi << std::endl;

	audi.apply_force_on_brakes(28.2);

	std::cout << audi << std::endl;

	audi.apply_force_on_brakes(218.2);

	std::cout << audi << std::endl;

	audi.apply_force_on_brakes(8.2);

	std::cout << audi << std::endl;

	audi.apply_emergency_brakes();

	std::cout << audi << std::endl;

	audi.stop();

	std::cout << audi << std::endl;
}