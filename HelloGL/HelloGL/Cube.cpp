#include "Cube.h"

Vertex Cube::indexedVertices[] = {
	1,1,1, -1,1,1,
	-1,-1,1, 1,-1,1,
	1,-1,-1, 1,1,-1,
	-1,1,-1, -1,-1,-1
};

Color Cube::indexedColors[] = {
	1,1,1, 1,1,0,
	1,0,0, 1,0,1,
	0,0,1, 0,1,1,
	0,1,0, 0,0,0
};

GLushort Cube::indices[] = {
	0,1,2, 2,3,0,
	0,3,4, 4,5,0,
	0,5,6, 6,1,0,
	1,6,7, 7,2,1,
	7,4,3, 3,2,7,
	4,7,6, 6,5,4
};

Cube::Cube()
{

}

Cube::~Cube()
{

}
void Cube::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);

	glPushMatrix();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Cube::Update()
{

}