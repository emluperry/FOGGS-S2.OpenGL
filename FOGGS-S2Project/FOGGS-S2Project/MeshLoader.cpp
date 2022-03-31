#include "MeshLoader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#undef max

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);
	void LoadTexCoords(ifstream& inFile, TexturedMesh& mesh);
	void LoadNormals(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.vertexCount;

		if (mesh.vertexCount > 0)
		{
			mesh.vertices = new Vertex[mesh.vertexCount];

			for (int i = 0; i < mesh.vertexCount; i++)
			{
				inFile >> mesh.vertices[i].x;
				inFile >> mesh.vertices[i].y;
				inFile >> mesh.vertices[i].z;
			}
		}
	}

	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.colorCount;

		if (mesh.colorCount > 0)
		{
			mesh.colors = new Color[mesh.colorCount];
			for (int i = 0; i < mesh.colorCount; i++)
			{
				inFile >> mesh.colors[i].r;
				inFile >> mesh.colors[i].g;
				inFile >> mesh.colors[i].b;
			}
		}
	}

	void LoadTexCoords(ifstream& inFile, TexturedMesh& mesh)
	{
		inFile >> mesh.texCoordCount;

		if (mesh.texCoordCount > 0)
		{
			mesh.texCoords = new TexCoord[mesh.texCoordCount];

			for (int i = 0; i < mesh.texCoordCount; i++)
			{
				inFile >> mesh.texCoords[i].u;
				inFile >> mesh.texCoords[i].v;
			}
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.indexCount;

		if (mesh.indexCount > 0)
		{
			mesh.indices = new GLushort[mesh.indexCount];
			for (int i = 0; i < mesh.indexCount; i++)
			{
				inFile >> mesh.indices[i];
			}
		}
	}

	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.normalCount;

		if (mesh.normalCount > 0)
		{
			mesh.normals = new Vector3[mesh.normalCount];
			for (int i = 0; i < mesh.normalCount; i++)
			{
				inFile >> mesh.normals[i].x;
				inFile >> mesh.normals[i].y;
				inFile >> mesh.normals[i].z;
			}
		}
	}

	Mesh* MeshLoader::Load(char* path, bool hasNormals)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, *mesh);
		if (hasNormals)
		{
			LoadNormals(inFile, *mesh);
			mesh->colors = nullptr;
		}
		else
		{
			LoadColours(inFile, *mesh);
			mesh->normals = nullptr;
		}
		LoadIndices(inFile, *mesh);

		return mesh;
	}

	TexturedMesh* MeshLoader::LoadTextured(char* path, bool hasNormals)
	{
		TexturedMesh* mesh = new TexturedMesh();
		mesh->mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open texture file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, *(mesh->mesh));
		if (hasNormals)
		{
			LoadTexCoords(inFile, *mesh);
			LoadNormals(inFile, *(mesh->mesh));
			mesh->mesh->colors = nullptr;
		}
		else
		{
			LoadColours(inFile, *(mesh->mesh));
			LoadTexCoords(inFile, *mesh);
			mesh->mesh->normals = nullptr;
		}
		LoadIndices(inFile, *(mesh->mesh));

		return mesh;
	}

	TexturedMesh* MeshLoader::LoadObj(char* path)
	{
		TexturedMesh* mesh = new TexturedMesh();
		mesh->mesh = new Mesh();

		vector<Vertex> vertices = vector<Vertex>();
		vector<TexCoord> texCoords = vector<TexCoord>();
		vector<Vector3> normals = vector<Vector3>();
		vector<GLushort> indices = vector<GLushort>();

		ifstream inFile;
		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open texture file " << path << endl;
			return nullptr;
		}

		while (!inFile.eof())
		{
			string type = "";
			inFile >> type;
			if (type == "v")
			{
				Vertex vertex = Vertex();
				inFile >> vertex.x;
				inFile >> vertex.y;
				inFile >> vertex.z;
				vertices.push_back(vertex);
			}
			else if (type == "vt")
			{
				TexCoord coord = TexCoord();
				inFile >> coord.u;
				inFile >> coord.v;
				texCoords.push_back(coord);
			}
			else if (type == "vn")
			{
				Vector3 normal = Vector3();
				inFile >> normal.x;
				inFile >> normal.y;
				inFile >> normal.z;
				normals.push_back(normal);
			}
			else if (type == "f")
			{
				string index;
				getline(inFile, index);

				for (int i = 0; i < index.length(); i++)
				{
					if (index[i] == '/')
					{
						index[i] = ' ';
					}
				}

				stringstream ss(index);
				do
				{
					Vertex i;
					ss >> i.x;
					ss >> i.y;
					ss >> i.z;
					indices.push_back(i.x -1);
				} while (!ss.eof());
			}
			else
			{
				inFile.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		//convert vectors to arrays
		mesh->mesh->vertexCount = vertices.size();
		mesh->mesh->vertices = new Vertex[mesh->mesh->vertexCount];
		for (int i = 0; i < mesh->mesh->vertexCount; i++)
		{
			mesh->mesh->vertices[i] = vertices[i];
			cout << vertices[i].x << " " << vertices[i].y << " " << vertices[i].z << endl;
		}
		cout << endl;

		mesh->mesh->normalCount = normals.size();
		mesh->mesh->normals = new Vector3[mesh->mesh->normalCount];
		for (int i = 0; i < mesh->mesh->normalCount; i++)
		{
			mesh->mesh->normals[i] = normals[i];
			cout << normals[i].x << " " << normals[i].y << " " << normals[i].z << endl;
		}
		cout << endl;

		mesh->mesh->indexCount = indices.size();
		mesh->mesh->indices = new GLushort[mesh->mesh->indexCount];
		for (int i = 0; i < mesh->mesh->indexCount; i++)
		{
			mesh->mesh->indices[i] = indices[i];
			cout << indices[i] << endl;
		}
		cout << endl;

		mesh->texCoordCount = texCoords.size();
		mesh->texCoords = new TexCoord[mesh->texCoordCount];
		for (int i = 0; i < mesh->texCoordCount; i++)
		{
			mesh->texCoords[i] = texCoords[i];
			cout << texCoords[i].u << " " << texCoords[i].v << endl;
		}
		cout << endl;

		return mesh;
	}
}