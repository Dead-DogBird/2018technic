#pragma once
#include "Button.h"

class MenuButton : public Button
{
public:
	MenuButton();
	~MenuButton();

	int delay = 0;

	void Start();
	void LateUpdate();
	void Click();
};

