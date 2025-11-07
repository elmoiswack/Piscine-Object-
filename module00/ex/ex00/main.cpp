#include <iostream>
#include "Account.hpp"
#include "Bank.hpp"


int main(void)
{

	Bank bank = Bank();
	// Account* account = new Account();
	// Account* account = new Account(2);
	
	bank.CreateAccount();

	//should see a single account
	std::cout << bank << std::endl;

	//should display error message that account doesn't exist
	bank.ModifyAccountValue(1, 20); 

	//nothing changed
	std::cout << bank << std::endl;

	//should succeed
	bank.ModifyAccountValue(0, 20); 
	
	//you should see 5% of 20 in bank.liquidity and the remainder in Account
	std::cout << bank << std::endl; 

	bank.ModifyAccountValue(0, -20);

	//should display that Account value is < 0 and bank remains the same
	std::cout << bank << std::endl;

	bank.ModifyAccountValue(0, 200);

	std::cout << bank << std::endl;

	//should desplay error since bank liquidity is not higher then 300
	bank.RequestLoan(0, 300);

	//should succeed
	bank.RequestLoan(0, 3);

	//Account value should go up by 3
	std::cout << bank << std::endl;

	bank.CreateAccount();

	//should see two Accounts
	std::cout << bank << std::endl;

	bank.CreateAccount();
	
	//should see three accounts
	std::cout << bank << std::endl;

	bank.ModifyAccountValue(2, 20); 

	//should increase only Account 2 and the liquidity of the Bank
	std::cout << bank << std::endl;

	bank.DeleteAccount(1);

	//Should see that only Account with id 2 remains
	std::cout << bank << std::endl;

	bank.CreateAccount();

	//shoud see that Accounts have different id's
	std::cout << bank << std::endl;

	bank.CreateAccount();

	//shoud see that Accounts have different id's
	std::cout << bank << std::endl;
}