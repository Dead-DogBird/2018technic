#include "stdafx.h"
#include "Shot.h"
#include "Aim.h"
#include "Monster.h"
#include "Player.h"
#include "Pg.h"
using namespace std;

Shot::Shot()
{
}


Shot::~Shot()
{
}

void Shot::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Shot.png");
	texture_size ={ 0,0,221,41 }; //{ 0,0,1000,100 };
	texture_ex.center = { 110,20}; //{ 0,50 }

	collider_size = { 0,0,40,40 };
	

	
}

void Shot::Update()
{
	//x = Player::me->x;
	//y = Player::me->y;
	x -= cos(D3DXToRadian(texture_ex.image_angle)) * 80;
	y -= sin(D3DXToRadian(texture_ex.image_angle)) * 80;

	destroy_time++;
	

	if (destroy_time > 100)
	{
		destroy = true;
		
	}
		

	Monster * inst = (Monster *)ObjectManager::Get()->CollidCheck(this, 0, 0, "Monster");

	if (inst != nullptr)
	{
		inst->hp--;
		Pg * p = ObjectManager::Get()->CreateObject<Pg>();
		p->x = x;
		p->y = y;

		if (Player::me->x > inst->x)
			inst->wspeed = -20;
		else
			inst->wspeed = 20;
		//inst->wspeed += cos(D3DXToRadian(texture_ex.image_angle)) * 30;
		//inst->vspeed += sin(D3DXToRadian(texture_ex.image_angle)) * 70;
		destroy = true;
	}

	if (ObjectManager::Get()->CollidCheck(this, 0, 0, "Block"))
	{

		Pg * p = ObjectManager::Get()->CreateObject<Pg>();
		p->x = x;
		p->y = y;
		destroy = true;
	}


		
}
