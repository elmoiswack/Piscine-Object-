#pragma once

#include <iostream>
#include "Tool.hpp"

class Hammer : public Tool
{
	private:
		int numberOfUses;

	public:
		Hammer(int numberOfUses);
		Hammer(const Hammer &in);
		Hammer& operator=(const Hammer &in);
		~Hammer();

		void use() override;
};

