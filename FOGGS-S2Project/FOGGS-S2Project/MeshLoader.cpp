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



	Vertex LoadVertex(ifstream& inFile)
	{
		Vertex vertex = Vertex();
		inFile >> vertex.x;
		inFile >> vertex.y;
		inFile >> vertex.z;
		return vertex;
	}

	TexCoord LoadTexCoord(ifstream& inFile)
	{
		TexCoord coord = TexCoord();
		inFile >> coord.u;
		inFile >> coord.v;
		return coord;
	}

	Vector3 LoadNormal(ifstream& inFile)
	{
		Vector3 normal = Vector3();
		inFile >> normal.x;
		inFile >> normal.y;
		inFile >> normal.z;
		return normal;
	}

	void LoadFace(ifstream& inFile, vector<IndexGroup>& indices)
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
			IndexGroup i = IndexGroup();
			ss >> i.v;
			ss >> i.t;
			ss >> i.n;
			indices.push_back(i);
		} while (!ss.eof());
	}

	bool GetSimilarVertexIndex(Vertex& inVertex, TexCoord& inTexCoord, Vector3& inNormal, vector<Vertex>& outVertices, vector<TexCoord>& outTexCoords, vector<Vector3>& outNormals, unsigned short &index)
	{
		for (unsigned int i = 0; i < outVertices.size(); i++)
		{
			if (
				inVertex.x == outVertices[i].x &&
				inVertex.y == outVertices[i].y &&
				inVertex.z == outVertices[i].z &&
				inTexCoord.u == outTexCoords[i].u &&
				inTexCoord.v == outTexCoords[i].v &&
				inNormal.x == outNormals[i].x &&
				inNormal.y == outNormals[i].y &&
				inNormal.z == outNormals[i].z
				)
			{
				index = i;
				return true;
			}
		}
		return false;
	}

	TexturedMesh* MeshLoader::LoadObj(char* path)
	{
		TexturedMesh* mesh = new TexturedMesh();
		mesh->mesh = new Mesh();

		vector<Vertex> inVertices = vector<Vertex>();
		vector<TexCoord> inTexCoords = vector<TexCoord>();
		vector<Vector3> inNormals = vector<Vector3>();

		vector<IndexGroup> faces = vector<IndexGroup>();

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
				inVertices.push_back(LoadVertex(inFile));
			else if (type == "vt")
				inTexCoords.push_back(LoadTexCoord(inFile));
			else if (type == "vn")
				inNormals.push_back(LoadNormal(inFile));
			else if (type == "f")
				LoadFace(inFile, faces);
			else
				inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		inFile.close();



		vector<Vertex> outVertices = vector<Vertex>();
		vector<TexCoord> outTexCoords = vector<TexCoord>();
		vector<Vector3> outNormals = vector<Vector3>();

		vector<GLushort> indices = vector<GLushort>();

		for (int i = 0; i < faces.size(); i++)
		{
			unsigned short index;
			bool found = GetSimilarVertexIndex(inVertices[faces[i].v - 1], inTexCoords[faces[i].t - 1], inNormals[faces[i].n - 1], outVertices, outTexCoords, outNormals, index);
			if (found)
				indices.push_back(index);
			else
			{
				outVertices.push_back(inVertices[faces[i].v - 1]);
				outTexCoords.push_back(inTexCoords[faces[i].t - 1]);
				outNormals.push_back(inNormals[faces[i].n - 1]);
				indices.push_back(outVertices.size() - 1);
			}
		}

		//convert vectors to arrays
		mesh->mesh->vertexCount = outVertices.size();
		mesh->mesh->vertices = new Vertex[mesh->mesh->vertexCount];
		for (int i = 0; i < mesh->mesh->vertexCount; i++)
			mesh->mesh->vertices[i] = outVertices[i];

		mesh->texCoordCount = outTexCoords.size();
		mesh->texCoords = new TexCoord[mesh->texCoordCount];
		for (int i = 0; i < mesh->texCoordCount; i++)
			mesh->texCoords[i] = outTexCoords[i];

		mesh->mesh->normalCount = outNormals.size();
		mesh->mesh->normals = new Vector3[mesh->mesh->normalCount];
		for (int i = 0; i < mesh->mesh->normalCount; i++)
			mesh->mesh->normals[i] = outNormals[i];

		mesh->mesh->indexCount = indices.size();
		mesh->mesh->indices = new GLushort[mesh->mesh->indexCount];
		for (int i = 0; i < mesh->mesh->indexCount; i++)
			mesh->mesh->indices[i] = indices[i];

		return mesh;
	}

	void LoadVector4(ifstream& inFile, Vector4& element)
	{
		string vec;
		getline(inFile, vec);

		int values = 0;
		for (int i = 0; i < vec.length(); i++)
		{
			if (vec[i] == ' ')
			{
				values++;
			}
		}

		stringstream ss(vec);
		ss >> element.x;
		ss >> element.y;
		ss >> element.z;
		if (values == 4)
			ss >> element.w;
		else
			element.w = 1;
	}

	Material* MeshLoader::LoadMaterial(char* path)
	{
		ifstream inFile;
		inFile.open(path);

		Material* material = new Material();

		while (!inFile.eof())
		{
			string type = "";
			inFile >> type;
			if (type == "Ns")
				inFile >> material->shininess;
			else if (type == "Ka")
				LoadVector4(inFile, material->ambient);
			else if (type == "Kd")
				LoadVector4(inFile, material->diffuse);
			else if (type == "Ks")
				LoadVector4(inFile, material->specular);
			else if (type == "Ke")
				LoadVector4(inFile, material->emissive);
			else
				inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		inFile.close();

		return material;
	}

}