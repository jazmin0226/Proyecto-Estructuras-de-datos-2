//
// Created by roxan on 5 dic. 2021.
//

#ifndef PROYECTOEDMAPA_TABLAHASH_H
#define PROYECTOEDMAPA_TABLAHASH_H


#include "Ubicacion.h"

class TablaHash {
public:
    TablaHash();

    virtual ~TablaHash();

    void addUbicacion(int indice, Ubicacion * ptr);

    Ubicacion * getUbicacion(int indice, long num);

    enum {MAX = 15};
private:
    Ubicacion *vectorUbic[MAX];
};


#endif //PROYECTOEDMAPA_TABLAHASH_H
