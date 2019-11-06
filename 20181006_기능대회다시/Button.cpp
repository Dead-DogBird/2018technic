#include "stdafx.h"
#include "Button.h"
#include "Aim.h"


Button::Button()
{
}


Button::~Button()
{
}

void Button::Update()
{
	if (
		Aim::me->x > x - texture_ex.center.x + collider_size.left &&
		Aim::me->x < x - texture_ex.center.x + collider_size.right &&
		Aim::me->y < y - texture_ex.center.y + collider_size.bottom &&
		Aim::me->y > y - texture_ex.center.y + collider_size.top)
	{

		if (GetAsyncKeyState(VK_LBUTTON))
		{
			Click();
		}

		if (texture_ex.image_xscale < 1.6)
		{
			texture_ex.image_xscale += (1.6 - texture_ex.image_xscale) / 8;
		}

		if (texture_ex.image_yscale > 0.8)
		{
			texture_ex.image_yscale += (0.8 - texture_ex.image_yscale) / 8;
		}
	}
	else
	{
		if (texture_ex.image_xscale > 1)
		{
			texture_ex.image_xscale += (1 - texture_ex.image_xscale) / 8;
		}

		if (texture_ex.image_yscale < 1)
		{
			texture_ex.image_yscale += (1 - texture_ex.image_yscale) / 8;
		}
	}

}

void Button::Click()
{
}
