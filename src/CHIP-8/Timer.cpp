#include <CHIP-8/Timer.h>

#include <cassert>

#include <SDL3/SDL_log.h>

namespace CHIP8
{
	Timer::Timer()
	{
		m_id = SDL_AddTimer(s_interval, Timer::Callback, this); // Call Tick every s_interval from a separate thread
	}

	Timer::~Timer()
	{
		SDL_RemoveTimer(m_id);
	}

	uint32_t Timer::GetDelayTimer() const
	{
		return m_delayTimer;
	}

	void Timer::SetDelayTimer(const uint32_t value)
	{
		m_delayTimer = value;
	}

	uint32_t Timer::GetSoundTimer() const
	{
		return m_soundTimer;
	}

	void Timer::SetSoundTimer(const uint32_t value)
	{
		m_soundTimer = value;
	}

	uint32_t Timer::Callback(void* userData, SDL_TimerID timerID, Uint32 interval)
	{
		assert(userData);

		static_cast<Timer*>(userData)->Tick();

		// If zero is returned, the timer is canceled
		// If a non-zero value is returned, the timer runs again with the value being the next interval
		return interval;
	}

	void Timer::Tick()
	{
		// Should I use a mutex?

		if (m_delayTimer > 0)
		{
			m_delayTimer--;
		}
		if (m_soundTimer > 0)
		{
			SDL_Log("Beep"); // Todo: actually beep

			m_soundTimer--;
		}
	}
}
