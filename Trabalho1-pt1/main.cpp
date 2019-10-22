#include <iostream>
#include <fstream>
#include <string>

#include <vector>

using namespace std;

#include <gui.h>


#include <objeto.h>
#include <carro.h>
#include <casa.h>

//#include <personagem.h>



//Model3DS model3ds("../3ds/cartest.3DS");

vector <Objeto*> objetosVector;
int posSelecionado = -1;
bool incluirObjeto = false;



void desenha() {
    //inicializando:
    GUI::displayInit();
    GUI::setLight(1, 0.5, 5, 1.5, true, false);

    GUI::drawOrigin(0.5);   //desenha origem do cenário ao centro
    GUI::setColor(0.0,0.755,0.18);
    GUI::drawFloor(12,18);   //desenha o piso do cenário

    for ( int i = 0; i < objetosVector.size(); i++){
        glPushMatrix();
        objetosVector[i]->desenha();
        glPopMatrix();

    if ( posSelecionado >= 0 && posSelecionado < objetosVector.size() ){
        objetosVector[posSelecionado]->t.x += glutGUI::dtx;
        objetosVector[posSelecionado]->t.y += glutGUI::dty;
        objetosVector[posSelecionado]->t.z += glutGUI::dtz;

        objetosVector[posSelecionado]->a.x += glutGUI::dax;
        objetosVector[posSelecionado]->a.y += glutGUI::day;
        objetosVector[posSelecionado]->a.z += glutGUI::daz;

        objetosVector[posSelecionado]->s.x += glutGUI::dsx;
        objetosVector[posSelecionado]->s.y += glutGUI::dsy;
        objetosVector[posSelecionado]->s.z += glutGUI::dsz;
    }
}


    GUI::displayEnd();
}

void carregarArquivo(){
    //cout << " - Começou a função CarregarArquivo" <<endl;
    ifstream baseFile;
    baseFile.open("../baseSaves.txt");
    //cout <<endl <<" - Tentando carregar arquivo baseSaves" <<endl;


    if(!baseFile){
        cout << " - ERRO arquivo tá errado seu IMBECIL!!!" << endl;
        exit(1);

    } else {
        //cout <<endl << " - Arquivo baseSaves carregado com sucesso" <<endl;
        std::string line;
        getline(baseFile, line);
        cout <<line << " Objetos no vetor;" <<endl;
        int n_objetos = stoi ( line );         //identifica quantos elementos estão no arquivo

        int tipo = 0;                   //variável para identificar qual será o objeto a ser criado
        double tx = 0, ty = 0, tz = 0;  //responsável pela translação
        double ax = 0, ay = 0, az = 0;  //responsável pelas rotações
        double sx = 0, sy = 0, sz = 0;  //responsável pela escala

        for( int i = 0; i < n_objetos; i++){
            getline(baseFile, line);
            tipo = stoi(line);          //identifica qual objeto deve ser criado conforme salvo no arquivo

            getline(baseFile, line);
            tx = stoi(line);
            getline(baseFile, line);
            ty = stoi(line);
            getline(baseFile, line);
            tz = stoi(line);

            getline(baseFile, line);
            ax = stoi(line);
            getline(baseFile, line);
            ay = stoi(line);
            getline(baseFile, line);
            az = stoi(line);

            getline(baseFile, line);
            sx = stoi(line);
            getline(baseFile, line);
            sy = stoi(line);
            getline(baseFile, line);
            sz = stoi(line);

            Vetor3D tn = Vetor3D(tx, ty, tz);
            Vetor3D an = Vetor3D(ax, ay, az);
            Vetor3D sn = Vetor3D(sx, sy, sz);

            if ( tipo == 1 ) {          //Valor é referente ao 3ds BMW
                objetosVector.push_back( new Carro( tn, an, sn) );
                cout << "Objeto Carro inserido no vetor" <<endl;
            } else if ( tipo == 2 ) {
                objetosVector.push_back( new Casa( tn, an, sn) );
                cout << "Objeto Casa inserido no vetor" <<endl;
            }
        }
    }

    baseFile.close();
}

//controle sobre os objetos no objetosVector
void objPrevious(){
    if ( posSelecionado >= 0 && posSelecionado < objetosVector.size() ){
        objetosVector[posSelecionado]->selecionado = false;
    }
    posSelecionado--;
    if ( posSelecionado < 0 ){
        posSelecionado = objetosVector.size() - 1;
    }
    if ( posSelecionado >= 0 && posSelecionado < objetosVector.size() ){
        objetosVector[posSelecionado]->selecionado = true;
    }
};

void objNext(){
    if ( posSelecionado >= 0 && posSelecionado < objetosVector.size() ){
        objetosVector[posSelecionado]->selecionado = false;
    }
    posSelecionado++;
    posSelecionado = posSelecionado % objetosVector.size();
    if ( posSelecionado >= 0 && posSelecionado < objetosVector.size() ){
        objetosVector[posSelecionado]->selecionado = true;
    }
};
void unmark(){
    if ( posSelecionado >= 0 && posSelecionado < objetosVector.size() ){
        objetosVector[posSelecionado]->selecionado = false;
    }
    glutGUI::trans_obj = false;
}
void drawnOrigem(){
    if ( posSelecionado >= 0 && posSelecionado < objetosVector.size() ){
        objetosVector[posSelecionado]->origem = !objetosVector[posSelecionado]->origem;
    }
}


//comandos oriundos do teclado
void teclado(unsigned char key, int x, int y) {
    GUI::keyInit(key, x, y);

    switch ( key ){
        case 't':
            glutGUI::trans_obj = !glutGUI::trans_obj;
            break;
        case 'l':
            glutGUI::trans_luz = !glutGUI::trans_luz;
            break;
        case ',':{
            objPrevious();
            break;
        }
        case '.':{
            objNext();
            break;
        }
        case ':':{
            unmark();
            break;
        }
        case '*':{
            drawnOrigem();
            break;
        }
    }
}



int main(){

    cout << "Bem Vindo! A seguir, um guia dos comandos:\n" << endl;
    cout << "Selecionar o objeto anterior: ( , )" << endl;
    cout << "Selecionar o próximo objeto: ( . )" << endl;
    cout << "Desmarcar objeto selecionado: ( : )" <<endl;
    cout << "Desenhar eixo do sistema local do objeto: ( * )" <<endl;

    carregarArquivo();
    GUI gui = GUI(1024,600,desenha,teclado);
}


