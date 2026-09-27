#include<iostream>
#include<string>

using namespace std;


bool checkearC(string cadena){
    // 4 estados 0 , 1,2,3
    // 3 es el limbo
    // 0 es el estado inicial
    // 1 es el estado de aceptacion
    // 2 es el estado despues de leer un _ 

int estado = 0;

if (cadena.empty()){
    return false;
}    
    for(int i = 0; i < int(cadena.length()); i++){

 char caracterAct = cadena[i]; // caracter actual

 if (estado == 0)
 {
    if(islower(caracterAct)) {estado = 1; continue;}
    if(isdigit(caracterAct)) {estado = 3; continue;}
    if(caracterAct == '_') {estado = 3; continue;}
    estado = 3;
 }

 if (estado == 1)
 {
    if(islower(caracterAct)) {estado = 1; continue;}
    if(isdigit(caracterAct)) {estado = 1; continue;}
    if(caracterAct == '_') {estado = 2; continue;}
    estado = 3;
 }

 if (estado == 2)
 {
    if(islower(caracterAct)) {estado = 1; continue;}
    if(isdigit(caracterAct)) {estado = 1; continue;}
    if(caracterAct == '_') {estado = 2; continue;}
    estado = 3;
 }
}

if(estado == 1) return true;

return false;
}

bool checkearP(string cadena){
//  3 estados: 0,1,2
// 0 es el estado inicial
// 1 es el estado de aceptacion
// 2 es el limbo

if(cadena.empty()) return false;

int estado = 0;

for(int i = 0; i < cadena.length() ; i++){

char caracterAct = cadena[i];

if(estado == 0){

if(islower(caracterAct)){ estado = 1; continue;}
if(isupper(caracterAct)){ estado = 1; continue;}
if(caracterAct == '_'){ estado = 1; continue;};
estado = 2;
}

if(estado == 1){

if(isdigit(caracterAct)){ estado = 1; continue;}
if(islower(caracterAct)){ estado = 1; continue;}
if(isupper(caracterAct)){ estado = 1; continue;}
if(caracterAct == '_'){ estado = 1; continue;};

estado = 2;

}
}

if(estado == 2) return false;

return true;

}

bool checkearCO(string cadena){
// uso 3 estados
    if(cadena.empty()) return false;

    int estado = 0;

    for(int i = 0; i < cadena.length() ; i++){

        char caracterAct = cadena[i];

        if(estado == 0){ // estado 0 inicial

            if(isupper(caracterAct)){ estado = 1; continue;}
            if(isdigit(caracterAct)){ estado = 3; continue;}
            if(caracterAct == '-'){ estado = 3; continue;}
            estado = 3;
        }

        if(estado == 1){ // estado 1 aceptacion

            if(isupper(caracterAct)){ estado = 1; continue;}
            if(isdigit(caracterAct)){ estado = 1; continue;}
            if(caracterAct == '-'){ estado = 2; continue;}
            estado = 3;
        }

        if(estado == 2){ // estado 2 limbo

            if(isupper(caracterAct)){ estado = 1; continue;}
            if(isdigit(caracterAct)){ estado = 1; continue;}
            if(caracterAct == '-'){ estado = 2; continue;}
            estado = 3;
        }

    }

    if(estado == 1) return true;
    return false;
}

class LenguajeAceptado{
    private:
    string cadena;
        string C_Style = "C-Style";
        string Python = "Python";
        string COBOL = "COBOL";
        bool C_accepted ;
        bool Python_accepted ;
        bool COBOL_accepted ;
public:


        LenguajeAceptado(string expresion){ // chequeamos la expresion por cada tipo y guardamos un bool de el resultado
            cadena = expresion;

            C_accepted = checkearC(expresion);
            Python_accepted = checkearP(expresion);
            COBOL_accepted = checkearCO(expresion);
        }

        void imprimir(){ // imprimimos resultados dependiendo si fue aceptada o rechazada con el ternario
            cout<< "Cadena: " <<cadena<<endl;
            cout << C_Style << ": " << (C_accepted ? "ACEPTADA": "RECHAZADA") << endl;
            cout << Python << ": " << (Python_accepted ? "ACEPTADA" : "RECHAZADA") << endl;
            cout << COBOL << ": " << (COBOL_accepted ? "ACEPTADA" : "RECHAZADA") << endl << endl;
        }

};            


int main(){            

int K;

cin >> K;
cin.ignore();

string* cadenas = new string [K]; // arreglo dinamico pa la cantidad K de cadenas

for (int i = 0; i < K; i++) 
{
getline(cin,cadenas[i]);
}

for (int i = 0; i < K; i++)
{

    LenguajeAceptado p(cadenas[i]);
    p.imprimir();
}

delete[] cadenas;
    return 0;
}