#pragma once

#include <iostream>

class Account
{
	private:
		int id;
		int value;

	protected:
		Account();
		Account(int id);

	public:
		virtual ~Account();

		friend std::ostream& operator<<(std::ostream &out, const Account &in);
	friend class Bank;
};

