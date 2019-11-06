#pragma once
#include "Button.h"
class StartButton : public Button
{
public:
	StartButton();
	~StartButton();

	void Start();
	void LateUpdate();
	void Click();
};

