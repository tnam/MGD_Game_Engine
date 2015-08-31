#pragma once

#include <vector>

#include "Renderable.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void AddRenderable(const Renderable* renderable);
	void Draw(const Renderable* renderable);

private:
	std::vector<const Renderable*> m_Renderables;
};

