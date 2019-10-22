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
            model->draw();
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


    /*glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            GUI::setColor(1,0,0);
        } else {
            GUI::setColor(1,1,0);
        }
        //face frente
        glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glVertex3f(1,0,1);
            glVertex3f(1,1,1);
            glVertex3f(0,1,1);
        glEnd();
        //face tras
        glBegin(GL_QUADS);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glVertex3f(0,1,0);
            glVertex3f(1,1,0);
            glVertex3f(1,0,0);
        glEnd();
        //face direita
        glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            glVertex3f(1,0,1);
            glVertex3f(1,0,0);
            glVertex3f(1,1,0);
            glVertex3f(1,1,1);
        glEnd();
        //face esquerda
        glBegin(GL_QUADS);
            glNormal3f(-1,0,0);
            glVertex3f(0,0,1);
            glVertex3f(0,1,1);
            glVertex3f(0,1,0);
            glVertex3f(0,0,0);
        glEnd();
        //face superior
        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(0,1,0);
            glVertex3f(0,1,1);
            glVertex3f(1,1,1);
            glVertex3f(1,1,0);
        glEnd();
        //face inferior
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0,0,0);
            glVertex3f(1,0,0);
            glVertex3f(1,0,1);
            glVertex3f(0,0,1);
        glEnd();
        //telhado
        //esquerda
        //glBegin(GL_POLYGON);
        //    glNormal3f(-1,1,0);
        //    glVertex3f(0,1,0);
        //    glVertex3f(0,1,1);
        //    glVertex3f(0.5,1.5,0.5);
        //glEnd();
        glPushMatrix();
            glTranslatef(0,1,0);
            glRotatef(-90,0,1,0);
            glRotatef(-45,1,0,0);
            glScalef(1,1.4,1);
            //GUI::drawOrigin(0.5);
            glBegin(GL_POLYGON);
                glNormal3f(0,0,1);
                glVertex3f(0,0,0);
                glVertex3f(1,0,0);
                glVertex3f(0.5,0.5,0);
            glEnd();
        glPopMatrix();
        //frente
        glBegin(GL_POLYGON);
            glNormal3f(0,1,1);
            glVertex3f(0,1,1);
            glVertex3f(1,1,1);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
        //tras
        glBegin(GL_POLYGON);
            glNormal3f(0,1,-1);
            glVertex3f(1,1,0);
            glVertex3f(0,1,0);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
        //direita
        glBegin(GL_POLYGON);
            glNormal3f(1,1,0);
            glVertex3f(1,1,1);
            glVertex3f(1,1,0);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
    glPopMatrix();
}*/
