#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include <gui.h>
#include <objeto.h>
#include <carro.h>
#include <casa.h>
#include <personagem.h>


vector <Objeto*> objetosVector;
int posSelecionado = -1;
bool incluirObjeto = false;



void desenha() {
    //inicializando:
    GUI::displayInit();
    GUI::setLight(1, 0.5, 5, 1.5, true, false);

    //GUI::drawOrigin(0.8);   //desenha origem do cenário ao centro
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

//Controle sobre o arquivo base
void carregarArquivo(){
    //cout << " - Começou a função CarregarArquivo" <<endl;
    ifstream baseFile;
    baseFile.open("../baseSaves.txt");
    //cout <<endl <<" - Tentando carregar arquivo baseSaves" <<endl;


    if(!baseFile){
        cout << " - ERRO ao carregar aquivo baseSaves.txt" << endl;
        exit(1);

    } else {
        //cout <<endl << " - Arquivo baseSaves carregado com sucesso" <<endl;
        std::string line;
        getline(baseFile, line);
        cout <<line << " Objetos no vetor;" <<endl << endl;
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
                //cout << "Objeto Carro inserido no vetor" <<endl;
            } else if ( tipo == 2 ) {
                objetosVector.push_back( new Casa( tn, an, sn) );
                //cout << "Objeto Casa inserido no vetor" <<endl;
            } else if ( tipo == 3 ) {
                objetosVector.push_back( new Personagem( tn, an, sn) );
                //cout << "Objeto Personagem inserido no vetor" <<endl;
            }
        }
    }

    baseFile.close();
}

void saveBaseFile(){
    ofstream baseFile;
    baseFile.open("../baseSaves.txt");
    baseFile.clear();

    baseFile << objetosVector.size() << "\n";
    for ( int i = 0; i < objetosVector.size(); i++ ){
        baseFile << objetosVector[i]->tipo << "\n";
        baseFile << objetosVector[i]->t.x << "\n";
        baseFile << objetosVector[i]->t.y << "\n";
        baseFile << objetosVector[i]->t.z << "\n";
        baseFile << objetosVector[i]->a.x << "\n";
        baseFile << objetosVector[i]->a.y << "\n";
        baseFile << objetosVector[i]->a.z << "\n";
        baseFile << objetosVector[i]->s.x << "\n";
        baseFile << objetosVector[i]->s.y << "\n";
        baseFile << objetosVector[i]->s.z << "\n";
    }

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
void deleteSelected(){
    if ( posSelecionado >= 0 && posSelecionado < objetosVector.size() ){
        objetosVector.erase(objetosVector.begin() + posSelecionado);
    }
}
void deleteLastObj(){
    if (objetosVector.size() > 0){
        objetosVector.pop_back();
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
        case 'P':{
            deleteSelected();
            break;
        }
        case '}':{
            deleteLastObj();
            break;
        }
        case '+':{
           incluirObjeto = !incluirObjeto;
           break;
        }
        case 'S':{
            saveBaseFile();
            break;
        }

        //Definindo a lista de objetos que pode ser criados no cernário;
        case '!':{
            if ( incluirObjeto ){
                objetosVector.push_back( new Carro() );
            }
            break;
        }
        case '@':{
            if ( incluirObjeto ){
                objetosVector.push_back( new Casa() );
            }
            break;
        }
        case '#':{
            if ( incluirObjeto ){
                objetosVector.push_back( new Personagem() );
            }
            break;
        }
        case '3':{
            glutGUI::cam = new CameraJogo(0.2,4,-17,  0,0,2.7,  0,1,0); //-10,10,-20,  2,0,0,  0,1,0
            break;
        }
        case '4':{
            glutGUI::cam = new CameraJogo(5,8,-18,  -1,-3,2,  0.4,1,0);  //5,3,-18,  0,1,8,  0.3,1,
            break;
        }
        case '5':{
            glutGUI::cam = new CameraDistante(8,19,21,  1,1,3,  0,1,0);  //8,19,21,  1,1,3,  0,1,0
            break;
        }
        case '6':{
            glutGUI::cam = new CameraDistante(-7,3,14,  5.5,-1,-8.5,  0,1,0);  //-7,3,14,  5.5,-1,-8.5,  0,1,0
            break;
        }

    }
}



int main(){

    cout << "Bem Vindo! A seguir, um guia dos comandos:\n" << endl;
    cout << "Selecionar o objeto anterior: ( , )" << endl;
    cout << "Selecionar o próximo objeto: ( . )" << endl;
    cout << "Desmarcar objeto selecionado: ( : )" <<endl << endl;
    cout << "Realizar transformações no objeto selecionado: ( t )" <<endl;
    cout << "Desenhar eixo do sistema local do objeto: ( * )" <<endl << endl;
    cout << "Incluir novo objeto no cenário: ( + )" << endl;
    cout << "A lista de objetos vi de 1 a 0 (não numerico) + SHIFT" << endl << endl;
    cout << "Eleminar objeto selecioando: ( P + SHIFT)" << endl;
    cout << "Eliminar o ultimo objeto do vetor: ( ] + SHIFT )" <<endl;
    cout << "Guardar a atual lista de objetos em arquivo: ( S + SHIFT )" << endl << endl;
    cout << "Alternar entre as câmera: ( 3 .. 6)" <<endl;
    cout << "Resetar para câmera dafult: ( c )" <<endl;

    cout << endl;
    carregarArquivo();
    GUI gui = GUI(1024,600,desenha,teclado);
}


