#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "hello.hpp"
#include <ios>
#include <sstream>

BOOST_AUTO_TEST_CASE(hello_world_inserts_text)
{
    std::ostringstream dest;

    hello_world(dest);

    BOOST_REQUIRE_EQUAL("Hello, world!\n", dest.str());
}

//[ hello_world_stream_with_badbit_throws_runtime_error_1
BOOST_AUTO_TEST_CASE(hello_world_stream_with_badbit_throws_runtime_error)
{
    std::ostringstream dest;
    dest.clear(std::ios_base::badbit);

    hello_world(dest);

    BOOST_FAIL("std::runtime_error not thrown");
}
//]
