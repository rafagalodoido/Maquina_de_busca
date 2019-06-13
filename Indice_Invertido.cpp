#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
#include "dicionario.h"
#include "Indice_Invetido.h"

using namespace std;

void File_reader::Ler() {
	ifstream doc;
	for (int i = 1; 1; i++) {
		doc_counter = i;
		doc.open("d" + to_string(i) + ".txt");
		if (!doc.is_open() && i == 1) {
			cout << "Falha na leitura" << endl;
			break;
		}
		if (!doc.is_open()) {
			break;
		}
		
		string palavra;
		while (!doc.eof()) {
			doc >> palavra;
			transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
			palavra.erase(remove_if(palavra.begin(), palavra.end(), [](char c) {return !isalpha(c) && !isdigit(c);}), palavra.end());
			set<string> valor = { "d" + to_string(i) + ".txt" };
			pair<map<string, set<string>>::iterator, bool> teste;
			teste = indice.insert(pair<string, set<string>>(palavra, valor));
			

			if (!teste.second) {
				string novo = "d" + to_string(i) + ".txt";
			
				indice[palavra].insert(novo);
			}

		}
		doc.close();
	}
};

void File_reader::Imprimir() {
	
	map<string, set<string>>::iterator itr;
	for (itr = indice.begin(); itr != indice.end(); itr++) {
		cout << itr->first << "->";
		for (auto e = itr->second.begin(); e != itr->second.end(); e++) {
			
			cout << *e <<"->";

		}

	}
};
map<string, set<string>> File_reader::mapa(){
	return indice;

}

bool File_reader::pertence(string palavra){
	return(indice.find(palavra) != indice.end());
}

size_t File_reader::doc_number(string c) {
	size_t count = 0;
	map<string, set<string>> aux;
	aux = indice;
	count = aux[c].size();
	return count;
	}

int File_reader::ocorrencias(string palavra_nova, string documento) {
	int conta = 0;
	ifstream doc;

	doc.open("documento");
	if (!doc.is_open()) {
		cout << "Falha na leitura" << endl;
	}

	string palavra;
	while (!doc.eof()) {
		doc >> palavra;
		transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);//trasnforma pra minuscula
		palavra.erase(remove_if(palavra.begin(), palavra.end(), [](char c) {return !isalpha(c) && !isdigit(c); }), palavra.end());// Retirar nao alfanumericos e digitos
		if (palavra == palavra_nova) {
			conta++;
		}
	}
	doc.close();
	return conta;
}



int File_reader::doc_quantity() {
	return doc_counter;
}

