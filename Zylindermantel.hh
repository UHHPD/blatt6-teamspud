#ifndef ZYLINDERMANTEL_HH
#define ZYLINDERMANTEL_HH

#include "Vektor.hh"
#include "Koerper.hh"

class Zylindermantel : public Koerper { 
  public:
    std::string name(){return "Zylindermantel";};
    Zylindermantel(double nr, double nl);

    Vektor punkt();

  private:
  double r_, l_;
};

#endif
