#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Window
{
public:
	Window(const char *title, int width, int height);
	~Window();

	void Init();
	void Terminate();
	void Update();
	bool IsClosed();

private:
	GLFWwindow *m_Window;
	int m_Width, m_Height;
	const char *m_Title;

	// Callbacks
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
};

