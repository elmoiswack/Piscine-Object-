#include "Hammer.hpp"

Hammer::Hammer(int numberOfUses)
{
	this->numberOfUses = numberOfUses;
}

Hammer::Hammer(const Hammer &in) {

	std::cout << "Copy constructor is called" << std::endl;
	*this = in;
}

Hammer& Hammer::operator=(const Hammer &in) {

	if (this == &in)
		return (*this);
	
	this->numberOfUses = in.numberOfUses;
	return (*this);
}

Hammer::~Hammer() {
	
	std::cout << "Hammer deconstructed" << std::endl;
}

void Hammer::use() {

	if (this->numberOfUses > 0)
	{
		std::cout << "Hammer is used to hammer" << std::endl;
		this->numberOfUses -= 1;
		return ;
	}

	std::cout << "This hammer can't be used anymore" << std::endl;
}