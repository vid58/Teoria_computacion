#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

list <string> Traduccion;
vector <string> TraduccionI;
map < string, string> TraductorAleman;
map < string, string> TraductorItaliano;
vector <string> Sentences;//token english

vector <string> ParaTraducir;
list <string> tokenGerman;
list <string> tokenItaliano;;
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
string Darist(list <string> & saLista)
{
    list <string>::iterator posa;
    posa= saLista.begin();
    string word=*posa;
    return word;
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

void TraducirPalabras(vector <string> &sVectorTP, string idioma, int j);
void Rellenar(string parent1, string name, int n, string id)
{
    string urs;
    if(id=="Aleman") {
        switch (n) {
            case 3:
                if (parent1 == "mother") Traduccion.push_back("Die");
                else if (parent1 == "father") Traduccion.push_back("Der");
                Traduccion.push_back(TraductorAleman[parent1]);
                Traduccion.push_back(TraductorAleman["of"]);
                Traduccion.push_back(TraductorAleman[name]);
                break;

            case 6:
                if (parent1 == "mother") Traduccion.push_back("Eine");
                else if (parent1 == "father") Traduccion.push_back("Ein");
                Traduccion.push_back("gross" + TraductorAleman[parent1]);
                Traduccion.push_back(TraductorAleman["of"]);
                Traduccion.push_back(TraductorAleman[name]);
                break;

            default:
                if ((n >= 9) && (n % 3 == 0)) {
                    if (parent1 == "mother") Traduccion.push_back("Eine");
                    else if (parent1 == "father") Traduccion.push_back("Ein");
                    for (int j = 0; j < (n / 3) - 2; j++) urs += "ur";
                    Traduccion.push_back(urs + "gross" + TraductorAleman[parent1]);
                    Traduccion.push_back(TraductorAleman["of"]);
                    Traduccion.push_back(TraductorAleman[name]);

                } else cout << "Hay un error en el Lenguaje de la oración";
        }
    }
    else if (id=="Italiano")
    {
        switch (n) {
            case 3:
                TraduccionI.push_back(parent1);
                break;
            case 6:
                TraduccionI.push_back("grand" + parent1);
                break;

            default:
                if ((n >= 9) && (n % 3 == 0)) {
                    for (int j = 0; j < (n / 3) - 2; j++) urs += "great";
                    TraduccionI.push_back(urs + "grand" + parent1);

                } else cout << "Hay un error en el Lenguaje de la oración";

        }
        Traduccion.push_back("Il");
        TraducirPalabras(TraduccionI, id, 1);
        string wordI;

       wordI=Darist(tokenItaliano);

        Traduccion.push_back(wordI);
        Traduccion.push_back("di");
        Traduccion.push_back(name);
    }
}

void LLenarTraductorAleman()
{
    TraductorAleman.insert(componente("mother","mutter"));
    TraductorAleman.insert(componente("father","vater"));
    TraductorAleman.insert(componente("of","von"));
    TraductorAleman.insert(componente("Mary","Maria"));
    TraductorAleman.insert(componente("John","Johan"));
    TraductorAleman.insert(componente("grand","gross"));
    TraductorAleman.insert(componente("great","ur"));
}

void LLenarTraductorItaliano()
{
    TraductorItaliano.insert(componente("mother","madre"));
    TraductorItaliano.insert(componente("father","padre"));
    TraductorItaliano.insert(componente("of","di"));
    TraductorItaliano.insert(componente("Mary","Mary"));
    TraductorItaliano.insert(componente("John","John"));
    TraductorItaliano.insert(componente("grand","nonno"));
    TraductorItaliano.insert(componente("great","grandissim"));
}

void TraducirOraciones(bool n, string idiom){
    if(n||idiom=="Aleman"){
        Rellenar(Sentences[1],Sentences[Sentences.size()-1],Sentences.size()-1, idiom);
        ShowList(Traduccion);
        cout<<endl;
    }
    else  cout<<"La oracion no pertenece al Lenguaje.";

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

void TraducirPalabras(vector <string> &sVectorTP, string idioma, int i){
    vector <string> ::iterator itvector;
    itvector= sVectorTP.begin();
    while(itvector!=sVectorTP.end()){
        SepararPalabras(*itvector);
        if(CheckSintaxis(ParaTraducir))
        {
            string word;

            if(idioma=="Aleman") {
                for (int i = 0; i < ParaTraducir.size(); i++) {
                    word += TraductorAleman[ParaTraducir[i]];
                }
                tokenGerman.push_back(word);
                LenguajeRegular(ParaTraducir);
                Generaciones(ParaTraducir);
                ParaTraducir.clear();
            }
            else if(idioma=="Italiano")
            {
                for (int i = 0; i < ParaTraducir.size(); i++)
                {
                    if (i == ParaTraducir.size() - 3) word += "bis";
                    if (i==ParaTraducir.size()-2) {
                        if(ParaTraducir[ParaTraducir.size()-1]=="mother") word +="nonna";
                        else word += "nonno";
                    }
                    if(ParaTraducir.size()-i >3) {
                        word += TraductorItaliano[ParaTraducir[i]];
                        if(ParaTraducir[ParaTraducir.size()-1]=="mother") word +="a ";
                        else word += "o ";
                    }
                    if(ParaTraducir.size()==1) word+=TraductorItaliano[ParaTraducir[i]];
                }
                    tokenItaliano.push_back(word);

            }

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
    LLenarTraductorAleman();
    LLenarTraductorItaliano();
    cout<<"Bienvenido al Traductor: \n";
    cout<<"¿Que deseas traducir?\n";
    cout<<"1.- Palabras\t"<<"2.- Oraciones\n";
    cout<<"Elige una de las dos opciones: ";
    int opcion;
    cin>>opcion;

    cout<<"¿En que idioma quieres traducir?\n 1. Aleman \t 2. Italiano\n";
    int ido;
    cout<<"Ingresa numero de opcion: ";
    cin>>ido;
    string idiom;
    if(ido==2)idiom="Italiano";
    if(ido==1)idiom="Aleman";

    if(opcion==1)
    {
        cout<<"\nEscribe la(s) palabra(s) a traducir: \n\t";
        Ingresar();

        TraducirPalabras(Sentences, idiom,0);
        ShowList(tokenRegular);
        cout<<endl;
        if(ido==2)ShowList(tokenItaliano);
        else ShowList(tokenGerman);
        cout<<endl;
        ShowList(tokenGeneracion);

    }
    else if(opcion==2)
    {
        cout<<"\nEscribe la oracion a traducir: \n\t";
        Ingresar();
        TraducirOraciones(CheckOracion(Sentences)==1, idiom);
    }

    Fin();
    return 0;
}