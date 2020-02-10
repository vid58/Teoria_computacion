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

int main(){
    string palabra;
    int n;

    palabra="greatgrandmother";

    for(int i=0;i<palabra.size();i++){
        cout<<palabra[i]<<"  ";
        n=i;
    }

    cout<<endl;
    n++;
    cout<<n<<endl;
    cout<<palabra[4]<<endl;

    cout<<":::::::::::::::"<<endl;

    int cant_palabras;
    cant_palabras=n/5;

    cout<<cant_palabras<<endl;
    cout<<palabra[0]<<endl;

    string palabritas[cant_palabras];

    if(n==6){
        if(palabra[0]=='f'){
            palabritas[0]=palabra;
        }else if(palabra[0]=='m'){
            palabritas[0]=palabra;
        }
    }
    else if(n>6){
        if(palabra[4]=='d'){
            int letra=5;
            int temp_letra=5;
            char temp[temp_letra];
            string tempo;
            int _i=0;

            for(int j=0;j<cant_palabras;j++) {

                int k=0;
                for (int i = _i; i < letra; i++) {

                    temp[k] = palabra[i];
                    tempo = temp;
                    _i=i;
                    k++;

                }

                letra=letra+_i+1+1;
                _i++;
                palabritas[j]=tempo;

            }

        }else if(palabra[4]=='t'){

            int letra=5;
            int temp_letra=5;
            char temp[temp_letra];
            string tempo;
            int _i=0;

            if(n==16) {
                for (int j = 0; j < cant_palabras; j++) {

                    int k = 0;
                    for (int i = _i; i < letra; i++) {

                        temp[k] = palabra[i];
                        tempo = temp;
                        _i = i;
                        k++;

                    }

                    letra = letra + _i + 1;
                    _i++;
                    palabritas[j] = tempo;

                }
            }else{
                cout<<"malo";
            }
        }
    }

    for(int i=0;i<cant_palabras;i++){
        cout<<palabritas[i]<<" ";
    }
}
