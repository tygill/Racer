//	Class:		Geometry
//	Author:		Morgan Strong
//	Updated:	11/15/12
//	Project:	CS 455 Game - Racer
//
//	Representative of a Non-Deformable 3D object. Generally a container class
//	with built-in space for dynamic transforms (physics simulation, user input,
//	etc.)  Color, Texture, and other data should be stored outside this class.
//	This class is built generally, but particularly friendly to openGL.

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <map>
#include <string>
#include <vector>
#include "Vec4.h"
#include "KineticState.h"
using namespace std;

class Geometry{
private:
	// Members
	string id;
	vector<Vec4> vertices;
	vector<Vec4> normals;
	vector<Vec4> uvs;
	map<int,vector<Vec4*> point_groups;
	Vec4 scale;
	Vec4 rotate;
	Vec4 translate;
	KineticState dynamic_transforms;

public:
	// Constructors
	Geometry();
	Geometry(const Geometry& other);
	~Geometry();

	Geometry(string new_id,
		int num_v = 0, float** vertices = NULL,
		int num_n = 0, float** normals = NULL,
		int num_u = 0, float** uvs = NULL);
	
	// Instance Methods

};

#endif