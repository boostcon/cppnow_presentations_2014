#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "hello.hpp"
#include <ios>
#include <sstream>

//[testing_with_fixtures_test_cpp_1
struct hello_world_fixture
{
    hello_world_fixture()
        : dest()
    { }
    ~hello_world_fixture()
    { }

    std::ostringstream dest;
};

BOOST_FIXTURE_TEST_CASE(hello_world_inserts_text, hello_world_fixture)
{
    hello_world(dest);

    BOOST_REQUIRE_EQUAL("Hello, world!\n", dest.str());
}

BOOST_FIXTURE_TEST_CASE(hello_world_stream_with_badbit_throws_runtime_error, hello_world_fixture)
{
    dest.clear(std::ios_base::badbit);

    BOOST_REQUIRE_THROW(hello_world(dest), std::runtime_error);
}
//]
