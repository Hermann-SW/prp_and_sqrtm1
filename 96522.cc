// NOLINT(legal/copyright)
//
// @Neptune's largest known 3-Carmichael number:
// https://www.mersenneforum.org/node/22080/page3#post1066763
/*
   LIBS="-lgmp -lgmpxx -Lp95v3019b14/gwnum -l:gwnum.a"
   g++ -O3 96522.cc paulunderwood/gw_utility.o $LIBS
*/
#include <gmpxx.h>
#include <iostream>

extern "C" {
#include "paulunderwood/gw_utility.h"
}

#define _(v) (v).get_mpz_t()

int main(int argc, char *argv[]) {
  mpz_class p43;
  mpz_primorial_ui(_(p43), 43);

  mpz_class a = 5752211*p43/2-1;
  mpz_pow_ui(_(a), _(a), 1069);

  mpz_class p = 3*a/2+1;
  mpz_class q = 3*a+1;
  mpz_class r = 3*(a*(a+1))/1050650772710+1;

  mpz_class n = p*q*r;
  mpz_class n1 = n-1;

  srandom(time(NULL));
  a = 2+random();
  gw_powm(_(a), _(a), _(n1), _(n));

  std::cout << a << "\n";

  return 0;
}
