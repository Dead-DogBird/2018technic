#pragma once
class StopItem : public GameObejct 
{
public:
	StopItem();
	~StopItem();

	int time = 0;

	void Start();
	void Update();
};

