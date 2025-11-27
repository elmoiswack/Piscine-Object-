#include "Workshop.hpp"

Workshop::Workshop() {

	this->name = "";
	this->workers = {};
}

Workshop::Workshop(std::string name)
{
	this->name = name;
	this->workers = {};
}

Workshop::Workshop(const Workshop &in) {
	
	std::cout << "Copy constructor called" << std::endl;
	*this = in;
}

Workshop& Workshop::operator=(const Workshop &in) {

	if (this == &in)
		return (*this);

	this->name = in.name;
	this->workers = in.workers;

	return (*this);
}

Workshop::~Workshop() {

	std::cout << "Workshop deconstructed" << std::endl;
	for (auto it = this->workers.begin(); it != this->workers.end(); it++)
		this->releaseWorker(*it);
}

void Workshop::registerWorker(Worker* worker) {

	this->workers.emplace_back(worker);
	std::cout << "Workshop: " << this->name << " has accepted worker " << worker->getName() << std::endl;
}

void Workshop::releaseWorker(Worker* worker) {

	for (auto it = this->workers.begin(); it != this->workers.end(); it++)
	{
		if ((*it)->getName() == worker->getName())
		{
			this->workers.erase(it);
			std::cout << "Workshop: " << this->name << " has released worker " << worker->getName() << std::endl;
			return ;
		}
	}

	std::cout << "Worker is not regestered to this Workshop" << std::endl;
}

void Workshop::executeWorkDay() {

	for (auto it = this->workers.begin(); it != this->workers.end(); it++)
		(*it)->work(this);
}

std::string Workshop::getName() {
	return this->name;
}

std::ostream& operator<<(std::ostream &out, Workshop &in) {
	out << "Workshop name = " << in.getName();
	out << ", size of workers = " << in.workers.size() << std::endl;

	return out;
}