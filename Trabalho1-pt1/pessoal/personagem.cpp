#include "personagem.h"

Personagem::Personagem( ) : Objeto( 3 ){
}
Personagem::Personagem( Vetor3D tn, Vetor3D an, Vetor3D sn ) : Objeto( 3 ){
    t = tn; a = an; s = sn;
    origem = false;
}
void Personagem::desenha(){     //Sonic Meme base from YouTube
    Vetor3D bodyColor = Vetor3D( 0.051, 0.153, 0.9 ) ;

    glPushMatrix();
            Objeto::desenha();
            glTranslatef(-0.5,0.8,-0.5);
            //glRotatef(90,1,0,0);
            glPushMatrix();
                glScalef(0.5, 0.5, 0.5);

                //tronco
                glPushMatrix();
                    GUI::setColor( bodyColor.x, bodyColor.y, bodyColor.z );
                    glTranslatef(0, 1, 0);
                    glScalef(0.6, 0.7, 0.5);
                    glutSolidSphere(0.99, 15, 15);
                glPopMatrix();

                glPushMatrix();
                    GUI::setColor(1, 0.8, 0.5);
                    glTranslatef(0, 1, 0.259);
                    glScalef(0.85, 1.02, 0.55);
                    glutSolidSphere(0.5, 15, 9);
                glPopMatrix();

                //pescoço
                glPushMatrix();
                    GUI::setColor( bodyColor.x, bodyColor.y, bodyColor.z );
                    glTranslatef(0, 1.70, 0);
                    glScalef(0.42, 0.54, 0.42);
                    glRotatef(90, 0, 1, 0);
                    glRotatef(90, 1, 0, 0);
                    glutSolidSphere(0.42, 9, 3);
                glPopMatrix();

                //cabeça
                glPushMatrix();
                    GUI::setColor( bodyColor.x, bodyColor.y, bodyColor.z );
                    glTranslatef(0, 2.15, 0);
                    glScalef(0.92, 0.92, 0.92);
                    glutSolidSphere(0.42, 30, 20);
                glPopMatrix();

                    //rosto
                        //olho-esquerdo
                        glPushMatrix();
                            GUI::setColor(1, 1, 1);
                            glTranslatef(-0.115, 2.25, 0.352);
                            glRotatef(-22, 1, 0, 0);
                            glRotatef(-20, 0, 1, 0);
                            glRotatef(35, 0, 0, 1);
                            glScalef(0.144, 0.195, 0.045);

                            glutSolidSphere(0.7, 20, 10);
                        glPopMatrix();
                        glPushMatrix();     //bola preta
                            GUI::setColor(0, 0, 0);
                            glTranslatef(-0.080, 2.25, 0.405);
                            glRotatef(-18, 1, 0, 0);
                            glRotatef(-20, 0, 1, 0);
                            glRotatef(0, 0, 0, 0);
                            glScalef(0.055, 0.1053, 0.025);
                            glutSolidSphere(0.6, 20, 10);
                        glPopMatrix();
                        //olho-direito
                        glPushMatrix();
                            GUI::setColor(1, 1, 1);
                            glTranslatef(0.115, 2.25, 0.352);
                            glRotatef(-22, 1, 0, 0);
                            glRotatef(20, 0, 1, 0);
                            glRotatef(-35, 0, 0, 1);
                            glScalef(0.144, 0.195, 0.045);
                            glutSolidSphere(0.7, 20, 10);
                        glPopMatrix();
                        glPushMatrix();     //bola preta
                            GUI::setColor(0, 0, 0);
                            glTranslatef(0.080, 2.25, 0.405);
                            glRotatef(-18, 1, 0, 0);
                            glRotatef(20, 0, 1, 0);
                            glScalef(0.055, 0.1053, 0.025);
                            glutSolidSphere(0.6, 20, 10);
                        glPopMatrix();

                        //Focinho
                        glPushMatrix();
                            GUI::setColor(1, 0.8, 0.5);
                            glTranslatef(0, 2.05, 0.255);
                            glRotatef(15, 1, 0, 0);
                            glScalef(0.9, 0.85, 0.5);
                            glutSolidSphere(0.27, 30, 15);
                        glPopMatrix();

                        //Espinhos


                        glPushMatrix();
                            GUI::setColor(bodyColor.x, bodyColor.y, bodyColor.z);
                            glTranslatef(-0.150, 2.46, 0);
                            glRotatef(80, 1, 0, 0);
                            glRotatef(-140, 0, 1, 0);
                            glRotatef(0, 0, 0, 1);
                            glutSolidCone(0.060, 0.3, 5, 1);
                        glPopMatrix();
                        glPushMatrix();
                            GUI::setColor(bodyColor.x, bodyColor.y, bodyColor.z);
                            glTranslatef(0, 2.515, 0);
                            glRotatef(-90, 1, 0, 0);
                            glRotatef(0, 0, 1, 0);
                            glRotatef(0, 0, 0, 1);
                            glutSolidCone(0.060, 0.3, 5, 1);
                        glPopMatrix();

                        glPushMatrix();
                            GUI::setColor(bodyColor.x, bodyColor.y, bodyColor.z);
                            glTranslatef(-0.205, 2.35, 0);
                            glRotatef(0, 1, 0, 0);
                            glRotatef(-90, 0, 1, 0);
                            glRotatef(0, 0, 0, 1);
                            glutSolidCone(0.060, 0.3, 5, 1);
                        glPopMatrix();

                        glPushMatrix();
                            GUI::setColor(bodyColor.x, bodyColor.y, bodyColor.z);
                            glTranslatef(0.150, 2.46, 0);
                            glRotatef(-90, 1, 0, 0);
                            glRotatef(35, 0, 1, 0);
                            glRotatef(0, 0, 0, 1);
                            glutSolidCone(0.060, 0.5, 5, 1);
                        glPopMatrix();

                        glPushMatrix();
                            GUI::setColor(bodyColor.x, bodyColor.y, bodyColor.z);
                            glTranslatef(0.35, 2.21, 0);
                            glRotatef(0, 1, 0, 0);
                            glRotatef(90, 0, 1, 0);
                            glRotatef(0, 0, 0, 1);
                            glutSolidCone(0.060, 0.5, 5, 1);
                        glPopMatrix();




                //Perna-esquerda
                glPushMatrix();
                    GUI::setColor( bodyColor.x, bodyColor.y, bodyColor.z );
                    glTranslatef(-0.25, 0.08, 0);

                    glRotatef(-3, 0, 0, 1);
                    //glRotatef(90, 0, 1, 0);
                    glScalef(0.17, 1.5, 0.17);
                    glutSolidSphere(0.42, 20, 3);
                glPopMatrix();
                glPushMatrix();
                    GUI::setColor( bodyColor.x, bodyColor.y, bodyColor.z );
                    glTranslatef(-0.28, -0.6, 0);
                    glRotatef(-1, 0, 0, 1);
                    glScalef(0.17, 1.5, 0.17);
                    glutSolidSphere(0.42, 20, 3);
                glPopMatrix();
                    //Pé-esquerdo

                //Perna-direita
                glPushMatrix();
                    GUI::setColor( bodyColor.x, bodyColor.y, bodyColor.z );
                    glTranslatef(0.25, 0.08, 0);

                    glRotatef(3, 0, 0, 1);
                    //glRotatef(90, 0, 1, 0);
                    glScalef(0.17, 1.5, 0.17);
                    glutSolidSphere(0.42, 20, 3);
                glPopMatrix();
                glPushMatrix();
                    GUI::setColor( bodyColor.x, bodyColor.y, bodyColor.z );
                    glTranslatef(0.28, -0.6, 0);
                    glRotatef(1, 0, 0, 1);
                    glScalef(0.17, 1.5, 0.17);
                    glutSolidSphere(0.42, 20, 3);
                glPopMatrix();
                    //Pé-direito

            glPopMatrix();
            /*
                //glTranslatef(-1,0.7,-1);



                */
/*





                        //Focinho
                        glPushMatrix();
                            GUI::setColor(1, 0.8, 0.5);
                            glTranslatef(0, 1.08, 0.03);

                            glScalef(0.9, 0.85, 1);
                            glutSolidSphere(0.210, 30, 15);
                        glPopMatrix();

                */



//                GUI::drawBox(0.2,2,0,-0.2,0.2,0.1);
//                GUI::drawBox(1,0.2,0,-1,0,0.2);
//                double i = 0;
//                while( i < 1 ){
//                    GUI::drawBox(0.4,2-i,-0.1,0.2,1.9-i,0);
//                    i = i + 0.2;
//                }
//                GUI::drawBox(0.8,0.9,-0.1, 0.2,0.8,0);
//                GUI::drawBox(0.9,2,-0.1, 0.8,0.8,0);
//                GUI::glReflectPlaneYZf();
//                    GUI::drawBox(-0.2,0.2,0.1, 0.2,2,0);
//                    GUI::drawBox(-1,0,0.2,1,0.2,0);
//                    i = 0;
//                    while( i < 1 ){
//                        GUI::drawBox(0.2,1.9-i,0, 0.4,2-i,-0.1);
//                        i = i + 0.2;
//                    }
//                    GUI::drawBox(0.2,0.8,0, 0.8,0.9,-0.1);
//                    GUI::drawBox(0.8,0.8,0, 0.9,2,-0.1);
//            glPopMatrix();



    glPopMatrix();
    glPushMatrix();
        if ( selecionado ){
            glRotatef(0,0,0,0);
            GUI::setColor(0.2, 0.8, 0.2, 0.35);
            GUI::drawBox(-0.185, -0.085, 0, 0.185, 0.085, 0.14);
        }
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
