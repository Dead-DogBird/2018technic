#pragma once
#include "Monster.h"

class EnemyShot : public GameObejct
{
public:
	EnemyShot();
	~EnemyShot();

	int destroy_time = 0;

	void Start();
	void Update();
};

