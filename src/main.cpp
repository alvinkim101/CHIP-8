#include <CHIP-8/CHIP-8.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
	CHIP8::CHIP8 chip8;

	bool running = true;
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_EVENT_KEY_DOWN:
				chip8.PressKey(event.key.scancode);
				break;

			case SDL_EVENT_KEY_UP:
				chip8.ReleaseKey();
				break;

			case SDL_EVENT_QUIT:
				running = false;
				break;
			}
		}
		
		chip8.Update();
	}

	SDL_Quit();
	return 0;
}
