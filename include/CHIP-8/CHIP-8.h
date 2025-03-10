#include <CHIP-8/Memory.h>
#include <CHIP-8/Display.h>
#include <CHIP-8/Stack.h>
#include <CHIP-8/Timer.h>

namespace CHIP8
{
	class CHIP8
	{
	public:
		uint8_t ReadMemory(const uint16_t address) const;
		void WriteMemory(const uint16_t address, const uint8_t data);

		void SetPixel(const uint8_t row, const uint8_t col);
		void ClearPixel(const uint8_t row, const uint8_t col);
		void Draw();

		void PushStack(const uint16_t address);
		uint16_t PopStack();

	private:
		Memory m_memory;
		Display m_display;
		Stack m_stack;
		Timer m_timer;
	};
}
