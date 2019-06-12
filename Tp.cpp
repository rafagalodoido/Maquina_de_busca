#include "Indice_Invertido.h"

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
			
			cout << *e <<"->"<< endl;

		}

	}
};

int File_reader::doc_number(string c) {
	int count = 0;
	map<string, set<string>> aux;
	aux = indice;
	count = aux[c].size();
	return count;
	}



int File_reader::doc_quantity() {
	return doc_counter;
}

