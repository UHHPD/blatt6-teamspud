#include "Kugel.hh"
#include "Koerper.hh"

#include <cmath>
#include <cstdlib>


Kugel::Kugel(double nr) {
   r_ = nr;
}

Vektor Kugel::punkt() {
  double R = r_*pow(rand()/(double)RAND_MAX,(1.0/3.0)); //ich bin mir an dieser Stelle nicht ganz sicher ob die Verteilungsfunktion von einer Kugel r^2 ist
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double theta = M_PI * rand() / (double)RAND_MAX;

  double x = R*cos(phi)*sin(theta);
  double y = R*sin(phi)*sin(theta);
  double z = R*cos(theta);


  return Vektor(x, y, z);
};
