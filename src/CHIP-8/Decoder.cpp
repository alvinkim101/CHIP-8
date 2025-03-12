#include <CHIP-8/Decoder.h>

#include <cassert>
#include <stdexcept>

#include <SDL3/SDL_log.h>

namespace CHIP8
{
	const std::unordered_map<uint16_t, Instruction> Decoder::s_opcodeToInstruction
	{
		{ 1, Instruction::ClearScreen },
		{ 1, Instruction::Jump },
		{ 1, Instruction::SetRegisterVX },
		{ 1, Instruction::AddValueToRegisterVX },
		{ 1, Instruction::SetIndexRegisterI },
		{ 1, Instruction::Draw }
	};

	Instruction Decoder::Decode(const uint16_t opcode)
	{
		try
		{
			return s_opcodeToInstruction.at(opcode);
		}
		catch (const std::out_of_range& e)
		{
			SDL_Log("Opcode %u is not implemented", opcode);
			assert(false);

			return Instruction::NoOperation;
		}
	}
}
