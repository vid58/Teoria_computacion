//
// Created by claudioecharre on 12/02/20.
//

#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

list <string> Traduccion;

map < string, string> Traductor;
typedef pair<string, string> componente;

vector <string> Sentences;

void Rellenar(string parent1, string parent2, string name, int n)
{
    string urs;
    switch(n)
    {
        case 3: if(parent1=="mother") Traduccion.push_back("Die");
            else if (parent1=="father") Traduccion.push_back("Der");
            Traduccion.push_back(Traductor[parent2]);
            Traduccion.push_back("of");
            Traduccion.push_back(Traductor[name]);
            break;

        case 6: if(parent1=="mother") Traduccion.push_back("Eine");
            else if (parent1=="father") Traduccion.push_back("Ein");
            Traduccion.push_back("gross"+Traductor[parent2]);
            Traduccion.push_back("of");
            Traduccion.push_back(Traductor[name]);
            break;

        default: if((n>=9)&&(n%3==0)){
                if(parent1=="mother") Traduccion.push_back("Die");
                else if (parent1=="father") Traduccion.push_back("Der");
                for(int j=0;j<(n/3)-2;j++) urs+="ur";
                Traduccion.push_back(urs+"gross"+Traductor[parent2]);
                Traduccion.push_back("of");
                Traduccion.push_back(Traductor[name]);
            }
    }
}

void ShowVector(vector<string> & sLista)
{
    vector<string>::iterator pos;
    pos= sLista.begin();
    while(pos!=sLista.end()){
        cout<<*pos<< endl;
        pos++;
    }
}

void ShowList(list <string> & saLista)
{
    list <string>::iterator posa;
    posa= saLista.begin();
    while(posa!=saLista.end()){
        cout<<*posa<<" ";
        posa++;
    }
}

int main()
{
    Traductor.insert(componente("mother","mutter"));
    Traductor.insert(componente("father","vater"));
    Traductor.insert(componente("of","van"));
    Traductor.insert(componente("Mary","Maria"));
    Traductor.insert(componente("John","Johan"));
    string palabra;
    do{
        cin>>palabra;
        Sentences.push_back(palabra);
    }while( cin.get()!='\n');
    //ShowVector(Sentences);
    Rellenar(Sentences[1],Sentences[Sentences.size()-3],Sentences[Sentences.size()-1],Sentences.size()-1);
    ShowList(Traduccion);
    cout<<endl;
    return 0;
}

