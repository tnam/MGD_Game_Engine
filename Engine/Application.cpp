#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Application.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Shader.h"
#include "Texture.h"
#include "Utility.h"

#include "Mesh.h"
#include "MeshGenerator.h"

Application::Application() 
	: m_Camera(glm::vec3(0.0f, 0.0f, 3.0f))
	, m_Window("Game Engine", 800, 600)
{
}

Application::~Application()
{
}

void Application::Run()
{
	m_Window.Init();
	m_Renderer.Init();
	Update();
	Quit();
}

void Application::Update()
{
	Shader shader("shaders/texture.vs", "shaders/texture.frag");

	Texture texture("textures/texture1.jpg");

	glm::vec3 cubePositions[] = {
	  glm::vec3( 0.0f,  0.0f,  0.0f), 
	  glm::vec3( 2.0f,  5.0f, -15.0f), 
	  glm::vec3(-1.5f, -2.2f, -2.5f),  
	  glm::vec3(-3.8f, -2.0f, -12.3f),  
	  glm::vec3( 2.4f, -0.4f, -3.5f),  
	  glm::vec3(-1.7f,  3.0f, -7.5f),  
	  glm::vec3( 1.3f, -2.0f, -2.5f),  
	  glm::vec3( 1.5f,  2.0f, -2.5f), 
	  glm::vec3( 1.5f,  0.2f, -1.5f), 
	  glm::vec3(-1.3f,  1.0f, -1.5f)  
	};
	

	while (!m_Window.IsClosed())
	{
		Mesh mesh = MeshGenerator::CreateCube();
		Mesh mesh2 = MeshGenerator::CreateCube();

		m_Window.Update();

		ProcessInput();
		
		shader.Bind();

		// Create transformations
        glm::mat4 view = m_Camera.GetViewMatrix();
        glm::mat4 projection = glm::perspective(glm::radians(m_Camera.GetFOV()), (GLfloat)m_Window.GetWidth() / (GLfloat)m_Window.GetHeight(), m_Camera.GetNear(), m_Camera.GetFar());

		// Send matrices to the shader
		shader.SetUniform("view", view);
		shader.SetUniform("projection", projection);

		m_Renderer.Begin();

		m_Renderer.AddRenderable(cubePositions[0], glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f), &mesh, texture.GetID(), m_Camera.GetFrustum());
		m_Renderer.AddRenderable(cubePositions[2], glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), &mesh2, texture.GetID(), m_Camera.GetFrustum());

		m_Renderer.End();

		m_Renderer.Render();
	}

	Quit();
}

void Application::ProcessInput()
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

void Application::Quit()
{
	m_Window.Terminate();
}