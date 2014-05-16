#include "hello.hpp"

void hello_world(std::ostream& stream)
{
    if (stream.bad())
    {
        throw std::runtime_error("bad stream");
    }
    stream << "Hello, world!\n";
}
