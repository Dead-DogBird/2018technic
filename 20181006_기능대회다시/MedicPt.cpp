#include "stdafx.h"
#include "MedicPt.h"


MedicPt::MedicPt()
{
}


MedicPt::~MedicPt()
{
}

void MedicPt::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Heal.png");
	texture_size = { 0,0,1920,1080 };
	texture_ex.center = { 0,0 };
	texture_ex.camera_on = false;
}

void MedicPt::Update()
{
	alpha -= 3;
	if (alpha <= 0)
	{
		destroy = true;
	}
	texture_ex.image_blend = D3DCOLOR_ARGB(alpha, 255, 255, 255);
}
