//[ hello_test_test_cpp1
#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "hello.hpp"
#include <sstream>

BOOST_AUTO_TEST_CASE(hello_world_inserts_text)
{
    std::ostringstream dest;

    hello_world(dest);

    BOOST_REQUIRE_EQUAL("Hello, world!\n", dest.str());
}
//]
