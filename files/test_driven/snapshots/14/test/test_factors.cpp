#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include "factors.h"

using namespace std;

struct fixture {
  vector<int> expected;
  vector<int> actual;
  void prime_factors(int n) {
    actual = ::prime_factors(n);
  }
  void verify_expected_factors() {
    BOOST_REQUIRE_EQUAL_COLLECTIONS(
      expected.begin(), expected.end(),
      actual.begin(), actual.end());
  }
};

BOOST_FIXTURE_TEST_CASE(one_yields_empty, fixture)
{
  prime_factors(1);

  verify_expected_factors();
}

BOOST_FIXTURE_TEST_CASE(two_yields_2, fixture)
{
  expected.push_back(2);

  prime_factors(2);

  verify_expected_factors();
}

BOOST_FIXTURE_TEST_CASE(three_yields_3, fixture)
{
  expected.push_back(3);

  prime_factors(3);

  verify_expected_factors();
}
