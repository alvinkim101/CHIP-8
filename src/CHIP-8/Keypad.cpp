#include <CHIP-8/Keypad.h>

#include <cassert>
#include <stdexcept>

namespace CHIP8
{
	const std::unordered_map<SDL_Scancode, Keypad::Key> Keypad::s_scancodeToKey
	{
		{ SDL_SCANCODE_1, Keypad::Key::_1 },
		{ SDL_SCANCODE_2, Keypad::Key::_2 },
		{ SDL_SCANCODE_3, Keypad::Key::_3 },
		{ SDL_SCANCODE_4, Keypad::Key::_C },
		{ SDL_SCANCODE_Q, Keypad::Key::_4 },
		{ SDL_SCANCODE_W, Keypad::Key::_5 },
		{ SDL_SCANCODE_E, Keypad::Key::_6 },
		{ SDL_SCANCODE_R, Keypad::Key::_D },
		{ SDL_SCANCODE_A, Keypad::Key::_7 },
		{ SDL_SCANCODE_S, Keypad::Key::_8 },
		{ SDL_SCANCODE_D, Keypad::Key::_9 },
		{ SDL_SCANCODE_F, Keypad::Key::_E },
		{ SDL_SCANCODE_Z, Keypad::Key::_A },
		{ SDL_SCANCODE_X, Keypad::Key::_0 },
		{ SDL_SCANCODE_C, Keypad::Key::_B },
		{ SDL_SCANCODE_V, Keypad::Key::_F },
	};

	void Keypad::Press(const Key key)
	{
		m_key = key;
	}

	void Keypad::Press(const SDL_Scancode scancode)
	{
		try
		{
			Press(s_scancodeToKey.at(scancode));
		}
		catch (const std::out_of_range& e)
		{
			assert(false);
		}
	}

	void Keypad::Release()
	{
		m_key = Key::None;
	}
}
