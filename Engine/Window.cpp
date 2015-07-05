#include <iostream>
#include "Window.h"
#include "Keyboard.h"

Window::Window(const char *title, int width, int height)
	: m_Title(title)
	, m_Width(width)
	, m_Height(height)
{
	//glfwSetWindowUserPointer(m_Window, m_pKeyboard);
	//glfwSetKeyCallback(m_Window, key_callback);
}

Window::~Window()
{
	Terminate();
}

bool Window::IsClosed()
{
	return glfwWindowShouldClose(m_Window);
}

void Window::Update()
{
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(m_Window);
}

void Window::Init()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
	glfwMakeContextCurrent(m_Window);
	if (m_Window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		Terminate();
	}

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return;
	}

	glViewport(0, 0, m_Width, m_Height);

	glfwSetKeyCallback(m_Window, KeyCallback);
}

void Window::Terminate()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//Keyboard *pKeyboard = static_cast<Keyboard*>(glfwGetWindowUserPointer(window));
	Keyboard::GetInstance().SetKey(key, action != GLFW_RELEASE);
}

