//
// Created by claudioecharre on 12/02/20.
//

#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

list <string> Traduccion;

/* int LENGHT=16;//Longitud de la oración sin rellenos
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
 */
typedef pair<string, string> componente;

vector <string> Sentences;

void ShowList(vector<string> & sLista)
{
    vector<string>::iterator pos;
    pos= sLista.begin();
    while(pos!=sLista.end()){
        cout<<*pos<< endl;
        pos++;
    }
}

int main()
{
    map <const string, const string> Traductor;
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
    ShowList(Sentences);





    Rellenar(Sentences[1],Sentences[Sentences.size()-3],Sentences[Sentences.size()],Sentences.size());

    for (int i = 0; i <4 ; i++) {
        cout<<translate[i]<<" ";
    }
    cout<<endl;

    return 0;

}

