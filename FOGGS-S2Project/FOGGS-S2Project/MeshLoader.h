#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#include <vector>
#include <string>
#include "Structures.h"

namespace MeshLoader
{
	Mesh* Load(char* path, bool hasNormals);
	TexturedMesh* LoadTextured(char* path, bool hasNormals);
	TexturedMesh* LoadObj(char* path);
};

