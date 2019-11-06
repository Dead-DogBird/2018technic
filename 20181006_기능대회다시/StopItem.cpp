#include "stdafx.h"
#include "StopItem.h"
#include "Player.h"

StopItem::StopItem()
{
}


StopItem::~StopItem()
{
}

void StopItem::Start()
{
	Player::me->stop = true;
}

void StopItem::Update()
{
	
	time++;
	if (time >= 200)
	{
		Player::me->stop = false;
		destroy = true;
	}
}
