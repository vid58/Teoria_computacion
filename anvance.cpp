#include <iostream>
using namespace std;

/*int main(){
    string c;
    cout<<"Escriba: ";cin>>c;

    if(c== "mother"){
        cout<<"mutter";
    }
    else if(c== "father"){
        cout<<"vater";
    }
    else if(c== "grand"){
        cout<<"gross";
    }
    else if(c== "great"){
        cout<<"ur";
    }
    else{
        cout<<"sin info";
    }

}*/

/*int main(){
    char A[6]={'m','o','t','h','e','r'};
    string cadena[2];

    cadena[0]= A;
    cout<<cadena[0];

    cout<<endl<<"........."<<endl;

    string algo="holapaco";
    char B[4];
    string almacen1;

    for(int i=0;i<4;i++){
        B[i]=algo[i];
    }
    for(int i=0;i<4;i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;

    almacen1=B;

    cout<<endl<<almacen1[3];
}*/
/*int n=0;
void algo(char A[]);
int main(){
    char A[6]={'m','o','t','h','e','r'};



    algo (A);
}
void algo(char  A[]){

    while (n!=6){
        cout<<A[n]<<"("<<A[n+1]<<")";
        n++;
    }

}*/

int main() {
    string palabra;
    int n;

    palabra = "greatgreatgrandfather";

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
//    string len_inter[];
    for(int i=0;i<cant_palabras;i++){
        palabritas[i] = "a";
    }


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
            //cout<<"("<<algo<<")"<<endl;

            for (int i = 0; i < algo; i++) {
                palabritas[i] = "great";
            }

            int p = (algo * 5);

            //cout<<"("<<cant_palabras-algo<<")"<<endl;

            palabritas[cant_palabras - 2] = "grand";
            if (palabra[n - 6] == 'm') {
                palabritas[cant_palabras - 1] = "mother";
            } else if (palabra[n - 6] == 'f') {
                palabritas[cant_palabras - 1] = "father";
            }


        }
    }

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

    for(int i=0;i<cant_palabras;i++){
        cout<<palabritas[i]<<" ";
    }
}
