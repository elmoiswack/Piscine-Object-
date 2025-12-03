#ifndef PACKAGEREDUCTIONDISCOUNT_HPP
# define PACKAGEREDUCTIONDISCOUNT_HPP

#include "command.hpp"

class PackageReductionDiscount : public Command
{
private:
	
public:
	PackageReductionDiscount(
		std::string date,
        std::string client,
        std::vector<std::pair<Article, int>> articles
    ) : Command(date, client, articles) {};

	~PackageReductionDiscount() {};
	
	double get_total_price() {
		
		double total = Command::get_total_price();

		if (total > 150)
			total -= 10;

		return total;
	}
};

#endif
