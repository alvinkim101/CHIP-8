#pragma once

#include <unordered_map>

#include <SDL3/SDL_scancode.h>

namespace CHIP8
{
	class Keypad
	{
	public:
		enum class Key
		{
			None,
			_1, _2, _3, _C,
			_4, _5, _6, _D,
			_7, _8, _9, _E,
			_A, _0, _B, _F
		};

	private:
		static const std::unordered_map<SDL_Scancode, Key> s_scancodeToKey;

	public:
		void Press(const Key key);
		void Press(const SDL_Scancode scancode);

		void Release();

	private:
		Key m_key{Key::None};
	};
}
