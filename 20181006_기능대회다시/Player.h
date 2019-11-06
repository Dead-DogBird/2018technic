#pragma once
#include "Gun.h"
#include "LaserGun.h"
class Gun;

class Player : public GameObejct
{
public:
	Player();
	~Player();

	static Player * me;

	int hp = 5;
	float more_jump = -10;

	int time = 7200;
	int gun_num = 0;

	bool stop = false;

	int item_delay = 0;
	

	bool clear = false;

	int heal_delay = 0;

	GameObejct * gun;

	int delay = 0;
	bool is_ground = false;

	float a = 0;
	int dire = 1;

	int damage_time = 0;

	float vspeed = 0;
	float gravity = 1;
	float wspeed = 0;

	void Start();
	void Update();

};

