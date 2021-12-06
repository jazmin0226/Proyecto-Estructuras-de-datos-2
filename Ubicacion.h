//
// Created by roxan on 5 dic. 2021.
//

#ifndef PROYECTOEDMAPA_UBICACION_H
#define PROYECTOEDMAPA_UBICACION_H


#include <iostream>
using namespace std;

class Ubicacion {
public:
    Ubicacion(long num, const string &nombre, Ubicacion *next = nullptr);

    virtual ~Ubicacion();

    long getNum() const;

    void setNum(long num);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    Ubicacion *getNext() const;

    void setNext(Ubicacion *next);

private:
    long num;
    string nombre;
    Ubicacion * next;
};


#endif //PROYECTOEDMAPA_UBICACION_H
