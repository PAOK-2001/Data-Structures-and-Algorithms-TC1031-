/*
appGraph
Programa que permite crear un grafo y terminar si este es un árbol o no, es decir si tiene ciclos
Autor: Pablo Agustín Ortega Kral A00344664
*/
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        vector<int> nodes;
        int edges;
        map<int,bool> visited;
        map<int,bool> recursive;
        map<int, vector<int>> adjList;
        // Constructor default
        Graph(){

        }
        /* 
        * addEdge
        * Agrega un elemento a la lista de adyacencia
        * Complejidad: O(1)
        * @param v1 primer vertice
        * @param v2 vertice con el que se hace conexión
        * @return No hay salida
        */
        void addEdge(int v1, int v2){
            adjList[v1].push_back(v2);
        }
        /*
        * isCyclicUtil
        * Complejidad O(N), depende del número de vértices y aristas
        * Traviesa al grapho utilizando Depth First Search
        */
        bool dfs(int start){
            if(recursive[start]){
                return true;
            }
            if(visited[start]){
                return false;
            }
            visited[start] = true;
            recursive[start] = true;

            vector<int> list = adjList[start];

            for(int element : list){
                if(dfs(element)){
                    return true;
                }
            }
            recursive[start] = false;
            return false;
        }
        /*
        * isTree
        * Complejidad: O(N)
        * @returns True si grafo no es cilclo; False si el grafo es cyclico
        */
        bool isTree(){
            for (auto const& x : adjList){
                if(dfs(x.first)){
                    return false;
                }
            }
            return true;
        
        }
};
/*
* loadGraph
* Complejidad O(n)
* @param v número de vertices
* @param e número de aristas
* @param g objeto grafos por referencia
* Carga los valores a la lista de adyacencia
*/
void loadGraph(int v, int e, Graph& g){
    g.edges = e;
    for (int i = 0; i < v; i++){
        int node;
        cout<<"+Crea un nodo: ";
        cin>>node;
        g.nodes.push_back(node);
    }
    int to, from;
    cout<<"-- Crea las conexiones -- \n";
    for (int i = 0; i < e; i++){
        cout<<"+Nodo origen: ";
        cin>> to;
        cout<<"+Nodo destino: ";
        cin>> from;
        if(find(g.nodes.begin(),g.nodes.end(),to)==g.nodes.end()||find(g.nodes.begin(),g.nodes.end(),from)==g.nodes.end()){
            cout<<"##Invalid node\n";
            exit(-1);
        }
        g.addEdge(to, from);
    }
    
}
int main(){
    Graph g1;
    Graph g2;
    Graph g3;
    Graph g4;
    /*
    Output de consola
    ---- Caso de prueba 1 ----
    +Crea un nodo: 0
    +Crea un nodo: 1
    +Crea un nodo: 2
    +Crea un nodo: 3
    -- Crea las conexiones -- 
    +Nodo origen: 3
    +Nodo destino: 0
    +Nodo origen: 0
    +Nodo destino: 1
    +Nodo origen: 1
    +Nodo destino: 2
    +Nodo origen: 2
    +Nodo destino: 0

    El grapho es ciclico
    */
    cout<<"---- Caso de prueba 1 ----\n";
    loadGraph(4,4,g1);
    if(g1.isTree()){
        cout<<"El grapho no es ciclico\n";
    }else{
        cout<<"El grapho es ciclico\n";
    }
     /*
    Output de consola
    ---- Caso de prueba 2 ----
    +Crea un nodo: 0
    +Crea un nodo: 1
    +Crea un nodo: 2
    +Crea un nodo: 3
    -- Crea las conexiones -- 
    +Nodo origen: 0
    +Nodo destino: 1
    +Nodo origen: 1
    +Nodo destino: 2
    +Nodo origen: 1
    +Nodo destino: 3
    El grapho no es ciclico
    */
    cout<<"---- Caso de prueba 2 ----\n";
    loadGraph(4,3,g2);
    if(g2.isTree()){
        cout<<"El grapho no es ciclico\n";
    }else{
        cout<<"El grapho es ciclico\n";
    }
     /*
    Output de consola
    ---- Caso de prueba 3 ----
    +Crea un nodo: 0
    +Crea un nodo: 1
    +Crea un nodo: 2
    +Crea un nodo: 3
    -- Crea las conexiones -- 
    +Nodo origen: 2
    +Nodo destino: 0
    +Nodo origen: 0
    +Nodo destino: 0
    +Nodo origen: 0
    +Nodo destino: 1
    +Nodo origen: 1
    +Nodo destino: 3
    +Nodo origen: 3
    +Nodo destino: 2
    El grapho es ciclico
    */ 
    cout<<"---- Caso de prueba 3 ----\n";
    loadGraph(4,5,g3);
    if(g3.isTree()){
        cout<<"El grapho no es ciclico\n";
    }else{
        cout<<"El grapho es ciclico\n";
    }
     /*
    Output de consola
    ---- Caso de prueba 3 ----
    +Crea un nodo: 0
    +Crea un nodo: 1
    +Crea un nodo: 2
    +Crea un nodo: 3
    -- Crea las conexiones -- 
    +Nodo origen: 2
    +Nodo destino: 3
    +Nodo origen: 3
    +Nodo destino: 1
    +Nodo origen: 1
    +Nodo destino: 0
    El grapho no es ciclico
    */
    cout<<"---- Caso de prueba 4 ----\n";
    loadGraph(4,3,g4);
    if(g4.isTree()){
        cout<<"El grapho no es ciclico\n";
    }else{
        cout<<"El grapho es ciclico\n";
    }

    return 0;

}