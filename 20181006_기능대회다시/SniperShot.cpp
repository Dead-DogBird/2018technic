#include "stdafx.h"
#include "SniperShot.h"
#include "Aim.h"
#include "Monster.h"
#include "Player.h"
#include "Pg.h"

SniperShot::SniperShot()
{
}


SniperShot::~SniperShot()
{
}

void SniperShot::Start()
{

	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/SniperShot.png");
	texture_size = { 0,0,300,100 }; //{ 0,0,1000,100 };
	texture_ex.center = { 150,50 }; //{ 0,50 }

	collider_size = { 0,0,40,40 };
	texture_ex.image_xscale = 2.2;
	texture_ex.image_yscale = 0.5;

	
}

void SniperShot::Update()
{
	//x = Player::me->x;
	//y = Player::me->y;
	x -= cos(D3DXToRadian(texture_ex.image_angle)) * 80;
	y -= sin(D3DXToRadian(texture_ex.image_angle)) * 80;

	//texture_ex.image_angle = D3DXToDegree(atan2(y - Player::me->y, x - Player::me->x));//

	destroy_time++;


	if (destroy_time > 100)
	{
		destroy = true;

	}


	Monster * inst = (Monster *)ObjectManager::Get()->CollidCheck(this, 0, 0, "Monster");

	if (inst != nullptr)
	{
		inst->hp-=15;
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
