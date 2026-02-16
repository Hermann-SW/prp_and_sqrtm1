// Implementation of theorem 1 with primitive root instead differnt a_i:
// https://t5k.org/prove/prove3_1.html
//
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include <gmpxx.h>
#include <iostream>

extern "C" {
#include "paulunderwood/gw_utility.h"
}

typedef uint64_t ut;

int main(int argc, char *argv[]) {
  mpz_class En, Enm1, p, r, E, one(1);
  ut *P;
  assert(argc == 3);
  int n = atoi(argv[1]);
  ut g = atol(argv[2]);
  P = new ut[n+1];
  assert(P);

  for (int i=1; i <= n; ++i) {
    mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());
    P[i] = mpz_get_ui(p.get_mpz_t());
  }

  mpz_primorial_ui(Enm1.get_mpz_t(), mpz_get_ui(p.get_mpz_t()));
  En = Enm1 + 1;

  bool is_prime = true;
  mpz_class G(g);

  for (int i=1; i <= n; ++i) {
    mpz_divexact_ui(E.get_mpz_t(), Enm1.get_mpz_t(), P[i]);
    gw_powm(r.get_mpz_t(), G.get_mpz_t(), E.get_mpz_t(), En.get_mpz_t());
    if (r == 1) {
      is_prime = false;
      break;
    }
  }
  if (is_prime) {
    gw_powm(r.get_mpz_t(), G.get_mpz_t(), Enm1.get_mpz_t(), En.get_mpz_t());
    is_prime = (r == 1);
  }

  std::cout << "is " << (is_prime?"":"no ") << "prime\n";

  return 0;
}
