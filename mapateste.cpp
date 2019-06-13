#include <string>
#include <map>
#include <set>
#include <cmath>
#include "dicionario.h"
#include "Indice_Invertido.h"
#include "doctest.h"
using namespace std;

class Teste {
public:
  static int N_(const dicionario& d) {
    return  d.N;
  }
  static int nt_(const dicionario& d) {
    return  d.nt;
  }
  static string Pt_(const dicionario& d) {
    return  d.Pt;
  }
  static map<string,set<string>> indice_(const File_reader& c) {
    return  c.indice;
  }
  static set<string> docs_(const dicionario& d) {
    return  d.docs;
  }
  static int doc_counter_ (const File_reader& c) {
    return  c.doc_counter;
  }
};
TEST_SUITE("File_reader") {
  TEST_CASE("void Ler()") {
    File_reader f;
    f.Ler();
    CHECK(Teste::doc_counter_(f) == 2);
    CHECK(Teste::indice_(f).size() == 9);
  }
  TEST_CASE("bool pertence(string palavra)") {
    File_reader f;
    f.Ler();
    CHECK(f.pertence("carlos") == true);
    CHECK(f.pertence("jonatas") == true);
    CHECK(f.pertence("jesus") == false);
    CHECK(f.pertence("oi") == false);
    CHECK(f.pertence("meu") == true);
  }
  TEST_CASE("int doc_number(string c)") {
    File_reader f;
    f.Ler();
    CHECK(f.doc_number("carlos") == 1);
    CHECK(f.doc_number("jonatas") == 2);
    CHECK(f.doc_number("jesus") == 0);
    CHECK(f.doc_number("oi") == 0);
    CHECK(f.doc_number("meu") == 1);
  }
  TEST_CASE("int doc_quantity()"){
    File_reader f;
    f.Ler();
    CHECK(Teste::doc_counter_(f)== 2);
  }
  TEST_CASE("int ocorrencias(string palavra, string documento))"){
    File_reader f;
    f.Ler();
    CHECK(f.ocorrencias("carlos", "d1.txt") == 1);
    CHECK(f.ocorrencias("carlos", "d2.txt") == 0);
    CHECK(f.ocorrencias("jonatas", "d1.txt") == 1);
    CHECK(f.ocorrencias("jonatas", "d2.txt") == 1);
    CHECK(f.ocorrencias("jesus", "d1.txt") == 0);
    CHECK(f.ocorrencias("jesus", "d2.txt") == 0);

  }
}


TEST_SUITE("dicionario") {
  TEST_CASE("double idf(string palavra)") {
    dicionario d;
    d.idf("carlos");
    CHECK(Teste::N_(d) == 2);
    CHECK(Teste::nt_(d) == 1);
    CHECK(d.idf("carlos") == 1);
    d.idf("jesus");
    CHECK(Teste::N_(d) == 2);
    CHECK(Teste::nt_(d) == 0);
    CHECK(d.idf("jesus") == 0);
    d.idf("jonatas");
    CHECK(Teste::N_(d) == 2);
    CHECK(Teste::nt_(d) == 2);
    CHECK(d.idf("jonatas") == 0);
  }
  TEST_CASE("int tf(string palavra)") {
      dicionario d;
    CHECK(d.tf("carlos") == 1);
    CHECK(d.tf("jesus") == 0);
    CHECK(d.tf("jonatas") == 1);
  }
  TEST_CASE("float w(string s)"){
    dicionario d;
    d.w("carlos");
    CHECK(d.idf("carlos")==2);
    CHECK(d.tf("carlos")==1);
    CHECK(d.w("carlos")==2);
    d.w("jesus");
    CHECK(d.idf("jesus")==0);
    CHECK(d.tf("jesus")==0);
    CHECK(d.w("jesus")==0);
    d.w("jonatas");
    CHECK(d.idf("jonatas")==0);
    CHECK(d.tf("jesus")==1);
    CHECK(d.w("jesus")==0);
    }
  }
