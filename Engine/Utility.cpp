#include "Utility.h"
#include <fstream>
#include <sstream>

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