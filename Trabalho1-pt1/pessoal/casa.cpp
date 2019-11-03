#include "casa.h"

Casa::Casa(  ) : Objeto( 2 ){
    model = new Model3DS("../3ds/cabanaHouse.3ds");
}

Casa::Casa( Vetor3D tn, Vetor3D an, Vetor3D sn ) : Objeto( 2 ){
    t = tn; a = an; s = sn;
    origem = false;
    model = new Model3DS("../3ds/cabanaHouse.3ds");
};

void Casa::desenha(){

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0.46, 0, 0);
            glRotatef(180, 0, 1, 0);
            glRotatef(-90, 1, 0, 0);

            glScalef(2, 2, 2);
            glScalef(0.005,0.005,0.005);
            //model->draw();
            GLUquadric* quadric = gluNewQuadric();
            Desenha::gluCapsule(quadric,20,20,20,20,20);
            gluDeleteQuadric(quadric);
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                glRotatef(-90,1,0,0);
                GUI::setColor(0, 0, 0.9, 0.35);
                GUI::drawBox(-0.012, -0.615, 0.001, 0.472, 0.015, 0.45);
            }
        glPopMatrix();
    glPopMatrix();
}

