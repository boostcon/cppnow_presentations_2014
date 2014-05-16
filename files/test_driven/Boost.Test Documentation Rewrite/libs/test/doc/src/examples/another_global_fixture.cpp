#include <boost/test/unit_test.hpp>

#include <iostream>

struct global3
{
    global3()
    {
        std::cout << "global3 setup\n";
    }
    ~global3()
    {
        std::cout << "global3 teardown\n";
    }
};

BOOST_GLOBAL_FIXTURE(global3);

BOOST_AUTO_TEST_CASE(three)
{
    std::cout << "three\n";

    BOOST_REQUIRE(true);
}

struct global4
{
    global4()
    {
        std::cout << "global4 setup\n";
    }
    ~global4()
    {
        std::cout << "global4 teardown\n";
    }
};

BOOST_GLOBAL_FIXTURE(global4);

BOOST_AUTO_TEST_CASE(four)
{
    std::cout << "four\n";

    BOOST_REQUIRE(true);
}
