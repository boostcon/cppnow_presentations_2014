#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "factors.h"

using namespace std;

BOOST_AUTO_TEST_CASE(one_yields_empty)
{
  vector<int> expected;

  vector<int> actual = prime_factors(1);

  BOOST_REQUIRE_EQUAL_COLLECTIONS(
    expected.begin(), expected.end(),
    actual.begin(), actual.end());
}
