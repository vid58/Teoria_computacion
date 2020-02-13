#include <iostream>
using namespace std;

void A1(int cant_palabras,string palabritas[]);
void A2(int cant_palabras,string palabritas[]);
//////////////////////////////////////////////////////
int LENGHT=16;//Longitud de la oración sin rellenos
string translate[3];

void Rellenar(string parent1, string parent2, string name, int n);
string traductor(string parent);


int main(){

    string registro;

    int p;

    cout<<"Cantidad de letras a ingresar: ";cin>>p;

    string arreglo[p];

    for(int i=0;i<p;i++){
        cout<<"Escriba: ";cin>>registro;
        arreglo[i]=registro;
    }

    cout<<"Arreglo=[ ";
    for(int i=0;i<p;i++){
        cout<<arreglo[i]<<" ";
    }
    cout<<"]";

    cout<<endl;

    for(int m=0;m<p;m++) {

        string palabra;
        int n;

        palabra = arreglo[m];
        cout<<endl<<endl;

        for (int i = 0; i < palabra.size(); i++) {
            cout << palabra[i] << "  ";
            n = i;
        }

        cout << endl;
        n++;
        cout << "Nº de letras: " << n << endl;

        cout << ":::::::::::::::" << endl;

        int cant_palabras;
        cant_palabras = n / 5;

        cout << "Cantidad de palabras: " << cant_palabras << endl;

        string palabritas[cant_palabras];

        if (n == 6) {

            if (palabra[0] == 'f') {
                palabritas[0] = palabra;

            } else if (palabra[0] == 'm') {
                palabritas[0] = palabra;
            }

        } else if (n > 6) {

            if (palabra[4] == 'd') {

                palabritas[0] = "grand";
                if (palabra[5] == 'm') {
                    palabritas[1] = "mother";
                } else if (palabra[5] == 'f') {
                    palabritas[1] = "father";
                }

            } else if (palabra[4] == 't') {

                int algo = 0;

                for (int i = 0; i < palabra.size(); i++) {
                    if (palabra[i] == 't') {
                        algo++;
                    }
                }

                algo = algo - 1;
                //cout << "(" << algo << ")" << endl;

                for (int i = 0; i < algo; i++) {
                    palabritas[i] = "great";
                }

                //cout<<"("<<cant_palabras-algo<<")"<<endl;

                palabritas[cant_palabras - 2] = "grand";
                if (palabra[n - 6] == 'm') {
                    palabritas[cant_palabras - 1] = "mother";
                } else if (palabra[n - 6] == 'f') {
                    palabritas[cant_palabras - 1] = "father";
                }

            }
        }

        string temp[cant_palabras];
        for(int i=0;i<cant_palabras;i++){
            temp[i]=palabritas[i];
        }

        A1(cant_palabras,temp);
        cout<<endl;
        A2(cant_palabras,palabritas);

    }

    cout<<endl;
///////////////////////////////////////////////////////////////////////////////////////////////
    cout<<endl<<"//////////////////////////////////////////////"<<endl;
    cout<<endl<<"Oración por partes: "<<endl;

    string _palabra;
    string Oraciones[50];
    _palabra = "The mother of the mother of the father of the mother of the mother of John";
    int cont=0;
    for(int i=0; i < _palabra.size(); i++) {
        if (_palabra[i] != ' ')
            Oraciones[cont] += _palabra[i];//Guardar las palabras en cadenas
        else
            cont++;
    }
    for(int i=0; i<=LENGHT;i++)cout<<Oraciones[i]<<endl;
    int name=0;//valor para saber si es gross, ur
    for(int i=0;i<=LENGHT;i++) {
        if (Oraciones[i] == "Mary" ||Oraciones[i] == "John") name = i;

    }
    cout<<"Traduccion: ";
    Rellenar(Oraciones[1],Oraciones[LENGHT-3],Oraciones[LENGHT-1],LENGHT-1);

    for (int i = 0; i <4 ; i++) {
        cout<<translate[i]<<" ";
    }
    cout<<endl;


}

void A1(int cant_palabras,string palabritas[]){

    for(int i=0;i<cant_palabras;i++){
        if(palabritas[i]== "mother"){
            palabritas[i]="mo(";
            for(int j=0;j<cant_palabras;j++){
                palabritas[i]+=")";
            }
        }
        else if(palabritas[i]== "father"){
            palabritas[i]="fa(";
            for(int j=0;j<cant_palabras;j++){
                palabritas[i]+=")";
            }
        }
        else if(palabritas[i]== "grand"){
            palabritas[i]="g(";
        }
        else if(palabritas[i]== "great"){
            palabritas[i]="g(";
        }
    }
    cout<<endl;

    cout<<"Lenguaje intermedio: ";
    for(int i=0;i<cant_palabras;i++){
        cout<<palabritas[i];
    }

}

void A2(int cant_palabras,string palabritas[]){

    cout<<"Lenguaje en ingles: ";
    for(int i=0;i<cant_palabras;i++){
        cout<<palabritas[i]<<" ";
    }

    for(int i=0;i<cant_palabras;i++){
        if(palabritas[i]== "mother"){
            palabritas[i]="mutter";
        }
        else if(palabritas[i]== "father"){
            palabritas[i]="vater";
        }
        else if(palabritas[i]== "grand"){
            palabritas[i]="gross";
        }
        else if(palabritas[i]== "great"){
            palabritas[i]="ur";
        }
    }

    cout<<endl;

    cout<<"Lenguaje en aleman: ";
    for(int i=0;i<cant_palabras;i++) {
        cout << palabritas[i] << " ";
    }

}

string traductor(string parent)
{
    if(parent=="mother") return "mutter";
    else if(parent=="father") return "vater";
    else if(parent=="of") return "von";
    else if(parent=="Mary") return  "Maria";
    else if (parent =="John") return "Johan";
}

void Rellenar(string parent1, string parent2, string name, int n)
{
    switch(n)
    {
        case 3: if(parent1=="mother") translate[0]="Die";
            else if (parent1=="father") translate[0]="Der";
            translate[1]=traductor(parent2);
            translate[2]=traductor("of");
            translate[3]=traductor(name);
            break;
        case 6: if(parent1=="mother") translate[0]="Eine";
            else if (parent1=="father") translate[0]="Ein";
            translate[1]="gross"+traductor(parent2);
            translate[2]=traductor("of");
            translate[3]=traductor(name);
            break;
        default: if((n>=9)&&(n%3==0)){
                if(parent1=="mother") translate[0]="Eine";
                else if (parent1=="father") translate[0]="Ein";
                for(int j=0;j<(n/3)-2;j++) translate[1]+="ur";
                translate[1]+="gross"+traductor(parent2);
                translate[2]=traductor("of");
                translate[3]=traductor(name);
            }
    }
}

