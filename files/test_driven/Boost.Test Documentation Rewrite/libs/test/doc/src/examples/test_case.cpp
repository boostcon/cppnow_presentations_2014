//[test_case
#define BOOST_TEST_NO_MAIN
#include <boost/test/included/unit_test.hpp>
#include "hello.hpp"
#include <sstream>

using namespace boost::unit_test;

static void inserts_text()
{
    std::ostringstream dest;

    hello_world(dest);

    BOOST_REQUIRE_EQUAL("Hello, world!\n", dest.str());
}

static test_suite*
init(int argc, char* argv[])
{
    framework::master_test_suite().add(BOOST_TEST_CASE(inserts_text));
    return 0;
}

int main(int argc, char* argv[])
{
    return unit_test_main(init, argc, argv);
}
//]
