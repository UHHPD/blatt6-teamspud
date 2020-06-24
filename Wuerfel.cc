#include "Wuerfel.hh"
#include "Koerper.hh"

#include <cmath>
#include <cstdlib>

Wuerfel::Wuerfel(double nl) {
   l_ = nl;
}

Vektor Wuerfel::punkt() {
  double x = l_ * (rand() / (double)RAND_MAX - 0.5);
  double y = l_ * (rand() / (double)RAND_MAX - 0.5);
  double z = l_ * (rand() / (double)RAND_MAX - 0.5);

  return Vektor(x, y, z);
};
