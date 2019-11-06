#pragma once
#include "Button.h"

class ExitButton : public Button
{
public:
	ExitButton();
	~ExitButton();

	void Start();
	void LateUpdate();
	void Click();
};

