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

		void Execute(Instruction instruction);

	private:
		std::unordered_map<Instruction, std::function<void()>> m_delegates;
		CHIP8& m_chip8;
	};
}
