#include <iostream>
#include <vector>

using namespace std;

#include <gui.h>


//#include <objeto.h>
//#include <personagem.h>
//#include <casa.h>
//#include <carro.h>

//Model3DS model3ds("../3ds/cartest.3DS");

vector<Objeto*> objetos;
int posSelecionado = -1;
bool incluirObjeto = false;



void desenha() {
    //inicializando:
    GUI::displayInit();
    GUI::setLight(1, 0.5, 5, 1.5, true, false);

    GUI::drawOrigin(0.2); //desenha as setinhas no centro
    GUI::setColor(1,0.7,0.5);
    GUI::drawFloor(18,9);


    GUI::displayEnd();

    /*
    GUI::displayInit();

    GUI::setLight(1,1,3,5,true,false);
    GUI::setLight(2,-1.5,0.5,-1,true,false);
    //GUI::setLight(3,-5,3,5,true,false);

    GUI::drawOrigin(1);

    GUI::setColor(1,0,0);
    GUI::drawFloor();

    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->t.x += glutGUI::dtx;
        objetos[posSelecionado]->t.y += glutGUI::dty;
        objetos[posSelecionado]->t.z += glutGUI::dtz;

        objetos[posSelecionado]->a.x += glutGUI::dax;
        objetos[posSelecionado]->a.y += glutGUI::day;
        objetos[posSelecionado]->a.z += glutGUI::daz;

        objetos[posSelecionado]->s.x += glutGUI::dsx;
        objetos[posSelecionado]->s.y += glutGUI::dsy;
        objetos[posSelecionado]->s.z += glutGUI::dsz;
    }
//    glutGUI::dtx = 0.0; glutGUI::dty = 0.0; glutGUI::dtz = 0.0;
//    glutGUI::dax = 0.0; glutGUI::day = 0.0; glutGUI::daz = 0.0;
//    glutGUI::dsx = 0.0; glutGUI::dsy = 0.0; glutGUI::dsz = 0.0;

    //objeto transformado
    //glPushMatrix();
//        glTranslatef(glutGUI::tx,glutGUI::ty,glutGUI::tz);
//        glRotatef(glutGUI::az,0,0,1);
//        glRotatef(glutGUI::ay,0,1,0);
//        glRotatef(glutGUI::ax,1,0,0);
//        GUI::drawOrigin(1);
//        glScalef(glutGUI::sx,glutGUI::sy,glutGUI::sz);
//        GUI::setColor(0,0,1);
//        //GUI::drawBox(0,0,0, 1,1,1);
//        //GUI::drawBox(1,1,0, 2,2,1);
//        //casa();
//        //personagem();
//        //GUI::draw3ds(model3ds);

    //glPopMatrix();

    GUI::displayEnd();
*/
}



void teclado(unsigned char key, int x, int y) {
    GUI::keyInit(key, x, y);

    switch ( key ){
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;

    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    }

    /*
    //if (!incluirObjeto) {
        GUI::keyInit(key,x,y);
    //}

    switch (key) {
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    case 'n':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado++;
        posSelecionado = posSelecionado%objetos.size();
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;
    case 'b':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado--;
        if (posSelecionado < 0) {
            posSelecionado = objetos.size()-1;
        }
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;


    case 'O':
        incluirObjeto = !incluirObjeto;
        break;
    case 'p':
        if (incluirObjeto) {
            objetos.push_back( new Personagem() );
        }
        break;
    case 'c':
        if (incluirObjeto) {
            objetos.push_back( new Carro() );
        }
        break;

    default:
        break;
    }
    */
}

int main(){

    cout << "Hello World!" << endl;

    GUI gui = GUI(1024,600,desenha,teclado);

}


