#include <stack>

namespace CHIP8
{
	class Stack
	{
	public:
		void Push(const uint16_t address);
		uint16_t Pop();

	private:
		std::stack<uint16_t> m_stack;
	};
}
