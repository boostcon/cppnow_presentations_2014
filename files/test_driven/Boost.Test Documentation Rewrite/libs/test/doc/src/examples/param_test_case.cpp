#define BOOST_TEST_NO_MAIN
#include <boost/test/included/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
#include "hello.hpp"
#include <sstream>

//[param_test_case
using namespace boost::unit_test;

static void does_not_insert_text(std::string const& text)
{
    std::ostringstream dest;

    hello_world(dest);

    BOOST_REQUIRE_NE(text, dest.str());
}

static std::vector<std::string> text;

static test_suite*
init(int argc, char* argv[])
{
    text.push_back("scooby");
    text.push_back("shaggy");
    text.push_back("foo");
    text.push_back("arg");
    framework::master_test_suite()
        .add(BOOST_PARAM_TEST_CASE(does_not_insert_text, text.begin(), text.end()));
    return 0;
}

int main(int argc, char* argv[])
{
    return unit_test_main(init, argc, argv);
}
//]
