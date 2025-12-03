#ifndef COMMAND_HPP
# define COMMAND_HPP

#include <iostream>
#include <vector>

struct Article {
	std::string name;
	double amount;
};

class Command
{
protected:
	int id;
	std::string date;
	std::string client;
	std::vector<std::pair<Article, int>> articles;
	
public:
	static int lastUsedId;

	Command(std::string date, std::string client, std::vector<std::pair<Article, int>> articles) {
		this->date = date;
		this->client = client;
		this->articles = articles;
		this->id = lastUsedId + 1;
		this->lastUsedId += 1;
	}
	virtual ~Command() { };


	double get_total_price() {
		
		double total = 0;
		for (auto it = this->articles.begin(); it != this->articles.end(); it++)
		{
			for (int i = 0; i < it->second; i++)
				total += it->first.amount;
		}

		return total;
	};
};

int Command::lastUsedId = 0;

#endif