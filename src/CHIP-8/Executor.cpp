#include <CHIP-8/Executor.h>
#include <CHIP-8/CHIP-8.h>

#include <cassert>

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
				Register& _register = m_chip8.GetRegister(); // Didn't know register was a keyword
				uint16_t I = _register.index;
				uint8_t& VF = _register.variables[0xF];
				uint8_t N = opcode & 0x000F;
				uint8_t X = ((opcode & 0x0F00) >> 8) % Display::s_width;
				uint8_t Y = ((opcode & 0x00F0) >> 4) % Display::s_height;

				VF = 0;
				for (int i = 0; i < N; i++)
				{
					const uint8_t sprite = m_chip8.ReadMemory(I + N);

					for (int j = 7; j >= 0; j--)
					{
						uint8_t spriteBit = sprite >> j;

						if (spriteBit)
						{
							assert(X < Display::s_width);
							assert(Y < Display::s_height);
							bool pixel = m_chip8.CheckPixel(Y, X);
							
							if (pixel)
							{
								m_chip8.ClearPixel(Y, X);
								VF = 1;
							}
							else
							{
								m_chip8.SetPixel(Y, X);
							}
						}

						if (X == Display::s_width - 1)
						{
							break;
						}
						X++;
					}

					Y++;
					if (Y == Display::s_height - 1)
					{
						break;
					}
				}

				m_chip8.Draw();
			};
	}

	void Executor::Execute(const Instruction instruction, const uint16_t opcode)
	{
		m_delegates[instruction](opcode);
	}
}
