#include "factors.h"

extern std::vector<int> prime_factors(int n)
{
  std::vector<int> primes;
  if (n > 1) {
    if (n % 2 == 0) {
      primes.push_back(2);
      n /= 2;
    }
    if (n > 1) {
      primes.push_back(n);
    }
  }
  return primes;
}
