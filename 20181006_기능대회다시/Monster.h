#pragma once
class Monster : public GameObejct
{
public:
	Monster();
	~Monster();

	float hp;
	float vspeed = 0;
	float gravity = 1.7;
	float wspeed = 0;

	bool is_ground = false;

};

