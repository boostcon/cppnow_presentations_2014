#include <boost/test/minimal.hpp>
#include "hello.hpp"
#include <ios>
#include <sstream>

static void inserts_text()
{
    std::ostringstream dest;

    hello_world(dest);

    BOOST_REQUIRE("Hello, world!\n" == dest.str());
}

static void stream_with_badbit_throws_runtime_error()
{
    std::ostringstream dest;
    dest.clear(std::ios_base::badbit);

    try
    {
        hello_world(dest);
    }

    catch (std::runtime_error const&)
    {
        return;
    }
    catch (...)
    {
        BOOST_FAIL("Unknown exception thrown.");
        return;
    }
    BOOST_FAIL("No exception thrown.");
}

int test_main(int /*argc*/, char* /*argv*/[])
{
    inserts_text();
    stream_with_badbit_throws_runtime_error();
    return 0;
}
