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
  ~fixture() {
    BOOST_REQUIRE_EQUAL_COLLECTIONS(
      expected.begin(), expected.end(),
      actual.begin(), actual.end());
  }
};

BOOST_FIXTURE_TEST_CASE(one_yields_empty, fixture)
{
  prime_factors(1);
}

BOOST_FIXTURE_TEST_CASE(two_yields_2, fixture)
{
  expected.push_back(2);

  prime_factors(2);
}

BOOST_FIXTURE_TEST_CASE(three_yields_3, fixture)
{
  expected.push_back(3);

  prime_factors(3);
}

BOOST_FIXTURE_TEST_CASE(four_yields_2_2, fixture)
{
  expected.push_back(2);
  expected.push_back(2);

  prime_factors(4);
}

BOOST_FIXTURE_TEST_CASE(six_yields_2_3, fixture)
{
  expected.push_back(2);
  expected.push_back(3);

  prime_factors(6);
}

BOOST_FIXTURE_TEST_CASE(eight_yields_2_2_2, fixture)
{
  expected.push_back(2);
  expected.push_back(2);
  expected.push_back(2);

  prime_factors(8);
}

BOOST_FIXTURE_TEST_CASE(nine_yields_3_3, fixture)
{
  expected.push_back(3);
  expected.push_back(3);

  prime_factors(9);
}
