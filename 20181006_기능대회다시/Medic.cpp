#include "stdafx.h"
#include "Medic.h"


Medic::Medic()
{
}


Medic::~Medic()
{
}

void Medic::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Medic.png");
	texture_size = { 0,0,300,300 }; //{ 0,0,1000,100 };
	texture_ex.center = { 150,150 }; //{ 0,50 }

	tag = "Medic";

	collider_size = { 0,0,300,300 };
}

void Medic::Update()
{
	a += 0.08;
	texture_ex.image_xscale = 1 + sin(a) * 0.05;
	texture_ex.image_yscale = 1 - sin(a) * 0.03;
	y = 200 + sin(a) * 7;
	//texture_ex.y = y
}
