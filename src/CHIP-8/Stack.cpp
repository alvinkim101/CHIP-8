#include <CHIP-8/Stack.h>

#include <cassert>

namespace CHIP8
{
    void Stack::Push(const uint16_t address)
    {
        assert(m_stack.size() < 16); // Original interpreters had limited stack size

        m_stack.push(address);
    }

    uint16_t Stack::Pop()
    {
        assert(m_stack.size() > 0);

        uint16_t address = m_stack.top();
        m_stack.pop();
        return address;
    }
}
