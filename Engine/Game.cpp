#include "Game.h"

Game::Game() 
{
	m_Window = new Window("Test", 800, 600);
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
	}

	Quit();
}

void Game::Quit()
{
	m_Window->Terminate();
}