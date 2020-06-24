#include "Kugel.hh"
#include "Koerper.hh"

#include <cmath>
#include <cstdlib>


Kugel::Kugel(double nr) {
   r_ = nr;
}

Vektor Kugel::punkt() {
  double R = r_*pow(rand()/(double)RAND_MAX,(1.0/3.0)); //ich bin mir an dieser Stelle nicht ganz sicher ob die Verteilungsfunktion von einer Kugel r^2 ist
  double phi = 2 * M_PI * (rand() / (double)RAND_MAX);
  // Bei Theta 0 liegen mehr Punkte als bei Theta nahe pi. Das Volumenelement in Kugelkoordinaten lautet r^2 dr sin(theta) dtheta dphi. 
  // Die Thetawerte müssten also gemäß sin(theta) verteilt sein. Das Integral wäre cos(theta) und die Umkehrfunktion dann acos(u)
  double u = 2 * (rand() / (double)RAND_MAX) -1;//2 *rand() ergibt wohl eine Zahl, die zu groß für int ist und dann negativ wird, weil das Vorzeichenbit überschrieben wird. Daher muss immer zuerst durch RAND_MAX geteilt werden. Das wusste ich vorher auch nicht. So etwas ist aber leider vom Betriebssystem und der CPU abhängig.
  double theta = acos(u);
  double x = R*cos(phi)*sin(theta);
  double y = R*sin(phi)*sin(theta);
  double z = R*cos(theta);


  return Vektor(x, y, z);
};
