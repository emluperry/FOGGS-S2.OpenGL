#pragma once
#include <Windows.h> //required for opengl windows
#include <gl/GL.h> //opengl
#include <gl/GLU.h> //open gl util
#include "GL\freeglut.h" //freeglut lib
#include "GLUTCallbacks.h"
#include "Structures.h"

class DrawMethods
{
private:
	float rotationRect = 0;
	float rotationSquare = 0;
	float rotationTriangle = 0;

	static Color colors[];
	//pyramid
	static Vertex pyVertices[];
	//triangular prism
	static Vertex triPrVertices[];
	//hexagonal prism
	static Vertex hexPrVertices[];
	//Dodedahedron
	static Vertex dodecaVertices[];

public:
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

	void DrawPyramid();
	void DrawTriangularPrism();
	void DrawHexagonalPrism();
	void DrawDodecahedron();
};