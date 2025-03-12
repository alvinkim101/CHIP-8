#include <CHIP-8/Executor.h>
#include <CHIP-8/CHIP-8.h>

namespace CHIP8
{
	Executor::Executor(CHIP8& chip8) : m_chip8(chip8)
	{
		m_delegates[Instruction::NoOperation] = [](){};
		m_delegates[Instruction::ClearScreen] = [this]()
			{

			};
		m_delegates[Instruction::Jump] = [this]()
			{

			};
		m_delegates[Instruction::SetRegisterVX] = [this]()
			{

			};
		m_delegates[Instruction::AddValueToRegisterVX] = [this]()
			{

			};
		m_delegates[Instruction::SetIndexRegisterI] = [this]()
			{

			};
		m_delegates[Instruction::Draw] = [this]()
			{

			};
	}

	void Executor::Execute(Instruction instruction)
	{
		m_delegates[instruction]();
	}
}
