#include "factors.h"

extern std::vector<int> prime_factors(int n)
{
  std::vector<int> primes;
  int candidate = 2;
  while (n > 1) {
    while (n % candidate == 0) {
      primes.push_back(candidate);
      n /= candidate;
    }
    ++candidate;
  }
  return primes;
}
