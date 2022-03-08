#pragma once

struct Vector3
{
	float x;
	float y;
	float z;
};

struct Vector4
{
	float x, y, z, w;
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

struct Mesh
{
	Vertex* vertices;
	Color* colors;
	GLushort* indices;
	int vertexCount, colorCount, indexCount;
};

struct TexCoord
{
	GLfloat u, v;
};

struct TexturedMesh
{
	Mesh* mesh;
	TexCoord* texCoords;
	int texCoordCount;
};

struct Lighting
{
	Vector4 ambient;
	Vector4 diffuse;
	Vector4 specular;
};

struct Material
{
	Vector4 ambient;
	Vector4 diffuse;
	Vector4 specular;
	GLfloat shininess;
};