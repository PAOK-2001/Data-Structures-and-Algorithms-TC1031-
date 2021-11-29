// Actividad 3.3: Arbol AVL
// Fecha: 21/10/2021
// Descripción: implementa la estrucutra de datos de un árbol AVL
// Autores: Pablo Agustín Ortega Kral A00344664
#include<bits/stdc++.h>
#include<queue>
using namespace std;
// Clase nodo
class Node{
    public:
    int key;
    Node *left, *right;
    int height;

};
// getHeight
// IN:  Apuntador a un Nodo
// OUT: Entero (Altura del nodo en cuestión)
int getHeight(Node* test){
    if (!test){
      return 0;
    }
    return test->height;
}
// balanceFactor
// IN:  Apuntador a un Nodo
// OUT: Entero (Altura del nodo en cuestión)
// Description: calcula y regresa el balance factor del nodo al
// restar la altura del subárbol izquierdo y derecho
int balanceFactor(Node* test){
    if (!test){
      return 0;
    }
    return getHeight(test->left) - getHeight(test->right);
}
// Rotaciones 

// r_rotatation
// IN:  Apuntador a un Nodo raiz
// OUT: un nuevo nodo que ocupa el lugar de la raiz
// Description: cambia los apuntadoras del nodo suministrado y su hijo para 
// realizar una rotación a la derecha, retornando el nuevo nodo raiz
Node *r_rotatation(Node *n){
	Node *n1 = n->left;
	Node *n2 = n1->right;
	n1->right = n;
	n->left = n2;
	n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
	n1->height = max(getHeight(n1->left), getHeight(n1->right)) + 1;

	return n1;
}
// l_rotation
// IN:  Apuntador a un Nodo raiz
// OUT: un nuevo nodo que ocupa el lugar de la raiz
// Description: cambia los apuntadoras del nodo suministrado y su hijo para 
// realizar una rotación a la izquierda, retornando el nuevo nodo raiz
Node *l_rotation(Node *n){
	Node *n1 = n->right;
	Node *n2 = n1->left;

	n1->left = n;
	n->right = n2;

	n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
	n1->height = max(getHeight(n1->left), getHeight(n1->right)) + 1;

	return n1;
}
// newNode
// IN:  Entero (correspondiente al nuevo key)
// OUT: un objeto Nodo, con el key suministrado
// Description: función auxiliar para la creación de Nodos con los valores "default",
// asignado el atributo k al argumento suministrado, los apuntafores a NULL y la altura a 1
Node* newNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}
// balanceTree
// IN:  Nodo (elemento a balancear) Entero (correspondiente al K del elemento)
// OUT: Objeto nodo correspondiente a la nueva raiz
// Description: calcula el balance factor del nodo suministrado, después determina y aplica la rotación necesaria
// para balancear el árbol
// Complejidad O(1)
Node* balanceTree(Node* root, int k){
    // Se calcula el balance factor y hacen las rotaciones pertinentes
	// Caso LL: se rota  la derecha
	if (balanceFactor(root) > 1 && k < root->left->key){
		return r_rotatation(root);
    }
	// Caso RR_ se rota la derecha
	if (balanceFactor(root) < -1 && k > root->right->key){ 
		return l_rotation(root);
    }
	// Caso LR: primero se realiza una left rotation y luego una right
	if (balanceFactor(root) > 1 && k > root->left->key){
		root->left = l_rotation(root->left);
		return r_rotatation(root);
	}
	// Caso RL: Primero se rota la derehca luego a la izquierda
	if (balanceFactor(root) < -1 && k < root->right->key){
		root->right = r_rotatation(root->right);
		return l_rotation(root);
	}
	/// Regresa la nueva raiz
	return root;
}
// insert
// IN:  Nodo (raiz del árbol AVL) y Entero (key del nuevo elemento)
// OUT: Objeto nodo correspondiente a la raiz del árbol
// Description: crea un nuevo nodo de key K y lo inserta utilizando el algoritmo de un BST
// después, llama la función balanceTree() para balancearse y retornar la nueva raiz
// Complejidad O(logN)
Node * insert(Node * root, int k){
    // Primero se inserta el nodo en el árbol de manera normal como si fuera un BST normal
    if(!root){
        return newNode(k);
    }
    if (k < root->key) {
        root->left = insert(root->left, k);
    }
    else if (k > root->key){ 
        root->right = insert(root->right, k);
    }
    else { 
        return root;
    }
    // Se actualiza la altura del nodo en cuestion, al ser recursiva, esto acomoda apropiadamente la altura 
    // todos los nodos
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    return balanceTree(root, k);
}
// deepestLeft
// IN:  Nodo
// OUT: Nodo (correspondiente al menor valor del subárbol izquierdo)
Node* deepestLeft(Node* n){
    Node* minN = n;

    while (minN-> left){
        minN = minN -> left;
    }
    return minN;
}
// deleteNode
// IN:  Nodo (raiz del árbol AVL) y Entero (key del elemento a borrar)
// OUT: Objeto nodo correspondiente a la raiz del árbol
// Description: encuentra el elemento a borrar y lo elimina como si fuera un BTS normal
// llama la función balanceTree() para acomodar el árbol y retornar la nueva raíz
// Complejidad O(logN)
Node* deleteNode(Node* root, int k){
    // Primero encontramos el nodo a borrar, buscándolo recursivamente
    if(root == NULL){
          return NULL;
    }
    // Buscamos en el subarbol izquierdo
    if(k < root-> key){
        root -> left = deleteNode(root->left, k);
    }
    //Buscamos en el subarbol derecho
    else if( k > root -> key){
        root -> right = deleteNode(root -> right, k);
    }
    // Encontramos el valor y empezamos el proceso de borrar
    else{
         //node with no child
          if( (root -> left == NULL) && (root -> right = NULL)){
            delete root;
          }
          //Node with one Child
          else if(root -> left == NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
          }
          else if(root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
          }
          // Node with 2 Childs
          else{
            Node* temp = deepestLeft(root -> right);
            root -> key = temp -> key;
            root -> right = deleteNode(root -> right, temp -> key);
          }
    }
    // Actualizamos altura del ancestro
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    // Balanceamos el árbol
    return balanceTree(root, k);
}
// printInorder
// IN:  Nodo (raiz del árbol AVL) 
// Description: imprime a consola los elementos del árbol en orden: subarbol izquirdo, raiz, subarbol derecho
void printInorder(Node *root){
  if(root){
    printInorder(root->left);
    cout << root->key << endl;
    printInorder(root->right);
  }
}
// printPreorder
// IN:  Nodo (raiz del árbol AVL) 
// Description: imprime a consola los elementos del árbol en preorden: raiz, subarbol izquierdo, subarbol derecho
void printPreorder(Node *root){
  if(root){
    cout << root->key << endl;
    printPreorder(root->left);
    printPreorder(root->right);
  }
}
// printPostorder
// IN:  Nodo (raiz del árbol AVL) 
// Description: imprime a consola los elementos del árbol en post-orden: subarbol izquierdo, subarbol derecho, raiz
void printPostorder(Node *root){
  if(root){
    printInorder(root->left);
    printInorder(root->right);
    cout << root->key << endl;
  }
}
// printLevel
// IN:  Nodo (raiz del árbol AVL) 
// Description: imprime a consola los elementos del árbol por niveles
void printLevel(Node *root){
  if(root==NULL){
    return;
  }

  else{
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false){
      Node * print(q.front());
      cout<<print->key<<endl;
      q.pop();
      
      if(print->left != NULL){
        q.push(print->left);
      }

      if(print->right!=NULL){
        q.push(print->right);
      }
    }
  }
}
// find
// IN:  Nodo (raiz del árbol AVL) 
// OUT: Entero del valor encontrado
// Complejidad O(logN)
int find(Node* root, int k){
  if(!root){
        return 0;
    }
    if (k < root->key) {
      find(root->left, k);
    }
    else if (k > root->key){ 
      find(root->right, k);
    }
    else { 
        return root->key;
  }
}
// size
// IN:  Nodo (raiz del árbol AVL) 
// OUT: Entero del tamño del arbol
// Complejidad O(1)
int size(Node* root){
  return root->height;
}
int main(){
    Node *root = NULL;
     
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 35);
    root = insert(root, 69);
    root = insert(root, 4);
    root = insert(root, 25);
    cout<<"Tamaño: "<<size(root)<<endl;
    cout<<"Busca 25:  "<<find(root,25)<<endl;
    printPreorder(root);
    cout<<"Borrando nodo 25"<<endl;    
    root = deleteNode(root, 25);
    printPreorder(root);

    return 0;
}