#pragma once
class Gun : public GameObejct
{
public:
	Gun();
	~Gun();

	int delay = 0;

	void Update();
	void Start();

};

