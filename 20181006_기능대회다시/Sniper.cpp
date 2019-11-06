#include "stdafx.h"
#include "Sniper.h"
#include "Aim.h"
#include "Player.h"
#include "SniperShot.h"

Sniper::Sniper()
{
}


Sniper::~Sniper()
{
}

void Sniper::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Sniper.png");
	texture_size = { 0,0,300,100 };
	texture_ex.center = { 150,50 };
}

void Sniper::Update()
{
	if (GetAsyncKeyState(VK_LBUTTON))
		if (delay <= 0)
		{
			for (int i = 0; i < 1; i++)
			{
				GameObejct * inst = ObjectManager::Get()->CreateObject<SniperShot>();
				inst->x = x;
				inst->y = y;
				SniperShot * shot = (SniperShot *)inst;
				shot->texture_ex.image_angle = D3DXToDegree(atan2(y - Aim::me->y, x - Aim::me->x)) ;

				Player::me->wspeed += cos(D3DXToRadian(shot->texture_ex.image_angle)) * 80;
				Player::me->vspeed += sin(D3DXToRadian(shot->texture_ex.image_angle)) * 80;

				Camera::Get()->size = 1.5;
				//Camera::Get()->rotation = -30;
			}



			delay = 70;
		}
	delay -= 1;

	if (Camera::Get()->size > 1)
	{
		Camera::Get()->size -= (Camera::Get()->size - 1) / 7;
	}

	Camera::Get()->rotation -= (Camera::Get()->rotation) / 7;

}
