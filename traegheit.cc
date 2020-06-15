#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>
#include <cmath>
#include <fstream>


int main() {
  const int N = 10000;     // Anzahl Integrationspunkte
  const double M = 1;      // Masse des Zylindermantels
  const double ZM_R = 1.0; // Radius des Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels
  const double VZ_R = 1.0; // Radius des Vollzylinders
  const double VZ_L = 1.0; // Laenge des Vollzylinders

  using namespace std;

  ofstream fout("Ergebnisse.txt");
  fout << "R     " << "L      " << "M     " << "      a " << "      u " << "J ZM analyt. " << "J ZM berechnet " << "J VZ analyt. " << "J VZ berechnet" << std::endl;

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  for (double M = 1; M <= 2; M++) {
    for (double Radius = 1; Radius <= 2; Radius++){
      std::unique_ptr<Zylindermantel> zm(new Zylindermantel(Radius, ZM_L));
      std::unique_ptr<Vollzylinder> vz(new Vollzylinder(Radius, VZ_L));
      double J = 0;     // Massentraegheitsmoment
      double m = M / N; // Masse eines Massenpunktes
      for (int i = 0; i < N; ++i) {
        Vektor x = zm->punkt();
        Vektor Abstand = x-a;//Abstand Punkt x und Gerade a + t*u
        Vektor Normal = Abstand.kreuz(u);
        //Vektor n = ...;//Normalenvektor x-a kreuz u
        double r = Normal.betrag()/u.betrag(); //|n|/|u|
        // std::cout << x << " :" << r << std::endl;
        // addiere Beitrag des Massenpunktes zum Traegheitsmoment
        J += m * r * r;
      }
      double Janalytisch = M*pow(Radius,2)+M*a.betrag()*a.betrag();
      
      double J2 = 0;     // Massentraegheitsmoment
      int Anzahl = 0;
      for (int i = 0; i < N; ++i) {
        Vektor b = vz->punkt();
        Vektor Abstand2 = b-a;//Abstand Punkt x und Gerade a + t*u
        Vektor Normal2 = Abstand2.kreuz(u);
        //Vektor n = ...;//Normalenvektor x-a kreuz u
        double r2 = Normal2.betrag()/u.betrag(); //|n|/|u|
        // std::cout << x << " :" << r << std::endl;
        // addiere Beitrag des Massenpunktes zum Traegheitsmoment
        J2 += m * r2 * r2;
        }
      double J2analytisch = 0.5*M*pow(Radius,2)+M*a.betrag()*a.betrag();

      if (Radius != 2 || M != 2) {
        fout << Radius << " m   " << "1 m   " << M << " kg   " << "(" << a.x() << "," << a.y() << "," << a.z() << ")" << "  (" << u.x() << "," << u.y() << "," << u.z() << ")  " << Janalytisch << "               " << J << "            " << J2analytisch << "           " << J2 << std::endl;
      }
    }  
  } 
  //std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            //<< " mit a = " << a << " und u = " << u << ": " << J << std::endl;
  //std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            //<< " mit a = " << a << " und u = " << u << ": " << J2 << std::endl;
  return 0;
}
