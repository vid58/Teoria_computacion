#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

list <string> Traduccion;
map < string, string> Traductor;
vector <string> Sentences;//token english

vector <string> ParaTraducir;
list <string> tokenGerman;
list <string> tokenRegular;
list <string> tokenGeneracion;

typedef pair<string, string> componente;

////////////////////////////////////// Permite ingresar oraciones dentro del lenguaje o varias palabras
void Ingresar()
{
    string palabra;
    do{
        cin>>palabra;
        Sentences.push_back(palabra);
    }while( cin.get()!='\n');
    //ShowVector(Sentences);
}
////////////////////////////////////
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
///////////////////////////////////////

//////////////////////////////////////
bool CheckOracion(vector<string> &sOracion) {
    if (sOracion[0] == "The" || sOracion[0] == "the") 
    {
        if (sOracion[1] == "mother" || sOracion[1] == "father") 
        {
            if (sOracion[2] == "of") 
            {
                if (sOracion[3] == "Mary" || sOracion[3] == "John") return 1;
                 
                else 
                {
                    if (sOracion[3] == "the") 
                    {
                        int n = (sOracion.size() - 4) / 3;
                        if ((sOracion.size() - 4) % 3 == 0) {
                            for (int i = 0; i < n; i++) {
                                if (sOracion[1] == "mother" || sOracion[1] == "father") {
                                    if (sOracion[2] == "of") {
                                        if (sOracion[3] == "Mary" || sOracion[3] == "John")
                                            return 1;
                                        else {
                                            if (sOracion[3] == "the");
                                            else
                                                return 0;
                                        }
                                    } else return 0;
                                } else return 0;
                            }
                        } else return 0;
                    } else return 0;
                }
            } else return 0;
        }
    }
}


void Rellenar(string parent1, string parent2, string name, int n)
{
    string urs;
    switch(n)
    {
        case 3: if(parent1=="mother") Traduccion.push_back("Die");
            else if (parent1=="father") Traduccion.push_back("Der");
            Traduccion.push_back(Traductor[parent2]);
            Traduccion.push_back(Traductor["of"]);
            Traduccion.push_back(Traductor[name]);
            break;

        case 6: if(parent1=="mother") Traduccion.push_back("Eine");
            else if (parent1=="father") Traduccion.push_back("Ein");
            Traduccion.push_back("gross"+Traductor[parent2]);
            Traduccion.push_back(Traductor["of"]);
            Traduccion.push_back(Traductor[name]);
            break;

        default: if((n>=9)&&(n%3==0)){
                if(parent1=="mother") Traduccion.push_back("Eine");
                else if (parent1=="father") Traduccion.push_back("Ein");
                for(int j=0;j<(n/3)-2;j++) urs+="ur";
                Traduccion.push_back(urs+"gross"+Traductor[parent2]);
                Traduccion.push_back(Traductor["of"]);
                Traduccion.push_back(Traductor[name]);

            }
            else cout<<"Hay un error en el Lenguaje de la oración";
    }
}

void LLenarTraductor()
{
    Traductor.insert(componente("mother","mutter"));
    Traductor.insert(componente("father","vater"));
    Traductor.insert(componente("of","van"));
    Traductor.insert(componente("Mary","Maria"));
    Traductor.insert(componente("John","Johan"));
    Traductor.insert(componente("grand","gross"));
    Traductor.insert(componente("great","ur"));
}

void TraducirOraciones(bool n){
    if(n){
        Rellenar(Sentences[1],Sentences[Sentences.size()-3],Sentences[Sentences.size()-1],Sentences.size()-1);
        ShowList(Traduccion);
        cout<<endl;
    }
    else
        cout<<"La oracion no pertenece al Lenguaje.";

}


///////////////////////////////////

