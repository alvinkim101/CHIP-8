#pragma once

#include <CHIP-8/Instruction.h>

#include <unordered_map>
#include <functional>

namespace CHIP8
{
	class CHIP8;

	class Executor
	{
	public:
		Executor(CHIP8& chip8);

		void Execute(const Instruction instruction, const uint16_t opcode);

	private:
		std::unordered_map<Instruction, std::function<void(const uint16_t)>> m_delegates;
		CHIP8& m_chip8;
	};
}
