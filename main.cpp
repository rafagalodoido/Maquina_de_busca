#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
#include "mapa.h"

using namespace std;

int main() {
	double aux;
	dicionario final;
	vector<double> pesquisa;
	vector<string>stringHolder;
	string busca;
	map<string, vector<double>> map_aux;
	final.cosine_ranking();
	map_aux = final.map_return();
	cout << "Digite a palavra para a busca:" << endl;
	while (cin >> busca) {
		stringHolder.push_back(busca);
	}
	sort(stringHolder.begin(), stringHolder.end());
	int ssize = stringHolder.size();
	if (ssize == 0) {
		cout << "No words" << endl;
		return 1;
	}

	int wordCount = 1;
	busca = stringHolder[0];
	for (int i = 1; i < ssize; i++) {
		if (busca != stringHolder[i]) {
			aux = final.idf(busca) * wordCount;
			pesquisa.push_back(aux);
			wordCount = 0;
			busca = stringHolder[i];
		}
		wordCount++;
	}


	map<string, vector<double>>::iterator it;
	for (it = map_aux.begin(); it != map_aux.end(); it++) {
		for (double i = 0; i < pesquisa.size(); i++) {
			if (it->second[i] - pesquisa[i] = 0 || it->second[i] - pesquisa[i] < 0, 2 || it->second[i] - pesquisa[i] >0, 2) {
				cout << "O documento que voce procura e"<< it->first << endl;
			}
		}
	}
}
