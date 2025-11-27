#pragma once

#include <iostream>
#include "Tool.hpp"

class Shovel : public Tool
{
	private:
		int numberOfUses;

	public:
		Shovel(int numberOfUses);
		Shovel(const Shovel &in);
		Shovel& operator=(const Shovel &in);
		~Shovel();

		void use() override;
};

