#pragma once
#include "Monster.h"

class Monster1 : public Monster
{
public:
	Monster1();
	~Monster1();

	int shot_delay = 40;
	bool awake = false;

	void Start();
	void Update();
};

