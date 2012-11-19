//	Class:		Geometry
//	Updated:	11/15/12
//	Project:	CS 455 Game - Racer
//
//	Representative of a Non-Deformable 3D object. Generally a container class
//	with built-in space for dynamic transforms (physics simulation, user input,
//	etc.)  Color, Texture, and other data should be stored outside this class.
//	This class is built generally, but particularly friendly to openGL.

#include "../inc/Geometry.h"
#include "../inc/TextureMan.h"

//Only for windows
#ifdef WIN32
#include <Windows.h>
#include <MMSystem.h>
#endif // WIN32

// For all operating systems
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

Geometry::Geometry()
{

}

Geometry::Geometry(const Geometry& other)
{
	id = other.id;
	vertices = other.vertices;
	normals = other.normals;
	uvs = other.uvs;
	faces = other.faces;
	point_groups = other.point_groups;
	// TODO: Figured this out
	//scale = other.scale;
	//rotate = other.rotate;
	//translate = other.translate;
	dynamic_transforms = other.dynamic_transforms;
}

Geometry::~Geometry()
{

}

Geometry::Geometry(string new_id,
		vector<Vec4> _verts,
		vector<Vec4> _norms,
		vector<Vec4> _uvs,
		vector<Face> _faces)
{
	id = new_id;
	vertices = _verts;
	normals = _norms;
	uvs = _uvs;
	faces = _faces;
}

void Geometry::Draw()
{
	GLuint texid = TextureMan::GetInstance()->Get(id);
	glBindTexture(GL_TEXTURE_2D, texid);
	glBegin(GL_TRIANGLES);
	
	for(int f = 0; f < faces.size(); f++)
	{
		Face face = faces[f];

		for(int v = 0; v < face.vertices.size(); v++)
		{
			glNormal3f(face.normals[v][0],
				face.normals[v][1],
				face.normals[v][2]);
			glTexCoord2f(face.uvs[v][0],
				face.uvs[v][1]);
			glVertex3f(face.vertices[v][0],
				face.vertices[v][1],
				face.vertices[v][2]);
		}
	}

	glEnd();
}