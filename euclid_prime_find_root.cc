// transpiled from seq.gp
// https://gist.github.com/Hermann-SW/b4d422842b22da4d5f2838a211f38e02
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
  assert(argc > 1);
  int n = atoi(argv[1]);
  P = new ut[n+1];
  assert(P);

  for (int i=1; i <= n; ++i) {
    mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());
    P[i] = mpz_get_ui(p.get_mpz_t());
  }

  mpz_primorial_ui(Enm1.get_mpz_t(), mpz_get_ui(p.get_mpz_t()));
  En = Enm1 + 1;

  for (ut g=2; ; ++g) {
    if (mpz_ui_kronecker(g, En.get_mpz_t()) == -1) {
      bool is_root = true;
      mpz_class G(g);
      for (int i=1; i <= n; ++i) {
        mpz_divexact_ui(E.get_mpz_t(), Enm1.get_mpz_t(), P[i]);
        gw_powm(r.get_mpz_t(), G.get_mpz_t(), E.get_mpz_t(), En.get_mpz_t());
        if (r == 1) {
          is_root = false;
          break;
        }
      }
      if (is_root) {
        std::cout << g << "\n";
        return 0;
      }
    }
  }
}
