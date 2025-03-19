#pragma once

#include <CHIP-8/Instruction.h>

#include <unordered_map>

namespace CHIP8
{
	class Decoder
	{
	private:
		static const std::unordered_map<uint8_t, Instruction> s_firstNibbleToInstruction;

	public:
		static Instruction Decode(const uint16_t opcode);
	};
}
