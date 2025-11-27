#include "Worker.hpp"

Worker::Worker(std::string name, Position coordinates, Statistic stats)
    : name(name),
      coordonnee(coordinates),
      stat(stats),
	  regesteredWorkshop({})
{
}

Worker::Worker(const Worker &in) {

	*this = in;
}

Worker& Worker::operator=(const Worker &in) {

	if (this == &in)
		return (*this);

	this->name = in.name;
	this->stat = in.stat;
	this->coordonnee = in.coordonnee;
	this->tools = in.tools;
	this->regesteredWorkshop = in.regesteredWorkshop;

	return *this;
}

Worker::~Worker() {
	
	for (auto it = this->regesteredWorkshop.begin(); it != this->regesteredWorkshop.end();)
	this->releaseFromWorkshop(*it);
	std::cout << "Worker deconstructed" << std::endl;
}

void Worker::takeTool(Tool* tool) {
	
	this->tools.emplace_back(tool);
	std::cout << "Worker: " << this->name << " has succesfully taken a tool" << std::endl;
}

void Worker::takeTool(Tool* tool, Worker &other) {

	this->tools.emplace_back(tool);
	for (auto it = other.tools.begin(); it != other.tools.end();)
	{
		if (*it == tool)
		{
			it = other.tools.erase(it);
			break ;
		}
		else
			++it;
	}
	std::cout << "Tool succesfully transfered from " << other.getName() << std::endl;
}

std::string Worker::getName() {
	return this->name;
}

Statistic Worker::getStats() {
	return this->stat;
}
		
Position Worker::getPosition() {
	return this->coordonnee;
}

void Worker::setStats(Statistic newStats) {
	this->stat = newStats;
}

void Worker::setPositions(Position newPosition) {
	this->coordonnee = newPosition;
}

void Worker::regesterToWorkshop(std::vector<Workshop*> workshop) {

	for (auto it = workshop.begin(); it != workshop.end(); it++)
	{
		this->regesteredWorkshop.emplace_back((*it));
		(*it)->registerWorker(this);
		std::cout << "Worker: " << this->name << " has succesfully registered to " << (*it)->getName() << std::endl;
	}
}

void Worker::releaseFromWorkshop(Workshop* workshop) {

	for (auto it = this->regesteredWorkshop.begin(); it != this->regesteredWorkshop.end(); it++)
	{
		if ((*it)->getName() == workshop->getName())
		{
			(*it)->releaseWorker(this);
			this->regesteredWorkshop.erase(it);
			std::cout << "Worker: " << this->name << " has succesfully been released from " << workshop->getName() << std::endl;
			return ;
		}
	}

	std::cout << "Worker is not regestered to Workshop" << std::endl;
}

void Worker::work(void) {

	if (this->regesteredWorkshop.size() == 0)
	{
		std::cout << "Worker: " << this->name << " is not registered to any Workshops, register before working" << std::endl;
		return ;
	}

	if (this->tools.size() == 0)
	{
		std::cout << "Worker: " << this->name << " has no tools to work with, grab some" << std::endl;
		return ;
	}

	for (auto itShops = this->regesteredWorkshop.begin(); itShops != this->regesteredWorkshop.end(); itShops++)
	{
		std::cout << "Worker "<< this->name <<" doing work at " << (*itShops)->getName() << std::endl;
		for (auto itTools = this->tools.begin(); itTools != this->tools.end(); itTools++)
			(*itTools)->use();
	}
}

void Worker::work(Workshop *workshop) {

	if (this->tools.size() == 0)
	{
		std::cout << "Worker: " << this->name << " has no tools to work with, grab some" << std::endl;
		return ;
	}

	std::cout << "Worker "<< this->name <<" doing work at " << workshop->getName() << std::endl;
	for (auto itTools = this->tools.begin(); itTools != this->tools.end(); itTools++)
		(*itTools)->use();
}

std::ostream& operator<<(std::ostream &out, Worker &in) {
	out << "Worker name = " << in.name;
	out << ", size of tools = " << in.tools.size();
	out << ", size of registered workshops = " << in.regesteredWorkshop.size() << std::endl; 

	return out;
}