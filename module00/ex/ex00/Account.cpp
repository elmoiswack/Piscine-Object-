#include "Account.hpp"

Account::Account() {

	std::cout << "Account default constructor is called" << std::endl;
}

Account::Account(int id) {

	std::cout << "Creating new account with id: " << id << std::endl;
	this->id = id;
	this->value = 0;
}

Account::~Account() {

	std::cout << "Deleting account with id: " << id << std::endl;
	this->id = 0;
	this->value = 0;
}

std::ostream& operator<<(std::ostream &out, const Account &in)
{
	out << "Account:" << std::endl;
	out << "Id = " << in.id << std::endl;
	out << "value = " << in.value << std::endl;
	return (out);
}