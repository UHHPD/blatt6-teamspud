#ifndef KOERPER_HH
#define KOERPER_HH

#include "Vektor.hh"

class Koerper {
  public:
    //Vektor punkt();
    //ohne virtual wird in traegheit direkt die punkt()-Funktion auf Koerper aufgerufen. Für die 
    // steht hier aber gar kein Code. 
    // Daher meckerte g++ beim Linken: undefined reference to `Koerper::punkt()
    // Mit virtual wird dann die Punkt-Funktion von erbenden Klassen genommen und der Linker
    // ist zufrieden. Da die Implementation von punkt in Koerper nicht sinnvoll ist, sollte
    // die Funktion hier "pure virtual sein", also "=0"
    virtual Vektor punkt() = 0;
    virtual std::string name(){return "Koerper";};
};

#endif
