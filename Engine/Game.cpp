#include <iostream>

#include "Game.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Shader.h"
#include "Texture.h"
#include "Utility.h"

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
	Shader shader("shaders/texture.vs", "shaders/texture.frag");

#if 0
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
#endif

	// Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[] = {
        // Positions          // Colors           // Texture Coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left 
    };
    GLuint indices[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };
    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    // TexCoord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0); // Unbind VAO

	Texture texture("textures/container.jpg");

	while (!m_Window->IsClosed())
	{
		m_Window->Update();

		ProcessInput();
		
		texture.Bind();
		shader.Bind();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
#if 0
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
#endif
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