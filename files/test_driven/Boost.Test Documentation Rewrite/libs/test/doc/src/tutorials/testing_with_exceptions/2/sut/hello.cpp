#include "hello.hpp"

//[ testing_with_exceptions_sut_hello_cpp_2
void hello_world(std::ostream& stream)
{
    if (stream.bad())
    {
        throw std::runtime_error("bad stream");
    }
    stream << "Hello, world!\n";
}
//]
