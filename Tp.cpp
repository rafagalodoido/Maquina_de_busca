#include "TP.h"


void File_reader::Ler()const{
for(int i = 1; 1;i++){
    ifstream doc;
    doc.open("d" + to_string(i) +".txt");
    if (!doc.is_open() && i==1){
        cout<<"Falha na leitura"<<endl;
        break;
    }
     else if (!doc.is_open()){
        break;
}
    string palavra;
    while(!doc.eof()){
        doc >> palavra;
        set<string> valor = {"d" + to_string(i) +".txt"};
        pair<map<string,set<string>>::iterator,bool> teste;
        teste = indice.insert(std::pair<string,set<string>>(palavra,valor));
        if(!teste.second){
            indice[palavra].insert(valor);
        }

        }
    }


doc.close();
};

void File_reader::Indice_invertido()const{
    map<string,set<string>>::iterator itr;
    for(auto itr : indice){
        cout<< itr->first<<"->"<<itr->second<<endl;

    }
}

}
