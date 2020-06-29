#ifndef VOLLZYLINDER_HH
#define VOLLZYLINDER_HH

#include "Vektor.hh"
#include "Koerper.hh"

class Vollzylinder : public Koerper { 
  public:
    std::string name(){return "Vollzylinder";};
    Vollzylinder(double nr, double nl);

    Vektor punkt();

  private:
    double r_, l_;
};

#endif
