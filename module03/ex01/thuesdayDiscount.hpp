#ifndef THUESDAYDISCOUNT_HPP
# define THUESDAYDISCOUNT_HPP

#include "command.hpp"

class ThuesdayDiscount : public Command
{
private:

public:
	ThuesdayDiscount(
        std::string date,
        std::string client,
        std::vector<std::pair<Article, int>> articles
    ) : Command(date, client, articles) {};

	~ThuesdayDiscount() {};

	double get_total_price() {
		
		double total = Command::get_total_price();
		double discount = 0;

		if (this->date == "Tuesday")
			discount = total * 0.1;

		return (total - discount);
	}
};

#endif