#include "stdafx.h"
#include "ObjectManager.h"


ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::EUpdate()
{
	int i = 0;
	while (i < object_vector.size())
	{
		if (object_vector[i]->destroy == true)
		{
			delete object_vector[i];
			object_vector.erase(object_vector.begin() + i);

		}
		else
		{
			object_vector[i]->EUpdate();
			i++;
		}

	}
}

void ObjectManager::Update()
{
	int i = 0;
	while (i < object_vector.size())
	{
		if (object_vector[i]->destroy == true)
		{
			delete object_vector[i];
			object_vector.erase(object_vector.begin() + i);
			
		}
		else
		{
			object_vector[i]->Update();
			i++;
		}
		
	}
}

void ObjectManager::LateUpdate()
{
	int i = 0;
	while (i < object_vector.size())
	{
		if (object_vector[i]->destroy == false)
			object_vector[i]->LateUpdate();
		i++;
	}
}

void ObjectManager::Render()
{
	int i = 0;
	while (i < object_vector.size())
	{
		
		if (object_vector[i]->destroy == false)
			object_vector[i]->Render();
		i++;
	}
}

void ObjectManager::LateRender()
{
	int i = 0;
	while (i < object_vector.size())
	{

		if (object_vector[i]->destroy == false)
			object_vector[i]->LateRender();
		i++;
	}
}

void ObjectManager::MapRender()
{
	int i = 0;
	while (i < object_vector.size())
	{

		if (object_vector[i]->destroy == false)
			object_vector[i]->MiniMapRender();
		i++;
	}
}

void ObjectManager::Clear()
{
	int i = 0;
	while (i < object_vector.size())
	{
		if (object_vector[i]->dont_destroy != true)
			object_vector.erase(object_vector.begin()+i);
		else
			i++;
	}
}

GameObejct * ObjectManager::FindWithTag(string tag)
{
	int i = 0;
	while (i < object_vector.size())
	{
		if (object_vector[i]->tag == tag)
			return object_vector[i];
		i++;
	}
	return nullptr;
}

GameObejct * ObjectManager::CollidCheck(GameObejct * me, float move_x = 0, float move_y = 0,string tag = "")
{
	for (auto &other : object_vector)
	{
		if (other->tag == tag)
		if (other->collider_size.right != 0)
		if (other != me)
		if (
			me->x - me->texture_ex.center.x+ move_x + me->collider_size.left < other->x -other->texture_ex.center.x+ other->collider_size.right &&
			me->x - me->texture_ex.center.x + move_x + me->collider_size.right > other->x - other->texture_ex.center.x + other->collider_size.left &&
			me->y - me->texture_ex.center.y + move_y + me->collider_size.bottom > other->y - other->texture_ex.center.y + other->collider_size.top &&
			me->y - me->texture_ex.center.y + move_y + me->collider_size.top < other->y - other->texture_ex.center.y + other->collider_size.bottom
			)
		{
			return other;
		}
	}
	return nullptr;
}