bool CheckSintaxis(vector<string> &sCS)
{
    if(sCS.size()==1){
        if(sCS[sCS.size()-1]=="mother"|| sCS[sCS.size()-1]=="father") return 1;
    }
    else if(sCS.size()==2){
        if(sCS[sCS.size()-1]=="mother"|| sCS[sCS.size()-1]=="father") if(sCS[sCS.size()-2]=="grand") return 1;
    }
    else if(sCS.size()>2)
    {
        if(sCS[sCS.size()-1]=="mother"|| sCS[sCS.size()-1]=="father") if(sCS[sCS.size()-2]=="grand") {
            bool check=1;
                for (int i = 0; i < sCS.size()-2; i++) {
                    if(sCS[i]!="great") return 0;
                }
                if(check==1) return 1;
        }
    }



}

void SepararPalabras(string palabra1)
{
    string trampa;
    if(palabra1.size()==6) ParaTraducir.push_back(palabra1);
    else {
        if (palabra1.size() < 6) ParaTraducir.push_back(palabra1);
        else {
            int NUM = (palabra1.size() - 6) / 5;//Separar en great o grand
            int contador = 0;
            for (int i = 0; i < NUM; i++)//Guardar los great's y grand
            {
                for (int j = 0; j < 5; j++) {
                    trampa += palabra1[contador];
                    contador++;
                }
                ParaTraducir.push_back(trampa);
                trampa = "";
            }
            for (int l = 0; l < 6; l++) {
                trampa += palabra1[contador + l];
            }
            ParaTraducir.push_back(trampa);
            trampa = "";
        }
    }
}

void Generaciones(vector<string>&genera)
{
    int entero= genera.size();
    string cadena=to_string(entero);
    tokenGeneracion.push_back(cadena+" generacion");
}

void LenguajeRegular(vector<string> &sLR)
{
    vector<string>::iterator posLR;
    posLR= sLR.begin();
    int contador=0;
    string leng;
    while(posLR!=sLR.end()){
        if(*posLR=="great"||*posLR=="grand") {leng+="g("; contador++;}
        else if(*posLR=="mother"){leng+="mo()";}
        else if(*posLR=="father"){leng+="fa()";}
        posLR++;
    }
    for(int g=0;g<contador;g++) leng+=")";
    tokenRegular.push_back(leng);
}

void TraducirPalabras(vector <string> &sVectorTP){
    vector <string> ::iterator itvector;
    itvector= sVectorTP.begin();
    while(itvector!=sVectorTP.end()){
        SepararPalabras(*itvector);
        if(CheckSintaxis(ParaTraducir))
        {
            string word;
            for (int i = 0; i < ParaTraducir.size(); i++) {
                word += Traductor[ParaTraducir[i]];
            }
            tokenGerman.push_back(word);
            LenguajeRegular(ParaTraducir);
            Generaciones(ParaTraducir);
            ParaTraducir.clear();
        }
        else
        {
            cout<<"La palabra "<<*itvector<<" no está dentro del lenguaje\n";
            ParaTraducir.clear();
        }
        itvector++;

    }
}

void Fin(){
    Sentences.clear();
    Traduccion.clear();
    tokenGerman.clear();
    tokenGeneracion.clear();
    tokenRegular.clear();
}

int main()
{
    LLenarTraductor();
    cout<<"Bienvenido al Traductor: \n";
    cout<<"¿Que deseas traducir?\n";
    cout<<"1.- Palabras\t"<<"2.- Oraciones\n";
    cout<<"Elige una de las dos opciones: ";
    int opcion;
    cin>>opcion;


    if(opcion==1)
    {
        cout<<"Escribe la(s) palabra(s) a traducir: \n\t";
        Ingresar();
        TraducirPalabras(Sentences);
        ShowList(tokenRegular);
        cout<<endl;
        ShowList(tokenGerman);
        cout<<endl;
        ShowList(tokenGeneracion);

    }
    else if(opcion==2)
    {
        cout<<"Escribe la oracion a traducir: \n\t";
        Ingresar();
        TraducirOraciones(CheckOracion(Sentences)==1);
    }

    Fin();
    return 0;
}
