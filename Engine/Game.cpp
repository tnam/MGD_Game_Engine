#include <iostream>
#include "Game.h"
#include "Keyboard.h"

Game::Game() 
{
	m_Window = new Window("Game Engine", 800, 600);
}

Game::~Game()
{
	delete m_Window;
}

void Game::Run()
{
	m_Window->Init();
	GameLoop();
	Quit();
}

void Game::GameLoop()
{
	while (!m_Window->IsClosed())
	{
		m_Window->Update();

		if (Keyboard::GetInstance().IsKeyPressed(GLFW_KEY_A))
		{
			std::cout << "key pressed" << std::endl;
		}
	}

	Quit();
}

void Game::Quit()
{
	m_Window->Terminate();
}