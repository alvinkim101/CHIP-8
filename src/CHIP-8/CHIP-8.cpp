#include <CHIP-8/CHIP-8.h>

namespace CHIP8
{
    uint8_t CHIP8::ReadMemory(const uint16_t address) const
    {
        return m_memory[address];
    }

    void CHIP8::WriteMemory(const uint16_t address, const uint8_t data)
    {
        m_memory[address] = data;
    }

    void CHIP8::SetPixel(const uint8_t row, const uint8_t col)
    {
        m_display.Set(row, col);
    }

    void CHIP8::ClearPixel(const uint8_t row, const uint8_t col)
    {
        m_display.Clear(row, col);
    }

    void CHIP8::Draw()
    {
        m_display.Draw();
    }
}
