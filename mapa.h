#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
#include<vector>
#include "Indice_Invertido.h"
using namespace std;
using std::string;

class dicionario {
public:
	// é a importância de Pt na coleção.
	double idf(string palavra);
	//é a frequência da palavra Pt no documento dj.
	double tf(string palavra);
	//é a coordenada do documento dj no eixo Pt
	double w(string palavra);
	//Preenche o vetor q
	double cosine_ranking();
	//retorna o map mapa_busca
	map<string, vector<double>> map_return();
	//Realiza o cálculo de sim para todos os documentos
	double sim(string palavra);
	
private:
	//variavel File_reader
	File_reader indice_;
	//número total de documentos.
	int N=0;
	//número de documentos que a palavra Pt ocorreu.
	size_t nt=0;
	//palavra recebida
	string Pt;
	//mapa que recebe a palavra como chave e cada valor é o conjunto (set) com os nomes dos documentos.
	map<string, set<string>> m;
	// recebe o valor da busca
	map<string, vector<double>> mapa_busca;
};
#endif // MAPA_H_INCLUDED
