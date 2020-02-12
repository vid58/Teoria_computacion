#include <iostream>
#include <limits>
#include "string.h"
using namespace std;



int LENGHT=16;//Longitud de la oración sin rellenos
string translate[3];

string traductor(string parent);

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


string traductor(string parent)
{
    if(parent=="mother") return "mutter";
    else if(parent=="father") return "vater";
    else if(parent=="of") return "von";
    else if(parent=="Mary") return  "Maria";
    else if (parent =="John") return "Johan";
}
int main()
{
    string palabra;
    string Oraciones[50];
    palabra = "The mother of the mother of the father of the mother of the mother of John";
    int cont=0;
    for(int i=0; i< palabra.size(); i++) {
        if (palabra[i] != ' ')
            Oraciones[cont] += palabra[i];//Guardar las palabras en cadenas
        else
            cont++;
    }
    for(int i=0; i<=LENGHT;i++)cout<<Oraciones[i]<<endl;
    int name=0;//valor para saber si es gross, ur
    for(int i=0;i<=LENGHT;i++) {
        if (Oraciones[i] == "Mary" ||Oraciones[i] == "John") name = i;

    }
    Rellenar(Oraciones[1],Oraciones[LENGHT-3],Oraciones[LENGHT-1],LENGHT-1);

    for (int i = 0; i <4 ; i++) {
        cout<<translate[i]<<" ";
    }
    cout<<endl;
    return 0;

}