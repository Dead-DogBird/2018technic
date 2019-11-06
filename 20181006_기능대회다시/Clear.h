#pragma once
class Clear : public GameObejct
{
public:
	Clear();
	~Clear();

	bool fail = false;

	void Start();
	void EUpdate();
};

