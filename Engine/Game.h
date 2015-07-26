#pragma once

#include "Window.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

private:
	void Quit();
	void Update();
	void ProcessInput();
	
private:
	Window *m_Window;
};

