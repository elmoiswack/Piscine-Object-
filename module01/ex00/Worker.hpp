#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "Shovel.hpp"
#include "Workshop.hpp"

class Workshop;

struct Statistic
{
	int level;
	int exp;
};

struct Position
{
	int x;
	int y;
	int z;
};

class Worker
{
	private:
		std::string name;
		Position coordonnee;
		Statistic stat;
		std::vector<Tool*> tools;
		std::vector<Workshop*> regesteredWorkshop;
	
	public:
		Worker(std::string name, Position coordinates, Statistic stats);
		Worker(const Worker &in);
		Worker& operator=(const Worker &in);
		~Worker();

		void takeTool(Tool* tool);
		void takeTool(Tool* tool, Worker &other);

		std::string getName();
		Statistic getStats();
		Position getPosition();

		void setStats(Statistic newStats);
		void setPositions(Position newPosition);

		void regesterToWorkshop(std::vector<Workshop*> workshop);
		void releaseFromWorkshop(Workshop* workshop);

		void work(void);
		void work(Workshop *workshop);

		friend std::ostream& operator<<(std::ostream &out, Worker &in);

};

