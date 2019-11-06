#pragma once
#include "Monster.h"

class Dron : public Monster
{
public:
	Dron();
	~Dron();

	bool awake = false;

	float a = 0;

	void Start();
	void Update();
};

