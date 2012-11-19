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
	void LoadObject(string name);
	void LoadTexture(string name);

public:
	vector<Geometry> objects;
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