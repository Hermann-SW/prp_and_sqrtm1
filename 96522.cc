// g++ -O3 96522.cc paulunderwood/gw_utility.o -lgmp -lgmpxx -Lp95v3019b14/gwnum -l:gwnum.a
//
#include <gmpxx.h>
#include <iostream>

extern "C" {
#include "paulunderwood/gw_utility.h"
}

int main(int argc, char *argv[]) {
  mpz_class p43;
  mpz_primorial_ui(p43.get_mpz_t(), 43);

  mpz_class a = (5752211*p43/2-1);
  mpz_pow_ui(a.get_mpz_t(), a.get_mpz_t(), 1069);

  mpz_class p = 3*a/2+1;
  mpz_class q = 3*a+1;
  mpz_class r = 3*(a*(a+1))/1050650772710+1;

  mpz_class n = p*q*r;
  mpz_class n1 = n-1;

  a = 2;
  gw_powm(a.get_mpz_t(), a.get_mpz_t(), n1.get_mpz_t(), n.get_mpz_t());

  std::cout << a << "\n";

  return 0;
}
