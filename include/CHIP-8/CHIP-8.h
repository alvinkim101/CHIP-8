#include <CHIP-8/Memory.h>

namespace CHIP8
{
	class CHIP8
	{
	public:
		uint8_t ReadMemory(const uint16_t address) const;
		void WriteMemory(const uint16_t address, const uint8_t data);

	private:
		Memory m_memory;
	};
}
