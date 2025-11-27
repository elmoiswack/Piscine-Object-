#pragma once

#include <iostream>
#include <list>
#include "Worker.hpp"

class Worker;

class Workshop
{
	private:
		std::string name;
		std::list<Worker*> workers;

	public:
		Workshop();
		Workshop(std::string name);
		Workshop(const Workshop &in);
		Workshop& operator=(const Workshop &in);
		~Workshop();

		void registerWorker(Worker* worker);
		void releaseWorker(Worker* worker);

		void executeWorkDay();

		std::string getName();
		friend std::ostream& operator<<(std::ostream &out, Workshop &in);
};

