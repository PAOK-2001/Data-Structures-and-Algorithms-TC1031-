/*
Actividad 5.1
Autor: Pablo Agustín Ortega Kral A00344664
Fecha: 22/11/2021
Descripción: Implementae una tabla de dispersión que incluya su técnica de hashing así como el manejo de colisiones a través de dirección abierta y sondeo cuadrático.
*/
#include <bits/stdc++.h>
using namespace std;
// Clase Nodo para construir una lista ligada
class Node {
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
// Clase set donde el hash es %11
class Set{
    public:
        vector<Node*> set_chainning = vector<Node*>(11); 
        vector<int> set_quadratic = vector<int>(11);
        /*
        *insert_channing
        * Complejidad O(Colision); lidia con las collisiones en una Hash tabla usando chainning, es decir almacenando los valores colisionados en una linked list
        * @param insert(int) valor a almacenar
        */
        void insert_chainning(int insert){
            int index = insert % 11; 
            Node* insertedValue= new Node(insert);
            
            if(!set_chainning[index] && !search(set_chainning[index], insert)) {
                set_chainning[index] = insertedValue; 
                return;
            } 
            insertToNode(set_chainning[index],insertedValue);
            return;
        }
        /*
        *printSet_chainning
        * Complejidad O(n); imprime el HashTable por chainning
        */
        void printSet_chainning(){
            for(auto node : set_chainning ){
                printLinkedList(node);
            }
        }
         /*
        *chainning_lookup
        * Complejidad O(n); realiza una búsqueda en el linked list
        * @param target(int) valor buscado
        * @returns booleano que indica si el valor existe
        */
        bool chainning_lookup(int target) {
            int index = target % 11; 
            return search(set_chainning[index], target);
        }
        /*
        *insert_quadratic
        * Complejidad O(Colisiones) Realiza una búsqueda en el linked list
        * @param insert(int) valor almacenado en el hash table
        */
        void insert_quadratic(int insert){
            int newIndex;
            int index = insert%11; // HashFunction
            if (!set_quadratic[index]){
            	set_quadratic[index] = insert;
        	}else{
              	for(int i = 0; i<11;i++){
                    newIndex = (index + (int)pow(i,2))%11; // nuevo indice calculado con cuadratic probing
                    if(set_quadratic[newIndex]){
                        continue;
                        
                    }else{
                        set_quadratic[newIndex]=insert;
                        break;

                    }
              }
            }
        }
        /*
        *printQ
        * Compleidad O(n); imprime el conjunto alamcenado por quadratic probing
        */
        void printQ(){
            for(int i = 0; i<11; i++){
              if(set_quadratic[i]){
                cout<<set_quadratic[i]<<"\n";
              }else{
                  cout<<"NONE\n";
              }
            }
        }
        
    private: 
        /*
        *insertToNode
        * Complejidad O(n); inserta un valor a la linked list
        * @param head(Node *) cabeza de la linked list
        * @param insertedValue(Node*) nodo a insertar
        */
        void insertToNode(Node* head, Node* insertedValue){
            Node* current = head;
            while(current->next){
                current = current->next; 
            } 
            current->next = insertedValue; 
            return;
        }
        /*
        * search
        * Complejidad O(n)
        * @param head(Node*) cabeza de la linked list
        * @param key(int)
        * @returns booleano que es verdadero si el valor se encuentra 
        */
        bool search(Node* head, int key){
            Node* current = head;
            while(current){
                if(current->data == key)
                    return true;
                current = current->next;
            }
            return false;
        }
        /*
        *printLinkedList
        * Complejidad O(n); imprime los valores del linked list
        * @param head(Node*) cabeza de la linked list
        */
        void printLinkedList(Node* head){
            if(!head){
                cout<<"NONE"<<endl;
                return;
            }
            Node* current=head;
            while(current){
                cout<<current->data<<" ";
                current=current->next;
            }
            cout<<endl;
            return;
        }
}; 

int main() {
    Set s1, s2, s3, s4;
    // Generar los casos de prueba
    vector<Set> test = {s1, s2, s3, s4};
    vector<vector<int>> testCases ={{22,33,3,4,44,20},{2,24,12,60,5,6},{23,1,36,3,9,99},{22,55,6,7,8,33}};
    for (int i = 0; i<4;i++){
        Set test_i = test[i];
        for(int number: testCases[i]){
            test_i.insert_chainning(number);
            test_i.insert_quadratic(number);
        }
        cout<<"---CASO PRUEBA "<<i+1<<"---\n";
        cout<<"++Chainning++ \n";
        test_i.printSet_chainning();
        cout<<"----------------------\n";
        cout<<"++Quadratic++\n";
        test_i.printQ();
        cout<<"############################\n";
    }
    return 0;
}