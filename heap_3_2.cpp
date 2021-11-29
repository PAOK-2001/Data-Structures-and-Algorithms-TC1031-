// Actividad 3.2: ArbolHeap
// Fecha: 20/10/2021
// Descripción: forma un priority queue utilizando un 
// binary heap
// Autores:
// Pablo Agustín Ortega Kral A00344664
#include <bits/stdc++.h>
#include <fstream> 
#include <string> 
#include <cmath> 
#include <vector>
using namespace std;
// Clase Priority Queue
template <class T>class priority_queue_custom{
    public:
        vector<pair<T, int>> arrHeap;
        int key;
        // priority_queue_custon
        // Descripción: constructor por default
        priority_queue_custom(){
        }
        // priority_queue_custon
        // Descripción: constructor que define atributos de data y key
        priority_queue_custom(T data, int key){
          arrHeap[0] = make_pair(data, key);
        }
        // padre
        // IN:  Entero (posición actual)
        // OUT: Entero (posición del padre)
        // Descripción: regresa el indice del nodo padre del elemento en la posición
        // especificada
        int padre(int i){
          return (i-1)/2;
        }
        // hijo_izq
        // IN:  Entero (posición actual)
        // OUT: Entero (posición del nodo izquierda)
        // Descripción: regresa el indice del nodo a la izquierda del elemento en la posición
        // especificada
        int hijo_izq(int i){
          return (2*i) + 1;
        }
        // hijo_der
        // IN:  Entero (posición actual)
        // OUT: Entero (posición del nodo derecha)
        // Descripción: regresa el indice del nodo a la derecha del elemento en la posición
        // especificada
        int hijo_der(int i){
          return (2*i) + 2;
        }
        // printArr
        // IN:  N/A
        // OUT: N/A
        // Descripción: imprime el array elemento a elemento por consola
        void printArr(){
          for (int i = 0; i < arrHeap.size(); i++){
            cout<<arrHeap[i].first<<endl;
          }
        }
        // maximum
        // IN:  Entero (posición actual)
        // OUT: Entero (nueva posición del padre)
        // Descripción: regresa la nueva posición del padre
        int maximum(int index){
          int nuevaPosPadre;
          int nuevoPadre = max(arrHeap[hijo_izq(index)].second,arrHeap[hijo_der(index)].second);
          if(nuevoPadre == arrHeap[hijo_izq(index)].second) nuevaPosPadre = hijo_izq(index);
          if(nuevoPadre == arrHeap[hijo_der(index)].second) nuevaPosPadre = hijo_izq(index);
          return nuevaPosPadre;
        }
        // pop_helper
        // IN:  Entero (posición del elemento a eliminar)
        // OUT: N/A
        // Descripción: función recuriva que elimna el elemento especificado
        // Complejidad: O(logN)
        void pop_helper(int index){
          int size = arrHeap.size()-1;
          swap(arrHeap[0], arrHeap[size]);
          if(hijo_izq(index)>size && hijo_der(index)>size){
            arrHeap.erase(arrHeap.begin()+arrHeap.size());
            return;
          }
          if(arrHeap[maximum(index)]>arrHeap[index]){
              swap(arrHeap[index], arrHeap[maximum(index)]);
          }
          pop_helper(maximum(index));
        }
        // pop
        // IN:  N/A
        // OUT: N/A
        // Descripción: llama la función pop_helper sobre la raíz
        // Complejidad: O(logN)
        void pop(){
            pop_helper(0);
        }
        // size
        // IN:  N/A
        // OUT: Entero (tamaño del array)
        // Complejidad: O(1)
        int size(){
          return arrHeap.size();
        }
        // push
        // IN:  N/A
        // OUT: N/A
        // Descripción: agrega el valor a un heap y lo acomda apropiadamente
        // Complejidad: O(logN)
        void push(T data,int key){
          arrHeap.push_back(make_pair(data,key));
          int pos = arrHeap.size()-1;
          while(pos!=0 && arrHeap[pos].second > arrHeap[padre(pos)].second){
            swap(arrHeap[pos], arrHeap[padre(pos)]);
            pos = padre(pos);
          }
        }
        // top
        // IN:  N/A
        // OUT: dato T (primer elemento del heap)
        // Complejidad: O(1)
        T top(){
            return arrHeap[0].first;
        }
        // top
        // IN:  N/A
        // OUT: booleano (falso si está lleno, verdadero si está vacío)
        // Complejidad: O(1)
        bool empty(){
            return arrHeap.size()== 0;
        } 
};

int main(){
    priority_queue_custom<int> Test;
    cout<<"Empty: "<<Test.empty()<<endl;
    Test.push(45,45);
    Test.push(300,300);
    Test.push(150,150);
    Test.push(40,40);
    Test.push(75,75);
    Test.printArr();
    cout<<endl;
    cout<<"Top: "<<Test.top()<<endl;
    cout<<"Size: "<<Test.size()<<endl;
    cout<<"Empty: "<<Test.empty()<<endl;
    Test.pop();
    cout<<endl;
    Test.printArr();

}