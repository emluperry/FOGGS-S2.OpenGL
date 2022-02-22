#pragma once
#include "Structures.h"
#include <Windows.h> //required for opengl windows
#include <gl/GL.h> //opengl
#include <gl/GLU.h> //open gl util
#include "GL\freeglut.h" //freeglut lib

float rotationRect;
float rotationSquare;
float rotationTriangle;

static Color colors[];
//pyramid
static Vertex pyVertices[];
//triangular prism
static Vertex triPrVertices[];
//hexagonal prism
static Vertex hexPrVertices[];
//Dodedahedron
static Vertex dodecaVertices[];

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