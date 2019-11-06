#pragma once
#include "Monster.h"


class SniperShot : public GameObejct
{
public:
	SniperShot();
	~SniperShot();

	int destroy_time = 0;

	void Start();
	void Update();
};

