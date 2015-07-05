#include "Mouse.h"

const int Mouse::MAX_BUTTONS;

Mouse::Mouse()
{
	for (size_t i = 0; i < MAX_BUTTONS; ++i)
	{
		m_Keys[i] = false;
	}
}

void Mouse::SetButton(unsigned int button, bool state)
{
	m_Keys[button] = state;
}

bool Mouse::IsButtonPressed(unsigned int button)
{
	return m_Keys[button];
}
