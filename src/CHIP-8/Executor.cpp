#include <CHIP-8/Executor.h>
#include <CHIP-8/CHIP-8.h>

namespace CHIP8
{
	Executor::Executor(CHIP8& chip8) : m_chip8(chip8)
	{
		m_delegates[Instruction::NoOperation] = [](const uint16_t opcode){};
		m_delegates[Instruction::ClearScreen] = [this](const uint16_t opcode)
			{
				m_chip8.ClearScreen();
			};
		m_delegates[Instruction::Jump] = [this](const uint16_t opcode)
			{
				uint16_t programCounter = opcode & 0x0FFF;
				m_chip8.GetRegister().programCounter = programCounter;
			};
		m_delegates[Instruction::SetRegisterVX] = [this](const uint16_t opcode)
			{
				uint8_t x = (opcode >> 8) & 0x0F;
				uint8_t nn = opcode & 0x00FF;
				m_chip8.GetRegister().variables[x] = nn;
			};
		m_delegates[Instruction::AddValueToRegisterVX] = [this](const uint16_t opcode)
			{
				uint8_t x = (opcode >> 8) & 0x0F;
				uint8_t nn = opcode & 0x00FF;
				m_chip8.GetRegister().variables[x] += nn;
			};
		m_delegates[Instruction::SetIndexRegisterI] = [this](const uint16_t opcode)
			{
				uint16_t nnn = opcode & 0x0FFF;
				m_chip8.GetRegister().index = nnn;
			};
		m_delegates[Instruction::Draw] = [this](const uint16_t opcode)
			{
				m_chip8.Draw();
			};
	}

	void Executor::Execute(const Instruction instruction, const uint16_t opcode)
	{
		m_delegates[instruction](opcode);
	}
}
