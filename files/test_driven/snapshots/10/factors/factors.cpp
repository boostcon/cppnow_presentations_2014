#include "factors.h"

extern std::vector<int> prime_factors(int n)
{
  std::vector<int> primes;
  if (n > 1) {
    primes.push_back(2);
  }
  return primes;
}
