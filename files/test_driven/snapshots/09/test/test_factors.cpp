#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "factors.h"

using namespace std;

struct fixture {
  vector<int> expected;
  vector<int> actual;
};

BOOST_AUTO_TEST_CASE(one_yields_empty)
{
  fixture f;

  f.actual = prime_factors(1);

  BOOST_REQUIRE_EQUAL_COLLECTIONS(
    begin(f.expected), end(f.expected),
    begin(f.actual), end(f.actual));
}

BOOST_AUTO_TEST_CASE(two_yields_2)
{
  vector<int> expected;
  expected.push_back(2);

  vector<int> actual = prime_factors(2);

  BOOST_REQUIRE_EQUAL_COLLECTIONS(
    expected.begin(), expected.end(),
    actual.begin(), actual.end());
}
