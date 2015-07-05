#pragma once
class Mouse
{
public:
	static Mouse& GetInstance()
	{
		static Mouse instance;
		return instance;
	}

	void SetButton(unsigned int button, bool state);
	bool IsButtonPressed(unsigned int button);

private:
	Mouse();
	Mouse(Mouse const&) = delete;
	void operator=(Mouse const&) = delete;

private:
	static const int MAX_BUTTONS = 32;
	bool m_Keys[MAX_BUTTONS];
};

