#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <objeto.h>
#include "Desenha.h"

class Personagem : public Objeto{

public:

    Personagem( );
    Personagem(Vetor3D tn, Vetor3D an, Vetor3D s);
    void desenha();
};

#endif // PERSONAGEM_H
