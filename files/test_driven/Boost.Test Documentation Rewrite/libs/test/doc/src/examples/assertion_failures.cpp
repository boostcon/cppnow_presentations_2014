#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include <stdexcept>

//[example_fail
BOOST_AUTO_TEST_CASE(example_fail)
{
    BOOST_FAIL("This should never happen.");
}
//]

//[example_passpoint
BOOST_AUTO_TEST_CASE(example_passpoint)
{
    BOOST_TEST_PASSPOINT();

    throw std::runtime_error("Oops");
}
//]
