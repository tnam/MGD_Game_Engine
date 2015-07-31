#pragma once

#include <string>
#include <string>
#include <GL\glew.h>

#include "Texture.h"

class Utility
{
public:
	static std::string ReadFile(const char* filename);

	// Texture utilities
	static unsigned char* LoadTexture(const char* filename, int* width, int* height);
	static void FreeImageData(unsigned char* image);

private:
	Utility();
	Utility(const Utility&) = delete;
	Utility& operator=(const Utility&) = delete;
};

