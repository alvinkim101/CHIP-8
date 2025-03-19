#pragma once

#include <CHIP-8/Memory.h>
#include <CHIP-8/Display.h>
#include <CHIP-8/Stack.h>
#include <CHIP-8/Timer.h>
#include <CHIP-8/Keypad.h>
#include <CHIP-8/Register.h>
#include <CHIP-8/Decoder.h>
#include <CHIP-8/Executor.h>

namespace CHIP8
{
	class CHIP8
	{
	private:
		static constexpr uint64_t s_delay = 1428571; // nanoseconds
	public:
		uint16_t ReadMemory(const uint16_t address) const;
		void WriteMemory(const uint16_t address, const uint8_t data);

		void SetPixel(const uint8_t row, const uint8_t col);
		void ClearPixel(const uint8_t row, const uint8_t col);
		void ClearScreen();
		void Draw();

		void PushStack(const uint16_t address);
		uint16_t PopStack();

		void PressKey(const SDL_Scancode scancode);
		void ReleaseKey();

		Register& GetRegister();

		void Update();

	private:
		void Fetch();
		void Decode(const uint16_t opcode);
		void Execute(const Instruction instruction, const uint16_t opcode);

		Memory m_memory;
		Display m_display;
		Stack m_stack;
		Timer m_timer;
		Keypad m_keypad;
		Register m_register;
		Executor m_executor{*this};
	};
}
