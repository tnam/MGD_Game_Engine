#pragma once
class Keyboard
{
public:
	static Keyboard& GetInstance()
	{
		static Keyboard instance;
		return instance;
	}

	void SetKey(unsigned int key, bool state);
	bool IsKeyPressed(unsigned int key) const;

private:
	Keyboard();
	Keyboard(Keyboard const&) = delete;
	void operator=(Keyboard const&) = delete;

private:
	static const int MAX_KEYS = 1024;
	bool m_Keys[MAX_KEYS];
};

