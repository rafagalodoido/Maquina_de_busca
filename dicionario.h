#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
#include "Indice_Invertido.h"
using namespace std;
using std::string;

class dicionario {
public:
	// é a importância de Pt na coleção.
	double idf(File_reader c);
	//é a frequência da palavra Pt no documento dj.
	int tf(string palavra);
	//é a coordenada do documento dj no eixo Pt
	float w();
private:
	//número total de documentos.
	int N;
	//número de documentos que a palavra Pt ocorreu.
	int nt;
	//palavra recebida
	string Pt;
	//mapa que recebe a palavra como chave e cada valor é o conjunto (set) com os nomes dos documentos.
	map<string, set<string>> m;
	set<string> docs;
};
#endif // MAPA_H_INCLUDED
