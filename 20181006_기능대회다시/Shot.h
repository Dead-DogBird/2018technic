#pragma once
class Shot : public GameObejct
{
public:
	Shot();
	~Shot();

	int destroy_time = 0;

	void Start();
	void Update();

};

