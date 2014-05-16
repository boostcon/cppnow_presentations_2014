#define BOOST_TEST_NO_MAIN
#include <boost/test/unit_test.hpp>
#include "hello.hpp"
#include <ios>
#include <sstream>

struct hello_world_fixture
{
    std::ostringstream dest;
};

BOOST_FIXTURE_TEST_SUITE(test_hello_world, hello_world_fixture);

BOOST_AUTO_TEST_CASE(inserts_text)
{
    hello_world(dest);

    BOOST_REQUIRE_EQUAL("Hello, world!\n", dest.str());
}

BOOST_AUTO_TEST_CASE(stream_with_badbit_throws_runtime_error)
{
    dest.clear(std::ios_base::badbit);

    BOOST_REQUIRE_THROW(hello_world(dest), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END();
