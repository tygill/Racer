//	Class:		ObjectMan
//	Updated:	11/18/12
//	Project:	CS 455 Game - Racer
//
//	Acts as manager for all objects within the game.

#define ENLISTMENTS "models/models.enlistments"
#define MODELSPATH "models/"
#define GEOEXT ".obj"
#define TEXEXT ".bmp"

#include <fstream>
#include "../inc/main.h"
#include "../inc/ObjectMan.h"
#include "../inc/TextureMan.h"
#include "../lib/kixor_obj/objLoader.h"

ObjectMan* ObjectMan::instance = NULL;

ObjectMan::ObjectMan()
{
	LoadObjects();
}

void ObjectMan::LoadObjects()
{
	ifstream enlistments(ENLISTMENTS);
	
	if(!enlistments.is_open())
	{
		cout << "Bad models.enlistments file:" << endl
			<< "\tMake sure you have a models.enlistments file in your models "
			<< "directory that contains the names of each object. Leave off the "
			<< "file extension. Textures should have the same name." << endl;
		return;
	}

	cout << "Loading Objects:" << endl;

	while(enlistments.good())
	{
		string filename;
		getline(enlistments, filename);

		LoadObject(filename);
		LoadTexture(filename);
	}

	cout << "Loading Complete." << endl;
}

void ObjectMan::LoadObject(string name)
{
	objLoader* loader = new objLoader();
	string filename = MODELSPATH + name + GEOEXT;
	
	cout << "\t" << filename << "...";
	
	char* file = (char*)(filename).c_str();
	loader->load(file);

	obj_vector** verts = loader->vertexList;
	int num_v = loader->vertexCount;
	vector<Vec4> vertices;

	obj_vector** norms = loader->normalList;
	int num_n = loader->normalCount;
	vector<Vec4> normals;

	obj_vector** uvs = loader->textureList;
	int num_u = loader->textureCount;
	vector<Vec4> uv_points;

	obj_face** face_list = loader->faceList;
	int num_f = loader->faceCount;
	vector<Face> faces;

	for (int i = 0; i < num_v; i++)
	{
		obj_vector* cur = verts[i];
		Vec4 point((float)cur->e[0], (float)cur->e[1], (float)cur->e[2]);
		vertices.push_back(point);
	}

	for (int j = 0; j < num_n; j++)
	{
		obj_vector* cur = norms[j];
		Vec4 norm((float)cur->e[0], (float)cur->e[1], (float)cur->e[2]);
		normals.push_back(norm);
	}

	for (int k = 0; k < num_u; k++)
	{
		obj_vector* cur = uvs[k];
		Vec4 uv_point((float)cur->e[0], (float)cur->e[1], 0);
		uv_points.push_back(uv_point);
	}

	for (int m = 0; m < num_f; m++)
	{
		obj_face* cur = face_list[m];
		Face new_face;
		
		for (int n = 0; n < cur->vertex_count; n++)
		{
			new_face.vertices.push_back(vertices[cur->vertex_index[n]]);
			new_face.normals.push_back(normals[cur->normal_index[n]]);
			new_face.uvs.push_back(uv_points[cur->texture_index[n]]);
		}

		faces.push_back(new_face);
	}

	Geometry geo(name, vertices, normals, uv_points, faces);
	objects.push_back(geo);

	delete loader;

	cout << "DONE." << endl;
}

void ObjectMan::LoadTexture(string name)
{
	string tex = MODELSPATH + name + TEXEXT;
	cout << "\t" << tex << "...";
	GLuint texId;
	bool success = NeHeLoadBitmap(LPTSTR(tex.c_str()), texId);
	if(!success)
	{
		cout << "Unsuccessful" << endl;
		return;
	}
	TextureMan::GetInstance()->Add(name, texId);
	cout << "DONE." << endl;
}