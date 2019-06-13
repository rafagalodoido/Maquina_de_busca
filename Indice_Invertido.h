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
	//Função para ler os documentos da coleção.
	void  Ler();
	//Função para imprimir os documentos da coleção.
	void Imprimir();
	//Retorna o tamanho do set da string.
	size_t doc_number(string c);
	//Retorna o número de documentos da coleção. 
	int doc_quantity();
	//Retorna se a palavra existe até o end do map.
	bool pertence(string palavra);
	//Função para retornar o índice.
	map<string, set<string>> mapa();
	//Abre o documento e enquanto documento aberto, lê todas as palavras.
	int ocorrencias(string palavra, string documento);
	

private:
	//mapa para armazenar o índice.
	map<string, set<string>> indice;
	//Número de documentos da coleção
	int doc_counter=0;
	friend class Teste;
	
};




#endif

