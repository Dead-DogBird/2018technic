#include "stdafx.h"
#include "HpUI.h"

#include "Player.h"
HpUI::HpUI()
{
}


HpUI::~HpUI()
{
}

void HpUI::Start()
{
	hp = TextureManager::Get()->LoadTexture("Image/Hp.png");
	hpout = TextureManager::Get()->LoadTexture("Image/HpOut.png");
	texture_size = { 0,0,118,118 };
	texture_ex.center = { 60,60 };
	texture_ex.camera_on = false;
}

void HpUI::Render()
{
	a += 0.1;
	for (int i = 1;i < 6; i++)
	{
		if (Player::me->hp >= i)
			texture_ex.texture = hp;
		else
			texture_ex.texture = hpout;
		texture_ex.x = 120 * i;
		texture_ex.y = 1000;
		texture_ex.texture_size = { texture_size.right * (int)image_index,texture_size.top,texture_size.right * (int)image_index + texture_size.right,texture_size.bottom };
		//texture_ex.x = x;

		//texture_ex.image_xscale = 1 + sin(a + i) * 0.1;
		texture_ex.y += 1 + cos(a + i) * 10;

		GrapicManager::Get()->TextureRender(texture_ex);
	}
	
}
