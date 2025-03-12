#pragma once

#include <array>

namespace CHIP8
{
	struct Register
	{
		static constexpr uint16_t s_startingAddress = 0x200;

		uint16_t programCounter{s_startingAddress};
		uint16_t index{};
		std::array<uint8_t, 16> variables{};
	};
}
