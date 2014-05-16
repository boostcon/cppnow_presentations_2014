#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "hello.hpp"
#include <sstream>

BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES(inserts_text_check_expected, 2)
BOOST_AUTO_TEST_CASE(inserts_text_check_expected)
{
    std::ostringstream dest;

    hello_world(dest);

    BOOST_CHECK_EQUAL("scooby-doo", dest.str());
    BOOST_CHECK_EQUAL("shaggy", dest.str());
}

BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES(inserts_text_check_exceeded, 2)
BOOST_AUTO_TEST_CASE(inserts_text_check_exceeded)
{
    std::ostringstream dest;

    hello_world(dest);

    BOOST_CHECK_EQUAL("scooby-doo", dest.str());
    BOOST_CHECK_EQUAL("shaggy", dest.str());
    BOOST_CHECK_EQUAL("SCOOBY", dest.str());
}

//[expected_failures
BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES(inserts_text_require_expected, 1)
BOOST_AUTO_TEST_CASE(inserts_text_require_expected)
{
    std::ostringstream dest;

    hello_world(dest);

    BOOST_REQUIRE_EQUAL("scooby-doo", dest.str());
}
//]
