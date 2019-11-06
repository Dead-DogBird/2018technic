#pragma once

using namespace std;

template <class T>
class Singleton;

class ObjectManager : public Singleton<ObjectManager>
{
private:
	vector<GameObejct*> object_vector;
public:
	ObjectManager();
	~ObjectManager();

	template <class T>
	T* CreateObject()
	{
		T* inst = new T;
		GameObejct * object = inst;
		object_vector.push_back(object);

		object->Start();

		return inst;
	}

	void EUpdate();
	void Update();
	void LateUpdate();
	void Render();
	void LateRender();
	void MapRender();
	void Clear();
	GameObejct * FindWithTag(string tag);
	GameObejct * CollidCheck(GameObejct * me, float move_x, float move_y,string tag);


};

