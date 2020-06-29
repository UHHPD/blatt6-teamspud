#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include "Koerper.hh"
#include "Kugel.hh"
#include "Wuerfel.hh"
#include <iostream>
#include <memory>
#include <cmath>
#include <fstream>

double traegheit(Koerper* k, Vektor a, Vektor u, double M) {
  std::cout << "berechne für " << k->name() << "\n";
  const int N = 10000;     // Anzahl Integrationspunkte

  double J = 0;     // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
     Vektor x = k->punkt();
     Vektor Abstand = x-a;//Abstand Punkt x und Gerade a + t*u
     Vektor Normal = Abstand.kreuz(u);//Vektor n = ...;//Normalenvektor x-a kreuz u
     double r = Normal.betrag()/u.betrag(); //|n|/|u|
        // std::cout << x << " :" << r << std::endl;
        // addiere Beitrag des Massenpunktes zum Traegheitsmoment
      J += m * r * r;
    }
  return J;
}

int main() {
  const double M = 1;      // Masse des Zylindermantels
  const double ZM_R = 1.0; // Radius des Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels
  const double VZ_R = 1.0; // Radius des Vollzylinders
  const double VZ_L = 1.0; // Laenge des Vollzylinders
  const double Kantenlaenge = 1.0; //Länge einer Würfelkante

  using namespace std;

  ofstream fout("Ergebnisse.txt");
  fout << "R     " << "L      " << "M     " << "      a " << "      u " << "J ZM analyt. " << "J ZM berechnet " << "J VZ analyt. " << "J VZ berechnet " << "J KU analyt. " << "J KU berechnet" << "J WU analyt. " << "J WU berechnet" << std::endl;

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  for (double M = 1; M <= 2; M++) {
    for (double Radius = 1; Radius <= 2; Radius++){
      std::unique_ptr<Koerper> k(new Zylindermantel(Radius, ZM_L));
      double J_ZM = traegheit(k.get(),a,u,M);

      std::unique_ptr<Koerper> k2(new Vollzylinder(Radius, VZ_L));
      double J_VZ = traegheit(k2.get(),a,u,M);

      std::unique_ptr<Koerper> k3(new Kugel(Radius));
      double J_KU = traegheit(k3.get(),a,u,M);

      std::unique_ptr<Koerper> k4(new Wuerfel(Kantenlaenge));
      double J_WU = traegheit(k4.get(),a,u,M);

      double J_analytisch_ZM = M*pow(Radius,2)+M*a.betrag()*a.betrag();
      double J_analytisch_VZ = 0.5*M*pow(Radius,2)+M*a.betrag()*a.betrag();
      double J_analytisch_KU = 2*M*pow(Radius,2)/5+M*a.betrag()*a.betrag();
      double J_analytisch_WU = M*pow(Kantenlaenge,2)/6+M*a.betrag()*a.betrag();

      if (Radius != 2 || M != 2) {
        fout << Radius << " m   " << "1 m   " << M << " kg   " << "(" << a.x() << "," << a.y() << "," << a.z() << ")" << "  (" << u.x() << "," << u.y() << "," << u.z() << ")  " << J_analytisch_ZM << "               " << J_ZM << "            " << J_analytisch_VZ << "        " << J_VZ << "     " << J_analytisch_KU << "         " << J_KU << "         " << J_analytisch_WU << "         " << J_WU << std::endl;
      }
    }  
  } 
  //std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            //<< " mit a = " << a << " und u = " << u << ": " << J << std::endl;
  //std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            //<< " mit a = " << a << " und u = " << u << ": " << J2 << std::endl;
  return 0;
}
