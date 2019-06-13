#include "mapa.h"
#include "Indice_Invertido.h"
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
using namespace std;

double dicionario::idf(string palavra) {
	indice_.Ler();
	double freq;
	double idf_;
	map<string, set<string>>::iterator itr;
	map<string,double> aux;
	for (itr = indice_.mapa().begin(); itr != indice_.mapa().end(); itr++) {
		palavra = itr->first;
		N = indice_.doc_quantity();
		nt = indice_.doc_number(palavra);
		freq = N / nt;
		idf_ = log2(freq);
		aux.insert(pair<string, double>(palavra, idf_));
	}

	if (nt == 0) {
		idf_ = 0;
		cout << "palavra não encontrada." << endl;
	}
	return aux[palavra];
}

double dicionario::tf(string palavra) {
	indice_.Ler();
	set<string> documento;
	map<string, double> tf_;
	set<string>::iterator itr1;
	m = indice_.mapa();
	if (indice_.pertence(palavra)) {
		documento = m[palavra];
	}

	for (itr1 = documento.begin(); itr1 != documento.end(); itr1++) {
		tf_[*itr1] = indice_.ocorrencias(palavra, *itr1);
	}

	return tf_[palavra];
}
	
double dicionario::w(string palavra) {
	dicionario d;
	double w_;
	w_ = d.idf(palavra) * d.tf(palavra);
	return w_;
}

void dicionario::cosine_ranking() {
	dicionario d;
	string aux;
	vector<double> pesq_;
	ifstream doc;
	for (int i = 1; 1; i++) {
		doc.open("d" + to_string(i) + ".txt");
		if (!doc.is_open() && i == 1) {
			cout << "Falha na leitura" << endl;
			break;
		}
		if (!doc.is_open()) {
			break;
		}
		string documento;
		string palavra;
		while (!doc.eof()) {
			doc >> palavra;
			transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
			palavra.erase(remove_if(palavra.begin(), palavra.end(), [](char c) {return !isalpha(c) && !isdigit(c); }), palavra.end());			
			pesq_.push_back(d.w(palavra));
			
			documento = "d" + to_string(i) + ".txt";
			mapa_busca.insert(pair<string, vector<double>>(documento, pesq_));
			
		}
		doc.close();
	}
};

map<string, vector<double>> dicionario::map_return() {
	return mapa_busca;
}

double dicionario::sim(string palavra) {
	dicionario d;
	return (d.w(palavra) * d.w(palavra)) / sqrt((d.w(palavra) * d.w(palavra)) * (d.w(palavra) * d.w(palavra)));

}
		

