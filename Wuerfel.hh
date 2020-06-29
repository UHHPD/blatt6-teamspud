#ifndef WUERFEL_HH
#define WUERFEL_HH

#include "Vektor.hh"
#include "Koerper.hh"

class Wuerfel : public Koerper { 
  public:
    std::string name(){return "Wuerfel";};
    Wuerfel(double nl);

    Vektor punkt();

  private:
  double l_;
};

#endif
