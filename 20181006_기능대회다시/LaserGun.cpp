#include "stdafx.h"
#include "LaserGun.h"
#include "Shot.h"
#include "Player.h"
#include "Aim.h"
#include "Pg.h"
#include "Monster.h"


LaserGun::LaserGun()
{
}


LaserGun::~LaserGun()
{
}

void LaserGun::Start()
{
	gun = TextureManager::Get()->LoadTexture("Image/LaserGun.png");
	texture_size = { 0,0,250,100 };
	texture_ex.center = {125,50 };
	collider_size = { 0,0,50,50 };

	

	laser = TextureManager::Get()->LoadTexture("Image/Laser.png");

}

void LaserGun::Update()
{
	/*if (GetAsyncKeyState(VK_LBUTTON))
		if (delay <= 0)
		{
			for (int i = 0; i < 5; i++)
			{
				GameObejct * inst = ObjectManager::Get()->CreateObject<Shot>();
				inst->x = x;
				inst->y = y;
				Shot * shot = (Shot *)inst;
				shot->texture_ex.image_angle = D3DXToDegree(atan2(y - Aim::me->y, x - Aim::me->x)) - 15 + i * 5;

				Player::me->wspeed += cos(D3DXToRadian(shot->texture_ex.image_angle)) * 6;
				Player::me->vspeed += sin(D3DXToRadian(shot->texture_ex.image_angle)) * 6;

				Camera::Get()->size = 1.4;
				Camera::Get()->rotation = -15;
			}



			delay = 30;
		}
	delay -= 1;
	*/
	if (Camera::Get()->size > 1)
	{
		Camera::Get()->size -= (Camera::Get()->size - 1) / 7;
	}

	Camera::Get()->rotation -= (Camera::Get()->rotation) / 7;
}

void LaserGun::Render()
{
	texture_ex.texture = gun;
	texture_ex.x = x;
	texture_ex.y = y;
	texture_ex.center = { 125,50 };
	texture_ex.texture_size = { 0,0,250,100 };
	//texture_ex.x = x;

	GrapicManager::Get()->TextureRender(texture_ex);

	if (GetAsyncKeyState(VK_LBUTTON))
	{
		
		Camera::Get()->rotation = -rand() % 2;
		Camera::Get()->size = 1.1;
		texture_ex.texture = laser;
		texture_ex.image_angle = D3DXToDegree(atan2(y - Aim::me->y, x - Aim::me->x));
		texture_ex.center = { 50,50 };
		texture_ex.texture_size = { 0,0,100,100 };

		Player::me->wspeed += cos(D3DXToRadian(texture_ex.image_angle)) * 1;
		Player::me->vspeed += sin(D3DXToRadian(texture_ex.image_angle)) * 1;

		for (int i = 1; i < 20; i++)
		{
			texture_ex.x = x - cos(D3DXToRadian(texture_ex.image_angle)) * i * 100 ;
			texture_ex.y = y - sin(D3DXToRadian(texture_ex.image_angle)) * i * 100;
			GrapicManager::Get()->TextureRender(texture_ex);

			Monster * monster = (Monster *)ObjectManager::Get()->CollidCheck(this, -cos(D3DXToRadian(texture_ex.image_angle)) * i * 100, -sin(D3DXToRadian(texture_ex.image_angle)) * i * 100, "Monster");

			if (monster != nullptr)
			{
				monster->hp-=0.4;
				Pg * p = ObjectManager::Get()->CreateObject<Pg>();
				p->x = x - cos(D3DXToRadian(texture_ex.image_angle)) * i * 100;
				p->y = y - sin(D3DXToRadian(texture_ex.image_angle)) * i * 100;
				Camera::Get()->size = 1.2;
				Camera::Get()->rotation = -rand() % 3;
				break;
			}

			if (ObjectManager::Get()->CollidCheck(this, -cos(D3DXToRadian(texture_ex.image_angle)) * i * 100, -sin(D3DXToRadian(texture_ex.image_angle)) * i * 100, "Block") != nullptr)
			{
				Pg * p = ObjectManager::Get()->CreateObject<Pg>();
				p->x = x - cos(D3DXToRadian(texture_ex.image_angle)) * i * 100;
				p->y = y - sin(D3DXToRadian(texture_ex.image_angle)) * i * 100;
				break;
			}

		}
		
		
		
	}
}
