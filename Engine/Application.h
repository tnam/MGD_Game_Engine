#pragma once

#include "Window.h"
#include "Camera.h"
#include "Renderer.h"

class Application
{
public:
	Application();
	~Application();

	void Run();

private:
	void Quit();
	void Update();
	void ProcessInput();
	
private:
	Window m_Window;
	Camera m_Camera;
	Renderer m_Renderer;
};

