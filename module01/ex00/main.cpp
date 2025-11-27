#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"


int main() {

	Position position = {1, 1, 1};
	Statistic stats = {5, 20};
	Worker* lad = new Worker("lad", position, stats);

	Position otherPos = {3, 6, 2};
	Statistic otherStats = {1, 60};
	Worker* chad = new Worker("Chad", otherPos, otherStats);

	Tool* shovelTool = new Shovel(3);
	Tool* hammerTool = new Hammer(5);

	Workshop* ah = new Workshop("Albert Heijn");
	Workshop* dirk = new Workshop("Dirk");
	
	std::vector<Workshop*> workshops = {ah, dirk};

	lad->takeTool(shovelTool);

	std::cout << *lad << std::endl;

	lad->work();

	std::cout << std::endl;

	chad->regesterToWorkshop(workshops);

	std::cout << *chad << std::endl;

	chad->work();

	std::cout << std::endl;

	chad->takeTool(hammerTool);

	std::cout << *chad << std::endl;

	chad->work();

	std::cout << std::endl;

	lad->regesterToWorkshop(workshops);

	std::cout << std::endl;
	std::cout << *ah << std::endl;
	std::cout << *dirk << std::endl;

	ah->executeWorkDay();

	std::cout << std::endl;

	lad->releaseFromWorkshop(dirk);

	std::cout << std::endl;
	std::cout << *ah << std::endl;
	std::cout << *dirk << std::endl;

	ah->executeWorkDay();
	dirk->executeWorkDay();

	std::cout << std::endl << *lad << std::endl;

	lad->takeTool(hammerTool, *chad);

	std::cout << std::endl;
	std::cout << *lad << std::endl;
	std::cout << *chad << std::endl;

	ah->executeWorkDay();
	dirk->executeWorkDay();

	std::cout << *chad << std::endl;

	chad->takeTool(hammerTool, *lad);

	std::cout << *chad << std::endl;

	delete lad;

	std::cout << *chad << std::endl;

	chad->takeTool(shovelTool);

	std::cout << *chad << std::endl;

	std::cout << *ah << std::endl;
	std::cout << *dirk << std::endl;
	
	chad->releaseFromWorkshop(ah);

	std::cout << *ah << std::endl;
	std::cout << *dirk << std::endl;

	ah->executeWorkDay();
	dirk->executeWorkDay();

	std::cout << *ah << std::endl;
	std::cout << *dirk << std::endl;

	delete chad;
	delete ah;
	delete dirk;
	delete shovelTool;
	delete hammerTool;
}