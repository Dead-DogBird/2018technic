#include "stdafx.h"
#include "JumpPt.h"


JumpPt::JumpPt()
{
}


JumpPt::~JumpPt()
{
}

void JumpPt::Start()
{
	texture_ex.texture = TextureManager::Get()->LoadTexture("Image/Jump.png");
	texture_size = { 0,0,100,100 };
	texture_ex.center = { 50,50 };
}

void JumpPt::Update()
{
	image_index += 0.18;
	if (image_index > 3)
		destroy = true;
}
