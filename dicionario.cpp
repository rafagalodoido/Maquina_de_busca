
#include "dicionario.h"
using std::string;

int dicionario::idf(string palavra) {
	//precisa definir o docs
	indice_.Ler();
	string palavra;
	int freq;
	int idf;
	map<string, set<string>>::iterator itr;
	map<string,int> aux;
	for (itr = indice_.mapa().begin(); itr != indice_.mapa().end(); itr++) {
		palavra = itr->first;
		N = indice_.doc_quantity();
		nt = indice_.doc_number(palavra);
		freq = N / nt;
		idf = log2(freq);
		aux.insert(pair<string, int>(palavra, idf));
	}

	if (nt == 0) {
		idf = 0;
		cout << "palavra não encontrada." << endl;
	}
	return idf;
}
int dicionario::tf(string palavra) {
	string palavra;
	set<string> documento;
	map<string, int> tf;
	set<string>::iterator itr1;
	map<string, int>::iterator itr2;
	if (indice_.pertence(palavra)) {
		documento = m[palavra];
	}

	for (itr1 = documento.begin(); itr1 != documento.end(); itr1++) {
		tf[*itr1] = indice_.ocorrencias(palavra, *itr1);
	}

	return tf[palavra];
}
	
