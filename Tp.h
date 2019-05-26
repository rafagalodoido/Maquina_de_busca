#ifndef TP_H
#define TP_H
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;
using std::string;
class File_reader{
public:
void  Ler()const;

void Inserir(string s)const;

void Indice_invertido();

private:
map<string,set<string>> indice;
int doc_number;

};




#endif
