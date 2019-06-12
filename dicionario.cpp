
#include "dicionario.h"
using std::string;

 double dicionario::idf(File_reader c) {
	//precisa definir o docs
	 string palavra;
	 double freq;
	 double idf;
	 map<string, set<string>>::iterator itr;
	 map<string, double> aux;
	 for (itr = indice.begin(); itr != indice.end(); itr++) {
		 palavra = itr->first;
		 N = c.doc_quantity();
		 nt = c.doc_number(palavra);
		 freq = N / nt;
		 idf  = log2(freq);
		 aux.insert(pair<string, double>(palavra, idf));
	 }
	
	if (nt == 0) {
		idf = 0;
		cout << "palavra não encontrada." << endl;
	}
