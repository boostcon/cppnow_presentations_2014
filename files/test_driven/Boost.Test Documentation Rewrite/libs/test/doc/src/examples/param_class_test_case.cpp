#define BOOST_TEST_NO_MAIN
#include <boost/test/included/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
#include "hello.hpp"
#include <sstream>

//[param_class_test_case
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost::unit_test;

class hello_world_tester
{
public:
    hello_world_tester()
    {
        eq_items.push_back("Hello, world!\n");
        eq_items.push_back("Hello, world!\n");
        ne_items.push_back("shaggy");
        ne_items.push_back("scooby");
    }

    void inserts_text(std::string const& text)
    {
        std::ostringstream dest;

        hello_world(dest);

        BOOST_REQUIRE_EQUAL(text, dest.str());
    };

    void does_not_insert_text(std::string const& text)
    {
        std::ostringstream dest;

        hello_world(dest);

        BOOST_REQUIRE_NE(text, dest.str());
    }

    std::vector<std::string> eq_items;
    std::vector<std::string> ne_items;
};

boost::shared_ptr<hello_world_tester> tester(boost::make_shared<hello_world_tester>());

static test_suite*
init(int argc, char* argv[])
{
    test_suite& suite = framework::master_test_suite();
    suite.add(BOOST_PARAM_CLASS_TEST_CASE(
        &hello_world_tester::inserts_text, tester,
        tester->eq_items.begin(), tester->eq_items.end()));
    suite.add(BOOST_PARAM_CLASS_TEST_CASE(
        &hello_world_tester::does_not_insert_text, tester,
        tester->ne_items.begin(), tester->ne_items.end()));
    return 0;
}

int main(int argc, char* argv[])
{
    return unit_test_main(init, argc, argv);
}
//]
