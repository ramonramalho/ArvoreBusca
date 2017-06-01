#include <cstddef>
#include <iostream>

//class Student
class Aluno{
 public:

//constructor
  Aluno(){
    this->ra   = -1;
    this->nome = "";
  };

 //other constructor
 Aluno(int ra, std::string nome){
    this->ra    = ra;
    this->nome  = nome;
 }

 //retur name of student
 std::string getNome() const {
    return nome;
 }

//return number of student
 int getRa() const{
    return ra;
  }

 
 private :
  //ra is number of student
  int         ra;
  //nome is name of student
  std::string nome;
};

//NodeAluno is a node of the students
//esquerda save the adrees children of nodes on left
//direita save the adrees children of nodes on right
struct NodeAluno
{
  Aluno      aluno;
  NodeAluno* esquerda;
  NodeAluno* direita;
};


class ArvoreBuscaAluno
{


 public:  
  ArvoreBuscaAluno() {
    root = NULL;
  }
    
  ~ArvoreBuscaAluno(){
   destroyTree(root);
  }

  // Ignore este metodo, jah esta completamente implementado.
  void printTree() const
  {
    printTree(root);
  }
  
  // Verifica se a arvore possui pelo menos um no.
  bool isEmpty() const;

  // Verificar se eh possivel alocar um novo no.
  bool isFull() const;

/* Todos os metodos publicos abaixo jah estao implementados, nao
   redefina. Voce deverah se preocupar apenas com os metodos privados
   que implementam a funcionalidade invocada por esses metodos
   publicos. */
  
  void retrieveAluno(Aluno& item, bool& found) const{
    retrieveAluno(root, item, found);
  }

  // Nos metodos seguintes, use os metodos privados de mesmo nome para
  // fazer de forma recursiva.
  void insertAluno(Aluno item){
    insertAluno(root, item);
  }
  
  void deleteAluno(Aluno item){
    deleteAluno(root, item);
  }


 private:

  // Funcoes recursivas que serao usados por algumas das funcoes
  // publicas.


  // O construtor dessa classe invocara destroyTree. Em resumo, voce
  // devera caminhar pela arvore apagando todos os nos que
  // existem. Cuidado com a ordem em que voce faz a chamada ao
  // delete. Garanta que soh invocarah o comando delete apos ambos os
  // filhos terem sido removidos.
  void destroyTree(NodeAluno*& tree);


  // O metodo publico chamado de retrieveAluno ira fazer uma chamada
  // para este metodo. Implemente este metodo de forma recursiva. Para
  // isso que serve o primeiro parametro NodeAluno *tree.
  
  // Voce vai receber um objeto item que serah usado como chave. Apos
  // isso, voce tera que procurar se na sua arvore existe algum noh
  // com essa chave. Se existir, entao voce coloca em "item" (no
  // proprio parametro) o objeto que estava no noh da sua arvore.

  // Use a variavel found para avisar a quem chamou se o objeto item
  // foi alterado ou nao. Em outras palavras, avise em found se o no
  // existe ou nao.
 
  void retrieveAluno(NodeAluno* tree, Aluno& item, bool& found) const;

  // De forma analoga, os metodos abaixo deverao ser chamados pelos
  // metodos publicos. Os parametros NodeAluno*& tree estao ai para voce
  // implementar de forma recursiva.
  void insertAluno(NodeAluno*& tree, Aluno item);

  // Use este metodo privado apenas para navegar pela arvore ate
  // encontrar o no que voce deseja excluir. Feito isso, chame o
  // metodo deleteNodeAluno passando como parametro o no que voce
  // encontrou.
  void deleteAluno(NodeAluno*& tree, Aluno item);

  // Nesse metodo, voce receberah como parametro o no que precisa ser
  // removido. Observe que temos tres casos: (i) o no pode ser uma
  // folha, (ii) o no pode ter um filho e (iii) o no pode ter dois
  // filhos. Caso o no tenha dois filhos, voce deverah chamar o metodo
  // getSuccessor para obter o no que deverah substituir o no atual
  // antes da remocao.
  void deleteNodeAluno(NodeAluno*& tree); 

  // Procure o sucessor do no atual na arvore. Em outras palavras,
  // procure o no mais a esquerda da arvore da direita.
  void getSuccessor(NodeAluno* tree, Aluno& data);


  void printTree(NodeAluno *tree) const
  {
    std::cout << "Pre:  ";
    printPreOrder(tree);
    std::cout << std::endl;
    std::cout << "In:   ";
    printInOrder(tree);
    std::cout << std::endl;
    std::cout << "Post: ";
    printPostOrder(tree);
    std::cout << std::endl;
  }
  
  void printPreOrder(NodeAluno* tree)  const;
  void printInOrder(NodeAluno* tree)   const;
  void printPostOrder(NodeAluno* tree) const;
  
  // Nossa estrutura de dados. Raiz da arvore binaria de busca.
  NodeAluno* root;
};
