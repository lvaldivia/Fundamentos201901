#pragma once
#include "Agent.h"
class Human : public Agent
{
public:
	Human();
	~Human();

	void update(const std::vector<std::string>& leveldata,
		std::vector<Human*> & humans,
		std::vector<Zombie*>& zombies);
};

