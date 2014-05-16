#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN
#include <boost/test/unit_test.hpp>

bool init_function()
{
    // create test cases and suites and return a boolean indicating
    // success (true) or failure (false).
    return true;
}

int main(int argc, char* argv[])
{
    return ::boost::unit_test::unit_test_main(&init_function, argc, argv);
}
