#define BOOST_TEST_NO_MAIN
#include <boost/test/included/unit_test.hpp>
#include <sstream>

using namespace boost::unit_test;

typedef boost::mpl::list<
    unsigned char, unsigned short,
    unsigned int,
    unsigned long, unsigned long long> unsigned_types;
BOOST_TEST_CASE_TEMPLATE_FUNCTION(not_is_signed_for_unsigned_types, T)
{
    BOOST_REQUIRE(!std::numeric_limits<T>::is_signed);
}

//[test_case_template_function
typedef boost::mpl::list<
    char, short,
    int,
    long, long long> signed_types;

BOOST_TEST_CASE_TEMPLATE_FUNCTION(is_signed_for_signed_types, T)
{
    BOOST_REQUIRE(std::numeric_limits<T>::is_signed);
}
//]

//[test_case_template
static test_suite*
init(int argc, char* argv[])
{
    test_suite& suite(framework::master_test_suite());
    suite.add(BOOST_TEST_CASE_TEMPLATE(not_is_signed_for_unsigned_types, unsigned_types));
    suite.add(BOOST_TEST_CASE_TEMPLATE(is_signed_for_signed_types, signed_types));
    return 0;
}

int main(int argc, char* argv[])
{
    return unit_test_main(init, argc, argv);
}
//]
