#include <CHIP-8/Display.h>

#include <cassert>

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

#define WHITE 0xFF, 0xFF, 0xFF, 0xFF
#define BLACK 0x00, 0x00, 0x00, 0xFF

namespace CHIP8
{
	Display::Display()
	{
		m_window = SDL_CreateWindow("CHIP-8", 0, 0, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
		m_renderer = SDL_CreateRenderer(m_window, nullptr);
	}

	Display::~Display()
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
	}

	void Display::SetPixel(const uint8_t row, const uint8_t col)
	{
		assert(row < s_height);
		assert(col < s_width);

		m_display[row][col] = true;
	}

	void Display::ClearPixel(const uint8_t row, const uint8_t col)
	{
		assert(row < s_height);
		assert(col < s_width);

		m_display[row][col] = false;
	}

	void Display::Clear()
	{
		m_display = {};
	}

	void Display::Draw()
	{
		SDL_SetRenderDrawColor(m_renderer, BLACK);
		SDL_RenderClear(m_renderer);

		int windowWidth;
		int windowHeight;
		SDL_GetWindowSize(m_window, &windowWidth, &windowHeight);
		float xOffset = static_cast<float>(windowWidth) / s_width;
		float yOffset = static_cast<float>(windowHeight) / s_height;

		SDL_FRect rect{ 0.0f, 0.0f, xOffset, yOffset };

		for (const auto& row : m_display)
		{
			for (const bool pixel : row)
			{
				switch (pixel)
				{
				case true:
					SDL_SetRenderDrawColor(m_renderer, WHITE);
					break;
				case false:
					SDL_SetRenderDrawColor(m_renderer, BLACK);
					break;
				}

				SDL_RenderFillRect(m_renderer, &rect);

				rect.x += xOffset;
			}

			rect.x = 0;
			rect.y += yOffset;
		}

		SDL_RenderPresent(m_renderer);
	}
}
