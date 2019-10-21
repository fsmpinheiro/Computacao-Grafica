#ifndef CASA_H
#define CASA_H

#include <objeto.h>

class Casa : public Objeto{

public:
    Model3DS* model;
    Casa();
    Casa( Vetor3D tn, Vetor3D an, Vetor3D sn);
    void desenha();
};

#endif // CASA_H
