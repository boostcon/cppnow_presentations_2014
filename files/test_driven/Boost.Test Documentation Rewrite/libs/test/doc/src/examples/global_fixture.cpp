#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include <iostream>

//[global_fixture
struct global_fixture
{
    global_fixture()
    {
        std::cout << "global setup\n";
    }
    ~global_fixture()
    {
        std::cout << "global teardown\n";
    }
};

BOOST_GLOBAL_FIXTURE(global_fixture);
//]

struct suite_fixture
{
    suite_fixture()
    {
        std::cout << "suite setup\n";
    }
    ~suite_fixture()
    {
        std::cout << "suite teardown\n";
    }
};

BOOST_FIXTURE_TEST_SUITE(suite, suite_fixture);

BOOST_AUTO_TEST_CASE(one)
{
    std::cout << "one\n";

    BOOST_REQUIRE(true);
}

struct global2
{
    global2()
    {
        std::cout << "global2 setup\n";
    }
    ~global2()
    {
        std::cout << "global2 teardown\n";
    }
};

BOOST_GLOBAL_FIXTURE(global2);

BOOST_AUTO_TEST_CASE(two)
{
    std::cout << "two\n";

    BOOST_REQUIRE(true);
}

BOOST_AUTO_TEST_SUITE_END();
