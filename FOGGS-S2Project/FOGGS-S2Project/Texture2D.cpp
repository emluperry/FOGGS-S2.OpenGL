#include "Texture2D.h"

Texture2D::Texture2D()
{

}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_ID);
}

bool Texture2D::LoadTexture(std::string path, int width, int height)
{
	std::ifstream inFile;
	inFile.open(path, std::ios::binary);
	if (!inFile.good())
	{
		std::cerr << "Can't open texture file " << path << std::endl;
		inFile.close();
		return false;
	}
	inFile.close();

	char* tempTextureData;
	char mode = 0;

	std::string extension = path.substr(path.rfind('.') + 1, std::string::npos);
	std::cout << extension << std::endl;
	if (extension == "bmp")
		tempTextureData = LoadBmp(&path[0]);
	else if (extension == "raw")
		tempTextureData = LoadRaw(&path[0], width, height);
	else if (extension == "tga")
		tempTextureData = LoadTga(&path[0], mode);

	if (tempTextureData == nullptr)
	{
		std::cerr << "Nullptr returned while loading " << path << std::endl;
		return false;
	}

	glGenTextures(1, &_ID); //get next texture ID
	glBindTexture(GL_TEXTURE_2D, _ID); //bind texture to ID

	if (extension == "bmp")
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, _width, _height, GL_BGR_EXT, GL_UNSIGNED_BYTE, tempTextureData);
	else if (extension == "raw")
	{
		//glTexImage2D(GL_TEXTURE_2D, 0, 3, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData); //specify details of texture image
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //required by glteximage2d
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, _width, _height, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);
	}
	else if (extension == "tga")
	{
		//tga stored as bgra, so specify format as gl_bgr(a)_ext
		if (mode == 4)
			gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, _width, _height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, tempTextureData);
		else
			gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, _width, _height, GL_BGR_EXT, GL_UNSIGNED_BYTE, tempTextureData);
	}

	delete[] tempTextureData;
	return true;
}

char* Texture2D::LoadRaw(char* path, int width, int height)
{
	std::ifstream inFile;
	inFile.open(path, std::ios::binary);
	int fileSize;
	_width = width;
	_height = height;

	char* tempTextureData;

	inFile.seekg(0, std::ios::end);
	fileSize = (int)inFile.tellg();
	tempTextureData = new char[fileSize];
	inFile.seekg(0, std::ios::beg);
	inFile.read(tempTextureData, fileSize);
	inFile.close();
	std::cout << path << " loaded." << std::endl;

	return tempTextureData;
}

char* Texture2D::LoadBmp(char* path)
{
	std::ifstream inFile;
	inFile.open(path, std::ios::binary);

	char header[14];
	char infoh[40];
	inFile.read((char*)header, 14);
	inFile.read((char*)&infoh, 40);

	_width = (int)((unsigned char)infoh[7] << 24u) + ((unsigned char)infoh[6] << 16u) + ((unsigned char)infoh[5] << 8u) + (unsigned char)infoh[4];
	_height = (int)((unsigned char)infoh[11] << 24u) + ((unsigned char)infoh[10] << 16u) + ((unsigned char)infoh[9] << 8u) + (unsigned char)infoh[8];

	int startPos = (int)((unsigned char)header[13] << 24u) + ((unsigned char)header[12] << 16u) + ((unsigned char)header[11] << 8u) + (unsigned char)header[10];
	inFile.seekg(startPos);

	int bytesPerPixel = ((int)((unsigned char)infoh[15] << 8u) + (unsigned char)infoh[14]) / 8; //bits per pixel
	if (bytesPerPixel != 3)
	{
		std::cerr << "Code only supports 24bit bmp files." << std::endl;
		return nullptr;
	}
	int fileSize = _height * _width * bytesPerPixel;
	char* tempTextureData = new char[fileSize];
	inFile.read(tempTextureData, fileSize);

	inFile.close();
	std::cout << path << " loaded." << std::endl;
	return tempTextureData;
}

char* Texture2D::LoadTga(char* path, char &mode)
{
	std::ifstream inFile;
	inFile.open(path, std::ios::binary);

	//tga header has 18 byte size
	char* tempHeaderData = new char[18];
	inFile.seekg(0, std::ios::beg);
	inFile.read(tempHeaderData, 18);

	char* tempTextureData;
	int fileSize;
	inFile.seekg(0, std::ios::end);
	fileSize = (int)inFile.tellg() - 18;
	tempTextureData = new char[fileSize];
	inFile.seekg(18, std::ios::beg);
	inFile.read(tempTextureData, fileSize);
	inFile.close();

	char type, pixelDepth;
	type = tempHeaderData[2]; //get type out of header as must be rgb
	_width = ((unsigned char)tempHeaderData[13] << 8u) + (unsigned char)tempHeaderData[12];// finds width by combining two bytes into short
	_height = ((unsigned char)tempHeaderData[15] << 8u) + (unsigned char)tempHeaderData[14]; //finds height
	pixelDepth = tempHeaderData[16];
	mode = pixelDepth / 8;

	bool flipped = false;
	if ((int)((tempHeaderData[11] << 8) + tempHeaderData[10]) == 0)
	{
		flipped = true;
	}
	delete[] tempHeaderData;

	if (type == 2)
	{
		std::cout << path << " loaded." << std::endl;

		return tempTextureData;
	}
	else
	{
		std::cerr << "Could not be loaded as type was " << (int)type << std::endl;
		delete[] tempTextureData;
		return nullptr;
	}
}