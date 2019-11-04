#ifndef CARRO_H
#define CARRO_H

#include <objeto.h>

class Carro : public Objeto{

public:
    Model3DS* model;

public:
    Carro( );
    Carro(Vetor3D tn, Vetor3D an, Vetor3D sn);
    void desenha();

};

#endif // CARRO_H
