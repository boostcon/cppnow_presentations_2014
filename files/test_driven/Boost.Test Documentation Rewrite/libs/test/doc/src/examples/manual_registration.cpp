#define BOOST_TEST_NO_MAIN
#include <boost/test/included/unit_test.hpp>
#include "hello.hpp"

using namespace boost::unit_test;

//[register_function
static void inserts_text()
{
    std::ostringstream dest;

    hello_world(dest);

    BOOST_REQUIRE_EQUAL("Hello, world!\n", dest.str());
}

static void register_function(test_suite& suite)
{
    suite.add(BOOST_TEST_CASE(inserts_text));
}
//]

//[hello_fixture
class hello_fixture
{
public:
    void stream_with_badbit_throws_runtime_error()
    {
        dest.clear(std::ios_base::badbit);

        BOOST_REQUIRE_THROW(hello_world(dest), std::runtime_error);
    }

    std::ostringstream dest;
};
//]

//[register_method_static_instance
static hello_fixture hf;

static void register_method_static_instance(test_suite& suite)
{
    suite.add(BOOST_TEST_CASE(
        boost::bind(&hello_fixture::stream_with_badbit_throws_runtime_error,
            &hf)));
}
//]

//[register_method_function_instance
static void stream_with_badbit_throws_runtime_error()
{
    hello_fixture().stream_with_badbit_throws_runtime_error();
};

static void register_method_function_instance(test_suite& suite)
{
    suite.add(BOOST_TEST_CASE(stream_with_badbit_throws_runtime_error));
}
//]

//[register_test_suite
static test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    test_suite* hello_suite = BOOST_TEST_SUITE("hello");
    register_function(*hello_suite);
    register_method_static_instance(*hello_suite);
    register_method_function_instance(*hello_suite);
    framework::master_test_suite().add(hello_suite);
    return 0;
}
//]

int main(int argc, char* argv[])
{
    return unit_test_main(init_unit_test_suite, argc, argv);
}
