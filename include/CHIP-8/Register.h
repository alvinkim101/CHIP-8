#pragma once

#include <array>

namespace CHIP8
{
	struct Register
	{
		static constexpr uint16_t s_startingAddress = 0x200;

		uint16_t programCounter{s_startingAddress};
		uint16_t index{};

		/*
		X: The second nibble.Used to look up one of the 16 registers(VX) from V0 through VF.
		Y : The third nibble.Also used to look up one of the 16 registers(VY) from V0 through VF.
		N : The fourth nibble.A 4 - bit number.
		NN : The second byte(third and fourth nibbles).An 8 - bit immediate number.
		NNN : The second, third and fourth nibbles.A 12 - bit immediate memory address.
		*/
		std::array<uint8_t, 16> variables{};
	};
}
