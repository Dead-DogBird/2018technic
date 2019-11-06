#pragma once
template <class T>
class Singleton
{
private:
	static T* me;
public:
	Singleton()
	{

	};
	~Singleton()
	{

	};

	static T* Get()
	{
		if (me == NULL)
		{
			me = new T;
		}
		return me;
	}

};

template <class T> T* Singleton<T>::me = NULL;