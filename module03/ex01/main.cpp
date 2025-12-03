#include "command.hpp"
#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"

int main(void)
{
	const Article articleOne = {"Sweatpants", 40.49}; 
	const Article articleTwo = {"Hoodie", 69.99}; 
	const Article articleThree = {"Shoes", 20.00}; 

	std::pair<Article, int> pairOne = {articleOne, 1}; //total = 40.49
	std::pair<Article, int> pairTwo = {articleTwo, 2}; //total = 139.98
	std::pair<Article, int> pairThree = {articleThree, 3}; //total = 60
	//all together should be 239.98

	std::vector<std::pair<Article, int>> winkelMandje = {pairOne, pairTwo, pairThree};

	Command command = Command("Monday", "Herman", winkelMandje);
	std::cout << "Command: " << command.get_total_price() << std::endl;

	ThuesdayDiscount thuesdaydiscount = ThuesdayDiscount("Tuesday", "Herman", winkelMandje);
	std::cout << "ThuesdayDiscount: " << thuesdaydiscount.get_total_price() << std::endl;

	PackageReductionDiscount package = PackageReductionDiscount("Wednesday", "Herman", winkelMandje);
	std::cout << "PackageReductionDiscount: " << package.get_total_price() << std::endl;

}