#define BOOST_TEST_MODULE auto_test_case_template
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

//[auto_test_case_template
#include <boost/mpl/list.hpp>
#include <limits>

typedef boost::mpl::list<
    unsigned char, unsigned short,
    unsigned int,
    unsigned long, unsigned long long> unsigned_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(not_is_signed_for_unsigned_types, T, unsigned_types)
{
    BOOST_REQUIRE(!std::numeric_limits<T>::is_signed);
}
//]

typedef boost::mpl::list<
    char, short,
    int,
    long, long long> signed_types;
BOOST_AUTO_TEST_CASE_TEMPLATE(is_signed_for_signed_types, T, signed_types)
{
    BOOST_REQUIRE(std::numeric_limits<T>::is_signed);
}
