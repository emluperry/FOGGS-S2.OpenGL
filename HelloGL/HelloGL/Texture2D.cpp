#include "Texture2D.h"

Texture2D::Texture2D()
{

}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
	char* tempTextureData;
	int fileSize;
	std::ifstream inFile;
	
	_width = width;
	_height = height;
	inFile.open(path, std::ios::binary);

	if (!inFile.good())
	{
		std::cerr << "Can't open texture file " << path << std::endl;
		return false;
	}

	inFile.seekg(0, std::ios::end);
	fileSize = (int)inFile.tellg();
	tempTextureData = new char[fileSize];
	inFile.seekg(0, std::ios::beg);
	inFile.read(tempTextureData, fileSize);
	inFile.close();
	std::cout << path << " loaded." << std::endl;

	glGenTextures(1, &_ID); //get next texture ID
	glBindTexture(GL_TEXTURE_2D, _ID); //bind texture to ID
	//glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData); //specify details of texture image
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);

	delete[] tempTextureData;
	return true;
}

bool Texture2D::LoadBmp(char* path, int width, int height)
{
	std::ifstream inFile;
	_width = width;
	_height = height;
	inFile.open(path, std::ios::binary);

	if (!inFile.good())
	{
		std::cerr << "Can't open texture file " << path << std::endl;
	}

	bmpFile_type type;
	bmpFile_header header;
	bmp_infoheader infoh;
	inFile.read((char*)&type, sizeof(bmpFile_type));
	inFile.read((char*)&header, sizeof(bmpFile_header));
	inFile.read((char*)&infoh, sizeof(bmp_infoheader));
	if (infoh.width != infoh.height)
	{
		std::cerr << "Bitmap is not square." << std::endl;
		return false;
	}

	//create buffer to hold each line as it is read in
	bmp_color* imageBuffer = new bmp_color;

	std::stringstream stream;

	int index = 0;
	for (int row = 0; row < infoh.height; row++)
	{
		inFile.read((char*)imageBuffer, sizeof(bmp_color));
		for (int col = 0; col < infoh.width; col++)
		{
			stream << imageBuffer->r << imageBuffer->g << imageBuffer->b;
		}
	}

	inFile.close();
	delete imageBuffer;

	stream.seekg(0, std::ios::end);
	int fileSize = (int)stream.tellg();
	char* tempTextureData = new char[fileSize];
	stream.seekg(0, std::ios::beg);
	stream.read(tempTextureData, fileSize);

	std::cout << path << " loaded." << std::endl;

	glGenTextures(1, &_ID); //get next texture ID
	glBindTexture(GL_TEXTURE_2D, _ID); //bind texture to ID
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData); //specify details of texture image
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);

	return true;
}