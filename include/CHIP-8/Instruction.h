#pragma once

namespace CHIP8
{
	enum class Instruction
	{
		NoOperation,
		ClearScreen,
		Jump,
		SetRegisterVX,
		AddValueToRegisterVX,
		SetIndexRegisterI,
		Draw
	};
}
