#pragma once
#include "Monster.h"

class Monster2  : public Monster
{
public:
	Monster2();
	~Monster2();

	bool awake = false;

	void Start();
	void Update();
};

