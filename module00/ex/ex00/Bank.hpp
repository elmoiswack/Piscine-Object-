#pragma once

#include <iostream>
#include <vector>
#include "Account.hpp"

class Bank
{
	private:
		int liquidity;
		std::vector<Account *> clientAccounts;
		
		std::vector<Account *>::iterator findAccount(int id);
		int generateUniqueId();

	public:
		Bank();
		~Bank();

		void CreateAccount();
		void DeleteAccount(int id);
		
		void ModifyAccountValue(int id, int newValue);
		void RequestLoan(int id, int loanValue);

		friend std::ostream& operator<<(std::ostream &out, const Bank &in);
};

