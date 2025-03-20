#include <CHIP-8/Memory.h>
#include <CHIP-8/Register.h>

#include <cassert>
#include <fstream>

namespace CHIP8
{
	Memory::Memory()
	{
		LoadFonts();
	}

	uint8_t Memory::operator[](const uint16_t address) const
	{
		assert(address < m_memory.size());

		return m_memory[address];
	}

	uint8_t& Memory::operator[](const std::uint16_t address)
	{
		assert(address < m_memory.size());
		assert(address >= 0x200); // Leave the first 0x200 exclusive addresses alone (except for font loading) for compatibility

		return m_memory[address];
	}

	void Memory::LoadROM(const std::string& fileName)
	{
		std::ifstream file(fileName, std::ios_base::binary);
		assert(file);

		file.seekg(0, std::ios::end);
		size_t size = file.tellg();
		file.seekg(0, std::ios::beg);

		file.read(reinterpret_cast<char*>(&m_memory[s_startingAddress]), size); // Does strict aliasing apply here?
	}

	void Memory::LoadFonts()
	{
		static constexpr std::array<uint8_t, 80> fonts =
		{
			0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
			0x20, 0x60, 0x20, 0x20, 0x70, // 1
			0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
			0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
			0x90, 0x90, 0xF0, 0x10, 0x10, // 4
			0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
			0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
			0xF0, 0x10, 0x20, 0x40, 0x40, // 7
			0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
			0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
			0xF0, 0x90, 0xF0, 0x90, 0x90, // A
			0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
			0xF0, 0x80, 0x80, 0x80, 0xF0, // C
			0xE0, 0x90, 0x90, 0x90, 0xE0, // D
			0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
			0xF0, 0x80, 0xF0, 0x80, 0x80  // F
		};

		// Loading between 0x50 and 0x9F inclusive to follow convention
		for (uint16_t address = 0x50; address <= 0x9F; address++)
		{
			m_memory[address] = fonts[address - 0x50];
		}
	}
}
