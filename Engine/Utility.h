#pragma once

#include <string>

class Utility
{
public:
	static std::string ReadFile(const char* filename);

private:
	Utility();
	Utility(const Utility&) = delete;
	Utility& operator=(const Utility&) = delete;
};

