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
	void GameLoop();
	
private:
	Window *m_Window;
};

