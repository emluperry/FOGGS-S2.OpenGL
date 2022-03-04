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

bool Texture2D::LoadBmp(char* path)
{
	std::ifstream inFile;
	inFile.open(path, std::ios::binary);

	if (!inFile.good())
	{
		std::cerr << "Can't open texture file " << path << std::endl;
	}

	char header[14];
	char infoh[40];
	inFile.read((char*)header, 14);
	inFile.read((char*)&infoh, 40);

	_width = (int)((unsigned char)infoh[7] << 24u) + ((unsigned char)infoh[6] << 16u) + ((unsigned char)infoh[5] << 8u) + (unsigned char)infoh[4];
	_height = (int)((unsigned char)infoh[11] << 24u) + ((unsigned char)infoh[10] << 16u) + ((unsigned char)infoh[9] << 8u) + (unsigned char)infoh[8];
	if (_width != _height)
	{
		std::cerr << "Bitmap is not square." << std::endl;
		return false;
	}

	int startPos = (int)((unsigned char)header[13] << 24u) + ((unsigned char)header[12] << 16u) + ((unsigned char)header[11] << 8u) + (unsigned char)header[10];
	inFile.seekg(startPos);

	int mode = ((int)((unsigned char)infoh[15] << 8u) + (unsigned char)infoh[14]) / 8; //bits per pixel
	int fileSize = _height * _width * mode;
	std::cout << fileSize << std::endl;
	std::cout << _height << std::endl;
	std::cout << _width << std::endl;
	std::cout << mode << std::endl;
	char* tempTextureData = new char[fileSize];
	inFile.read(tempTextureData, fileSize);

	inFile.close();
	std::cout << path << " loaded." << std::endl;

	glGenTextures(1, &_ID); //get next texture ID
	glBindTexture(GL_TEXTURE_2D, _ID); //bind texture to ID

	if (mode == 4)
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, _width, _height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, tempTextureData);
	else
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, _width, _height, GL_BGR_EXT, GL_UNSIGNED_BYTE, tempTextureData);
	return true;
}

bool Texture2D::LoadTga(char* path)
{
	char* tempHeaderData = new char[18];
	char* tempTextureData;
	int fileSize;
	char type, pixelDepth, mode;

	std::ifstream inFile;

	inFile.open(path, std::ios::binary);
	if (!inFile.good())
	{
		std::cerr << "Can't open texture file " << path << std::endl;
		return false;
	}

	//tga header has 18 byte size
	inFile.seekg(0, std::ios::beg);
	inFile.read(tempHeaderData, 18);

	inFile.seekg(0, std::ios::end);
	fileSize = (int)inFile.tellg() - 18;
	tempTextureData = new char[fileSize];
	inFile.seekg(18, std::ios::beg);
	inFile.read(tempTextureData, fileSize);
	inFile.close();

	type = tempHeaderData[2]; //get type out of header as must be rgb
	_width = ((unsigned char)tempHeaderData[13] << 8u) + (unsigned char)tempHeaderData[12];// finds width by combining two bytes into short
	_height = ((unsigned char)tempHeaderData[15] << 8u) + (unsigned char)tempHeaderData[14]; //finds height
	pixelDepth = tempHeaderData[16];

	bool flipped = false;
	if ((int)((tempHeaderData[11] << 8) + tempHeaderData[10]) == 0)
	{
		flipped = true;
	}
	if (type == 2)
	{
		std::cout << path << " loaded." << std::endl;

		glGenTextures(1, &_ID); //get next texture ID
		glBindTexture(GL_TEXTURE_2D, _ID); //bind texture to ID
		mode = pixelDepth / 8;

		//tga stored as bgra, so specify format as gl_bgr(a)_ext
		if(mode == 4)
			gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, _width, _height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, tempTextureData);
			//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, tempTextureData);
		else
			gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, _width, _height, GL_BGR_EXT, GL_UNSIGNED_BYTE, tempTextureData);
			//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, tempTextureData);

		delete[] tempHeaderData;
		delete[] tempTextureData;
		return true;
	}
	std::cerr << "Could not be loaded as type was " << (int)type << std::endl;
	return false;
}