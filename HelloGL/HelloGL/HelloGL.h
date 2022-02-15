#pragma once
#include <Windows.h> //required for opengl windows
#include <gl/GL.h> //opengl
#include <gl/GLU.h> //open gl util
#include "GL\freeglut.h" //freeglut lib
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

struct Vector3
{
	float x;
	float y;
	float z;
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

struct Color
{
	GLfloat r, g, b;
};
struct Vertex
{
	GLfloat x, y, z;
};

class HelloGL
{
private:
	float rotationRect;
	float rotationSquare;
	float rotationTriangle;
	Camera* camera;
	static Vertex vertices[];
	static Color colors[];
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
public:
	HelloGL(int argc, char* argv[]); //constructor
	~HelloGL(void); //destructor

	void Update();
	void Keyboard(unsigned char key, int x, int y);

	void Display();
	void DrawPolygon();
	void DrawSquare();
	void DrawScalene();
	void DrawIsosceles();
	void DrawEquilateral();
	void DrawAcute();
	void DrawRight();
	void DrawObtuse();
	void DrawPentagon();
	void DrawHexagon();

	void DrawCube();
	void DrawCubeArray();
	void DrawIndexedCube();
};

