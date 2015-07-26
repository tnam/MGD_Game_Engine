#include <iostream>

#include "Game.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Shader.h"

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
	Update();
	Quit();
}

void Game::Update()
{
	Shader shader("shaders/basic.vs", "shaders/basic.frag");

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
	     0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	GLuint vbo, vao;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!m_Window->IsClosed())
	{
		m_Window->Update();

		ProcessInput();

		shader.Use();
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
	}

	Quit();
}

void Game::ProcessInput()
{
	if (Keyboard::GetInstance().IsKeyPressed(GLFW_KEY_A))
	{
		std::cout << "key pressed" << std::endl;
	}

	if (Mouse::GetInstance().IsButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
	{
		std::cout << "mouse button pressed" << std::endl;
	}
}

void Game::Quit()
{
	m_Window->Terminate();
}