#include "ArvoreBuscaAluno.h"


int main() {
  // Untemplated queue of char
  // Templated heap
  ArvoreBuscaAluno alunosArvore;

  int         ras[7]    = {12704  , 31300 , 1234  , 49001   , 52202  , 65606  , 91234    };
  std::string nomes[7] = {"Pedro", "Raul", "Paulo", "Carlos", "Lucas", "Maria", "Samanta"};

  for (int i = 0; i < 7; i++) {
    Aluno aluno = Aluno(ras[i], nomes[i]);
    alunosArvore.insertAluno(aluno);
  }
  alunosArvore.printTree();
 
}
