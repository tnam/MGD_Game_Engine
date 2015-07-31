#include <iostream>
#include <fstream>
#include <sstream>
#include <SOIL\SOIL.h>

#include "Utility.h"

Utility::Utility()
{
}

std::string Utility::ReadFile(const char* filename)
{
	std::string fileData;
	std::stringstream fileStream;

	std::ifstream file(filename);

	fileStream << file.rdbuf();
	file.close();

	fileData = fileStream.str();

	return fileData;
}

unsigned char* Utility::LoadTexture(const char* filename, int* width, int* height)
{
	unsigned char* image = SOIL_load_image(filename, width, height, 0, SOIL_LOAD_RGB);

	return image;
}

void Utility::FreeImageData(unsigned char* image)
{
	SOIL_free_image_data(image);
}
