#pragma once

#include <array>

extern "C"
{
	struct SDL_Window;
	struct SDL_Renderer;
}

namespace CHIP8
{

	class Display
	{
	public:
		static constexpr uint8_t s_width = 64;
		static constexpr uint8_t s_height = 32;

	public:
		Display();
		~Display();

		bool CheckPixel(const uint8_t row, const uint8_t col);
		void SetPixel(const uint8_t row, const uint8_t col);
		void ClearPixel(const uint8_t row, const uint8_t col);
		void Clear();
		void Draw();

	private:
		std::array<std::array<bool, s_width>, s_height> m_display{};
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
	};
}
