#include <CHIP-8/CHIP-8.h>

#include <cassert>

namespace CHIP8
{
    uint16_t CHIP8::ReadMemory(const uint16_t address) const
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

    void CHIP8::PushStack(const uint16_t address)
    {
        m_stack.Push(address);
    }

    uint16_t CHIP8::PopStack()
    {
        return m_stack.Pop();
    }

    void CHIP8::PressKey(const SDL_Scancode scancode)
    {
        m_keypad.Press(scancode);
    }

    void CHIP8::ReleaseKey()
    {
        m_keypad.Release();
    }
}
