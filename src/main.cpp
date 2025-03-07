#include <CHIP-8/Chip-8.h>

#include <SDL3/SDL.h>

int main()
{
	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
	CHIP8::CHIP8 chip8;

	SDL_Quit();
	return 0;
}
