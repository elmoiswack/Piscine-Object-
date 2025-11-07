#include "Bank.hpp"

Bank::Bank() {

	std::cout << "Bank Constructor" << std::endl;
	this->liquidity = 0;
	this->clientAccounts = {};
}

Bank::~Bank() {

	std::cout << "Bank Deconstructor" << std::endl;
	this->liquidity = 0;
	for (auto account : this->clientAccounts)
	{
    	delete account;
	}
}

std::vector<Account *>::iterator Bank::findAccount(int id) {
	
	for (auto it = this->clientAccounts.begin(); it < this->clientAccounts.end(); it++)
	{
		if ((*it)->id == id)
			return (it);
	}

	return (this->clientAccounts.end());
}

int Bank::generateUniqueId() {
	for (int i = 0; i < INT32_MAX; i++) {
		if (findAccount(i) == this->clientAccounts.end())
			return (i);
	}
	return (-1);
}

void Bank::CreateAccount() {
	
	int uniqueId = this->generateUniqueId();
	if (uniqueId == -1)
	{
		std::cout << "Error failed to generate unique id\n" << std::endl;
		return ;
	}
	this->clientAccounts.emplace_back(new Account(uniqueId));
	std::cout << "Succesfully create new Account\n" << std::endl;
}

void Bank::DeleteAccount(int id) {

	auto it = this->findAccount(id);
	
	if (it == this->clientAccounts.end())
	{
		std::cout << "Error: Account not found\n" << std::endl;
		return ;
	}

	delete *it;
	this->clientAccounts.erase(it);
	std::cout << "Account with id: " << id << " succesfully deleted\n" << std::endl;
}

void Bank::ModifyAccountValue(int id, int money) {

	auto it = this->findAccount(id);
	
	if (it == this->clientAccounts.end())
	{
		std::cout << "Error: Account not found\n" << std::endl;
		return ;
	}

	int liquidityIncrease = 0;
	if (money > 0)
	{
		liquidityIncrease = (money * 0.05);
		this->liquidity += liquidityIncrease;
	}

	(*it)->value = (*it)->value + (money - liquidityIncrease);

	std::cout << "Account value is updated successfully\n" << std::endl;
}

void Bank::RequestLoan(int id, int loanValue) {
	
	if (this->liquidity <= loanValue)
	{
		std::cout << "Loan is to much for Bank to handle\n" << std::endl;
		return ;
	}

	auto it = this->findAccount(id);
	
	if (it == this->clientAccounts.end())
	{
		std::cout << "Error: Account not found\n" << std::endl;
		return ;
	}

	(*it)->value = (*it)->value + loanValue;
	this->liquidity -= loanValue;

	std::cout << "Succesfully Requested a loan\n" << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Bank &in) {

	out << "Bank informations : " << std::endl;
	out << "Liquidity : " << in.liquidity << std::endl;
	for (auto &clientAccount : in.clientAccounts)
    	out << *clientAccount << std::endl;
	return (out);
}