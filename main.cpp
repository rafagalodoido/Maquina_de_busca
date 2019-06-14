#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
#include "dicionario.h"
#include "Indice_Invertido.h"

using namespace std;

int main() {
	File_reader arquivos;
	double aux;
	dicionario final;
	vector<double> pesquisa;
	vector<string>stringHolder;
	string busca;
	map<string, vector<double>> map_aux;
		cout<<"Digite a palavra para a busca:" << endl;
		cin >> busca; 
		arquivos.Ler();
		arquivos.Imprimir();

	final.cosine_ranking();
	map_aux = final.map_return();
	map<string, vector<double>>::iterator it;
	for (it = map_aux.begin(); it != map_aux.end(); it++) {
		for (double i = 0; i < pesquisa.size(); i++) {
			double result = (it->second[i] * pesquisa[i])/sqrt((it->second[i]it->second[i])(pesquisa[i]*pesquisa[i])); 
			if (final.sim(busca) == result|| final.sim(busca) - result>0.5) {
				cout << "O documento que voce procura e"<< it->first << endl;
			}
		}
	}
}
