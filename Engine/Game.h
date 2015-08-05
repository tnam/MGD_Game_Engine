#pragma once

#include "Window.h"
#include "Camera.h"

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
	Window m_Window;
	Camera m_Camera;
};

