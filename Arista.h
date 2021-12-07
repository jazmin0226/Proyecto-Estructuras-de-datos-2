//
// Created by Jazmin Roxana Arias Salazar on 5 dic. 2021.
//

#ifndef PROYECTOEDMAPA_ARISTA_H
#define PROYECTOEDMAPA_ARISTA_H

class Vertice;
#include <string>

using namespace std;
class Arista {
public:

    Arista(int peso, const string &nombre, Vertice *ady, Arista *sig = nullptr,
           Vertice *prev = nullptr, Arista *ant = nullptr);

    virtual ~Arista();

    float getPeso() const;

    void setPeso(float peso);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    Arista *getSig() const;

    void setSig(Arista *sig);

    Vertice *getAdy() const;

    void setAdy(Vertice *ady);

    Vertice *getPrev() const;

    void setPrev(Vertice *prev);

    Arista *getAnt() const;

    void setAnt(Arista *ant);

private:
    float peso;
    string nombre;
    Vertice *ady;
    Arista *sig;
    Vertice *prev;
    Arista *ant;
};


#endif //PROYECTOEDMAPA_ARISTA_H
