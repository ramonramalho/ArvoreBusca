#include "ArvoreBuscaAluno.h" 
#include <iostream>

using namespace std;

//destructor 
void ArvoreBuscaAluno::destroyTree(NodeAluno*& tree){
	//TODO
}

//insere um aluno 
//insert a student
void ArvoreBuscaAluno::insertAluno(NodeAluno*& tree, Aluno item){
	if(tree==NULL){
		//verify if the root is NULL
		//create a new NodeAluno and insert of the new position
		NodeAluno* novo = new NodeAluno;		
		novo->aluno = item;
		//the old connects with the current
		tree = novo;
		return;
	}
	if(tree->aluno.getRa() > item.getRa() ){
		//if the number of student is smaller that number of the root
		//insert on left
		insertAluno(tree->esquerda, item);
	}else{
		//if not
		//insert on right
		insertAluno(tree->direita, item);
	}
 }
 
//print the tree in Pre Order
void ArvoreBuscaAluno::printPreOrder(NodeAluno* tree)  const{
 	if(tree!= NULL){
 	//while root is diferent of NULL
 		//print the root
 		cout << tree->aluno.getNome() << " ";
 		//walk to left
 		printPreOrder(tree->esquerda);
 		//walk to right
 		printPreOrder(tree->direita);
 	}
 }
 
 //print the tree in Order
 void ArvoreBuscaAluno::printInOrder(NodeAluno* tree)   const{
 	if(tree!= NULL){
 		//while root is diferent of NULL
 		//walk to left
 		printPreOrder(tree->esquerda);
 		//print the root
 		cout << tree->aluno.getNome() << " ";
 		//walk to right
 		printPreOrder(tree->direita);
 	}
 }
 
 //print the tree Post Order
void ArvoreBuscaAluno::printPostOrder(NodeAluno* tree) const{
 	if(tree!= NULL){
 	//while root is diferent of NULL
 		//walk to left
 		printPreOrder(tree->esquerda);
 		//walk to right
 		printPreOrder(tree->direita);
 		//print the root
 		cout << tree->aluno.getNome() << " " ;	
 	}
 }
