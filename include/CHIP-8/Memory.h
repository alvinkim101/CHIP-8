#pragma once

#include <array>
#include <string>

namespace CHIP8
{
	class Memory
	{
	public:
		static constexpr uint16_t s_startingAddress = 0x200;

	private:
		static constexpr uint16_t s_bytes = 4096;

	public:
		Memory();

		uint8_t operator[](const uint16_t address) const;
		uint8_t& operator[](const uint16_t address);

		void LoadROM(const std::string& fileName);

	private:
		void LoadFonts();

		std::array<uint8_t, s_bytes> m_memory;
	};
}
