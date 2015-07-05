#include "Keyboard.h"

const int Keyboard::MAX_KEYS;

Keyboard::Keyboard()
{
	for (size_t i = 0; i < MAX_KEYS; ++i)
	{
		m_Keys[i] = false;
	}
}

void Keyboard::SetKey(unsigned int key, bool state)
{
	m_Keys[key] = state;
}

bool Keyboard::IsKeyPressed(unsigned int key) const
{
	return m_Keys[key];
}


