#include <CHIP-8/Decoder.h>

#include <cassert>
#include <stdexcept>

#include <SDL3/SDL_log.h>

namespace CHIP8
{
	const std::unordered_map<uint8_t, Instruction> Decoder::s_firstNibbleToInstruction
	{
		// First nibble of opcode is checked
		// Might need to rethink this since there is overlap e.g. 00E0 is clear screen and 00EE is returning from a subroutine

		{ 0x0, Instruction::ClearScreen },
		{ 0x1, Instruction::Jump },
		{ 0x6, Instruction::SetRegisterVX },
		{ 0x7, Instruction::AddValueToRegisterVX },
		{ 0xA, Instruction::SetIndexRegisterI },
		{ 0xD, Instruction::Draw }
	};

	Instruction Decoder::Decode(const uint16_t opcode)
	{
		try
		{
			uint8_t nibble = (opcode & 0xF000) >> 12;
			return s_firstNibbleToInstruction.at(nibble);
		}
		catch (const std::out_of_range& e)
		{
			SDL_Log("Opcode %u is not implemented", opcode);
			assert(false);

			return Instruction::NoOperation;
		}
	}
}
