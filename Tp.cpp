#include "TP.h"


File_reader::void Ler(const string)const{
for(int i = 1; 1;i++){
    ifstream doc
    doc.open("d" + to_string(i) +".txt");
    if (!doc.is_open && i==1){
            cout<<"Falha na leitura"<<endl
        break;
    }
    if (!doc.is_open){
        break;
}
doc.close;
}

};
