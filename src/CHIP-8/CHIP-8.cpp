#include <CHIP-8/CHIP-8.h>

#include <cassert>

#include <SDL3/SDL_timer.h>

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
        m_display.SetPixel(row, col);
    }

    void CHIP8::ClearPixel(const uint8_t row, const uint8_t col)
    {
        m_display.ClearPixel(row, col);
    }

    void CHIP8::ClearScreen()
    {
        m_display.Clear();
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

    Register& CHIP8::GetRegister()
    {
        return m_register;
    }

    void CHIP8::Update()
    {
        Fetch();

        SDL_DelayNS(s_delay); // To roughly match original CHIP-8 speeds
    }

    void CHIP8::Fetch()
    {
        uint16_t opcode = m_memory[m_register.programCounter];
        m_register.programCounter++;

        Decode(opcode);
    }

    void CHIP8::Decode(const uint16_t opcode)
    {
        Instruction instruction = Decoder::Decode(opcode);

        Execute(instruction, opcode);
    }

    void CHIP8::Execute(const Instruction instruction, const uint16_t opcode)
    {
        m_executor.Execute(instruction, opcode);
    }
}
