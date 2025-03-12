#pragma once

#include <atomic>

#include <SDL3/SDL_timer.h>

namespace CHIP8
{
	class Timer
	{
	private:
		static constexpr uint32_t s_interval = 16; // milliseconds

	public:
		Timer();
		~Timer();

		uint32_t GetDelayTimer() const;
		void SetDelayTimer(const uint32_t value);

		uint32_t GetSoundTimer() const;
		void SetSoundTimer(const uint32_t value);

	private:
		static uint32_t Callback(void* userData, SDL_TimerID timerID, Uint32 interval); // Intermediary function to match SDL_TimerCallback
		void Tick();

		std::atomic<uint8_t> m_delayTimer{};
		std::atomic<uint8_t> m_soundTimer{};
		SDL_TimerID m_id;
	};
}
