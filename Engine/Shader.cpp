#include <iostream>

#include "Shader.h"
#include "Utility.h"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
	: m_VertexPath(vertexPath)
	, m_FragmentPath(fragmentPath)
{
	m_ProgramID = Load();
}

Shader::~Shader()
{
	glDeleteProgram(m_ProgramID);
}

GLint Shader::Load()
{
	// Loading vertex and fragment source code 
	std::string vertexPath = Utility::ReadFile(m_VertexPath).c_str();
	std::string fragmentPath = Utility::ReadFile(m_FragmentPath).c_str();

	const GLchar* vertCode = vertexPath.c_str();
	const GLchar* fragCode = fragmentPath.c_str();

	// Vertex shader compilation
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertCode, NULL);
	glCompileShader(vertex);
	// Check for compile errors
	GLint success;
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "Failed to compile vertex shader\n" << infoLog << std::endl;
		glDeleteShader(vertex);
		return 0;
	}

	// Fragment shader compilation
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragCode, NULL);
	glCompileShader(fragment);
	// Check for compile errors
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "Failed to compile fragment shader\n" << infoLog << std::endl;
		glDeleteShader(fragment);
		return 0;
	}

	// Shader Program
	GLint program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glValidateProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[512];
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "Failed to link program\n" << infoLog << std::endl;
	}

	// Delete shaders
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	
	return program;
}

void Shader::Use()
{
	glUseProgram(m_ProgramID);
}

void Shader::Disable()
{
	glUseProgram(0);
}
