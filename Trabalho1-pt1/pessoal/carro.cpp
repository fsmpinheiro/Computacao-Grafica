#include "carro.h"

Carro::Carro() : Objeto( 1 ){
    model = new Model3DS("../3ds/bmwX5_4.3ds");
}

Carro::Carro(Vetor3D tn, Vetor3D an, Vetor3D sn) : Objeto( 1 ){
    t = tn; a = an; s = sn;
    origem = false;
    model = new Model3DS("../3ds/bmwX5_4.3ds");
};

void Carro::desenha(){

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0,0,0);
            glRotatef(-90,1,0,0);
            glScalef(2, 2, 2);
            glScalef(0.001,0.001,0.001);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                glRotatef(-90,1,0,0);
                GUI::setColor(0, 0, 0.9, 0.35);
                GUI::drawBox(-0.185, -0.085, 0, 0.185, 0.085, 0.14);
            }
        glPopMatrix();
    glPopMatrix();
}
