#ifndef Indice_Invertido_H
#define Indice_Invertido_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;
using std::string;
class File_reader {
public:
	void  Ler();

	void Imprimir();

	size_t doc_number(string c);

	int doc_quantity();

	bool pertence(string palavra);

	map<string, set<string>> mapa();

	int ocorrencias(string palavra, string documento);
	

private:
	map<string, set<string>> indice;
	int doc_counter=0;
	friend class Teste;
	
};




#endif

