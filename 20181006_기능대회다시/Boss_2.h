#pragma once
#include "Monster.h"


class Boss_2 : public Monster
{
public:
	Boss_2();
	~Boss_2();

	int shot_delay = 40;
	bool awake = false;

	float a = 0;

	void Start();
	void Update();
};

