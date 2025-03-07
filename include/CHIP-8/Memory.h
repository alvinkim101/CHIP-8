#include <array>

namespace CHIP8
{
	class Memory
	{
	private:
		static constexpr uint16_t s_bytes = 4096;

	public:
		Memory();

		uint8_t operator[](const uint16_t address) const;
		uint8_t& operator[](const uint16_t address);

	private:
		void LoadFonts();

		std::array<uint8_t, s_bytes> m_memory;
	};
}
