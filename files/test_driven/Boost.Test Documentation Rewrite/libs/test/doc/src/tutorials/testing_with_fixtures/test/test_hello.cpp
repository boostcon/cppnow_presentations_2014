#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "hello.hpp"
#include <ios>
#include <sstream>

//[testing_with_fixtures_test_cpp
struct hello_world_fixture
{
    std::ostringstream dest;
};

#define HELLO_WORLD_TEST_CASE(name_) \
    BOOST_FIXTURE_TEST_CASE(hello_world_##name_, hello_world_fixture)

HELLO_WORLD_TEST_CASE(inserts_text)
{
    hello_world(dest);

    BOOST_REQUIRE_EQUAL("Hello, world!\n", dest.str());
}

HELLO_WORLD_TEST_CASE(stream_with_badbit_throws_runtime_error)
{
    dest.clear(std::ios_base::badbit);

    BOOST_REQUIRE_THROW(hello_world(dest), std::runtime_error);
}
//]
