#include "Shovel.hpp"

Shovel::Shovel(int numberOfUses) {

	this->numberOfUses = numberOfUses;
}

Shovel::Shovel(const Shovel &in) {

	std::cout << "Copy constructor is called" << std::endl;
	*this = in;
}

Shovel& Shovel::operator=(const Shovel &in) {

	if (this == &in)
		return (*this);
	
	this->numberOfUses = in.numberOfUses;
	return (*this);
}

Shovel::~Shovel() {

	std::cout << "Shovel deconstructed" << std::endl;
}

void Shovel::use() {
	
	if (this->numberOfUses > 0)
	{
		std::cout << "Shovel is used to dig" << std::endl;
		this->numberOfUses -= 1;
		return ;
	}

	std::cout << "This shovel can't be used anymore" << std::endl;
}