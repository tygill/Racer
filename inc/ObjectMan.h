//	Class:		ObjectMan
//	Updated:	11/18/12
//	Project:	CS 455 Game - Racer
//
//	Acts as manager for all objects within the game.

#ifndef OBJECTMAN_H
#define OBJECTMAN_H

#include <iostream>
#include <vector>

#include "Geometry.h"

using namespace std;

class ObjectMan
{
private:
	static ObjectMan* instance;
	ObjectMan();
	~ObjectMan();
	void LoadObjects();
	Geometry* LoadObject(string id,
		string name,
		bool collidable,
		string parent_id);
	void LoadTexture(string id, string name);

public:
	vector<Geometry*> objects;
	vector<Geometry*> collidables;
	static ObjectMan* GetInstance()
	{
		if (instance == NULL)
		{
			instance = new ObjectMan();
		}
		return instance;
	}
};

#endif