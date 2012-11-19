//	Class:		main
//	Updated:	11/18/12
//	Project:	CS 455 Game - Racer
//
//	Program entrance for Racer game

#ifndef MAIN_H
#define MAIN_H

//Only for windows
#ifdef WIN32
#include <Windows.h>
#include <MMSystem.h>
#endif // WIN32

// For all operating systems
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

#include <iostream>

// Game specific classes
#include "../inc/ObjectMan.h"
#include "../inc/TextureMan.h"

#define DEFAULT_WINDOW_WIDTH 640
#define DEFAULT_WINDOW_HEIGHT 480
#define KEYBOARD_S 115
#define KEYBOARD_ESC 27
#define KEYBOARD_F 102
#define NORMAL_EXIT_GLUT_LOOP "terminating glut"
#define PROGRAM_NAME "Racer"

GLvoid HandleKeyboardInput();

GLvoid InitGL(GLvoid);
GLvoid DrawGLScene(GLvoid);
GLvoid IdleGLScene(GLvoid);
GLvoid ReSizeGLScene(int width, int height);
GLvoid GLKeyDown(unsigned char key, int x, int y);
GLvoid SpecialKeys(int key, int x, int y);
GLvoid SpecialKeysUp(int key, int x, int y);

#ifdef WIN32

GLvoid PollJoyStick(GLvoid);
bool NeHeLoadBitmap(LPTSTR szFileName, GLuint &texid);

#endif // WIN32

#endif