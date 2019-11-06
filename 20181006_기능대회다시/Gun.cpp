#include "stdafx.h"
#include "Gun.h"
#include "Shot.h"
#include "Aim.h"
#include "Player.h"


Gun::Gun()
{
}


Gun::~Gun()
{
}

void Gun::Update()
{
	if (GetAsyncKeyState(VK_LBUTTON))
		if (delay <= 0)
		{
			for (int i = 0; i < 5; i++)
			{
				GameObejct * inst = ObjectManager::Get()->CreateObject<Shot>();
				inst->x = x;
				inst->y = y;
				Shot * shot = (Shot *)inst;
				shot->texture_ex.image_angle = D3DXToDegree(atan2(y - Aim::me->y, x - Aim::me->x)) - 15 + i * 5;

				Player::me->wspeed += cos(D3DXToRadian(shot->texture_ex.image_angle)) *6;
				Player::me->vspeed += sin(D3DXToRadian(shot->texture_ex.image_angle)) *6;

				Camera::Get()->size = 1.4;
				Camera::Get()->rotation = -15;
			}
			


			delay = 30;
		}
	delay -= 1;

	if (Camera::Get()->size > 1)
	{
		Camera::Get()->size -= (Camera::Get()->size - 1) / 7;
	}

	Camera::Get()->rotation -= (Camera::Get()->rotation) / 7;

}

void Gun::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Gun.png");
	texture_size = { 0,0,200,100 };
	texture_ex.center = { 91,51 };

	

	//collider_size = { 0,0,150,75 };
}
