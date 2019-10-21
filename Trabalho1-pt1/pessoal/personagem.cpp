#include "personagem.h"


Personagem::Personagem(){

}

void Personagem::desenha(){

    glPushMatrix();
        Objeto::desenha();

        glScalef(0.1, 0.1, 0.1);

        Vetor3D v1, v2, v3, normal;

        //cabeça
        GUI::setColor(1, 1, 1);
        v1 = Vetor3D(-0.5, 0, 2);
        v2 = Vetor3D(0, 2, 1);
        v3 = Vetor3D(-1, 2, 0);

    glBegin(GL_POLYGON);
        normal = (v3 - v2) ^ (v1 - v2);
        glNormal3f(normal.x , normal.y , normal.z);
        glVertex3f(-0.5, 0, 2);
        glVertex3f(0, 2, 1);
        glVertex3f(-1, 2, 0);
    glEnd();




    glPopMatrix();
        /*//pelvis
        glPushMatrix();
            //transformacoes influenciam todo o escopo push/pop
            glTranslatef(0,-1,0);
            glRotatef(0,1,0,0);
            GUI::drawOrigin(0.5);
            //modelo
            if (selecionado) {
                GUI::setColor(1,0,0);
            } else {
                GUI::setColor(0,0,1);
            }
            GUI::drawBox(-0.5,0.0,-0.5, 0.5,0.5,0.5);

            //tronco
            glPushMatrix();
                glTranslatef(0,0.5,0);
                glRotatef(glutGUI::lx,1,0,0);
                GUI::drawOrigin(0.5);
                //modelo
                if (selecionado) {
                    GUI::setColor(1,0,0);
                } else {
                    GUI::setColor(1,0,0);
                }
                GUI::drawBox(-0.5,0.0,-0.5, 0.5,1.5,0.5);

                //braco direito
                glPushMatrix();
                    //transformacoes influenciam apenas localmente (escopo push/pop mais interno)
                    glTranslatef(0.5,1.5,0);
                    glRotatef(glutGUI::ly,0,0,1);
                    GUI::drawOrigin(0.5);
                    //modelo
                    if (selecionado) {
                        GUI::setColor(1,0,0);
                    } else {
                        GUI::setColor(0,1,0);
                    }
                    glTranslatef(1,0,0);
                    GUI::drawBox(-1.0,0.0,-0.1, 1.0,0.2,0.1);
                glPopMatrix();

                //braco esquerdo
                glPushMatrix();
                    glTranslatef(-0.5,1.5,0);
                    glRotatef(45,0,0,1);
                    GUI::drawOrigin(0.5);
                    //modelo
                    if (selecionado) {
                        GUI::setColor(1,0,0);
                    } else {
                        GUI::setColor(0,1,0);
                    }
                    glTranslatef(-1,0,0);
                    GUI::drawBox(-1.0,0.0,-0.1, 1.0,0.2,0.1);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();*/

}
