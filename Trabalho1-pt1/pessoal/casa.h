#ifndef CASA_H
#define CASA_H

#include <objeto.h>

class Casa : public Objeto{

public:
    Model3DS* model;
    Casa(int i);
    void desenha();
};

#endif // CASA_H
