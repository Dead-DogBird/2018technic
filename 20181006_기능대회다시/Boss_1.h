#pragma once
#include "Monster.h"
class Boss_1 : public Monster
{
public:
	Boss_1();
	~Boss_1();

	int shot_delay = 40;
	bool awake = false;

	void Start();
	void Update();
};

