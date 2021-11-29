// Actividad 1.2: SearchSort 
// Pablo Agustín Ortega Kral A00344664
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
// binarySearch
// IN: Recibe un vector de enteros(arr) y un valor a buscar(item)
// OUT: Numero entero, correspondiente al indice del valor buscado
// Descripción: aplica la búsqueda binaria para encontrar un índice de un elemento, si lo encuentra 
// regresa sicho número, si no regresa un -1,
// Complejidad:  O(log N), logaritmica
int binarySearch(vector<int> arr, int item){
    int length = arr.size();
    int leftPointer = 0;
    int rightPointer = length-1;
    int middle;
    while (leftPointer<=rightPointer){
        floor(middle =(leftPointer+rightPointer)/2);
        if (item==arr[middle]){
            return middle;
        }
        if (item<arr[middle]){
            rightPointer = middle-1;
        }
        else{
            leftPointer=middle+1;
        }
    }
    return -1;
}
// seqSearch
// IN: Recibe un vector de enteros(arr) y un valor a buscar(item)
// OUT: Numero entero, correspondiente al indice del valor buscado
// Descripción: aplica la búsqueda secuencial para encontrar un índice de un elemento, si lo encuentra 
// regresa sicho número, si no regresa un -1,
// Complejidad:  O(N), lineal

int seqSearch(vector<int> arr, int item){
    int size = arr.size();

    for (int i = 0; i < size; i++){
        if (arr[i]==item){
            return i;
        }
    }
    return -1;   
}
// BubbleSort
// IN: Recibe un vector de enteros(arr)
// OUT: No hay salida
// Descripción: recibe un vector por referencia el cual ordena utilizando el algoritmo de ordenamiento burbuja 
// Complejidad: O(N²), quadrática
void BubbleSort(vector<int>& arr){
    int size = arr.size();
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size-i-1; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }   
    }
}
// InsertionSort
// IN: Recibe un vector de enteros(arr)
// OUT: No hay salida
// Descripción: recibe un vector por referencia el cual ordena utilizando el algoritmo de ordenamiento por inserción 
// Complejidad: O(N²), quadrática
void InsertionSort(vector<int>& arr){
    int size = arr.size();

    for (int i = 1; i < size; i++){
        int key = arr[i];
        int before = i-1;

        while (before>=0 && arr[before]>key){
            arr[before+1]=arr[before];
            before =before-1;
        }
        arr[before+1]=key;
    }
}

// merge
// IN: Recibe un vector de enteros(arr) por referencia, y tres interos
// OUT: No hay salida
// Descripción: toma un vector y crea subarrays, los cuales combina nuevamente en el mismo vector
// Complejidad: O(N), lineal
void merge(vector<int>& arr, int left, int middle, int right){
    int sizearr1 = middle-left+1;
    int sizearr2 = right-middle;
    vector<int> leftarr(sizearr1);
    vector<int> rightarr(sizearr2);

    for (int i = 0; i < sizearr1; i++){
        leftarr[i]=(arr[left + i]);
    }
    for (int j = 0; j < sizearr2; j++){
        rightarr[j]=(arr[middle+1+j]);
    }
    int i  =  0;
    int j =  0;
    int k    = left;
    while (i<sizearr1 && j<sizearr2){
        if (leftarr[i]<= rightarr[j]){
            arr[k] =leftarr[i];
            i++;
        }
        else{
            arr[k]=rightarr[j];
            j++;
        }
        k++;
    }
    while (i<sizearr1){
        arr[k]= leftarr[i];
        i++;
        k++;
    }
    while (j<sizearr2){
        arr[k]= rightarr[j];
        j++;
        k++;
    }
}
// merge
// IN: Recibe un vector de enteros(arr) por referencia, y tres interos
// OUT: No hay salida
// Descripción: algoritmo recursivo que divide el vector tomado por referencia para mandar los subconjuntos 
// creados a merge, donde se ordenan y juntan.
// Complejidad: O(nlog(n)).
void mergeSort(vector<int>& arr, int left, int right){
    int middle;
    if (left<right){
        middle = left + (right-left)/2;
        mergeSort(arr,left, middle);
        mergeSort(arr,middle+1, right);
        merge(arr,left,middle,right);
    }
}
// printarr
// IN: Recibe un vector de enteros(arr)
// OUT: No hay salida
// Descripción: toma un vector y imprime sus elementos a consola.
void printarr(vector<int> arr){
    int size = arr.size();
    for (int i = 0; i < size; i++){
        if (i ==size-1){
            cout<<arr[i]<<endl;
        }
        else{
            cout<<arr[i]<<", ";
        }   
    }
} 
// randomVector
// IN: Recibe un número entero
// OUT: Retorna un vector de enteros
// Descripción: genera un vector de números aleatorios.
vector<int> randomVector(int size){
    vector<int> test(size, 0);
    srand(time(0)+rand()%100);
    generate(test.begin(), test.end(), []() {
    return rand() % 100;});

    return test;
}

int main() {
    vector<int> test;
    vector<int> case1;
    vector<int> case2;
    vector<int> case3;

    cout<<"---Casos Prueba Ordenamiento---"<<endl;
    cout<<endl;
    for (int i = 0; i < 4; i++){
        test = randomVector(6);
        case1 = test;
        case2 = test;
        case3 = test;
        cout<<"**Caso de prueba "<<(i+1)<<"  **  ";
        printarr(test);
        cout<<endl;
        // InsertionSort
        cout<<"Before  "<<endl;
        printarr(case1);
        cout<<endl;
        cout<<"InsertionSort  ";
        InsertionSort(case1);
        printarr(case1);
        cout<<endl;
        // Bubble Sort
        cout<<"Before  "<<endl;
        printarr(case2);
        cout<<endl;
        cout<<"BubbleSort  ";
        BubbleSort(case2);
        printarr(case2);
        cout<<endl;
        // MergeSort
        cout<<"Before  "<<endl;
        printarr(case3);
        cout<<endl;
        cout<<"MergeSort  ";
        mergeSort(case3,0,case3.size()-1);
        printarr(case3);
        cout<<endl;
    }
    cout<<endl<<endl;
    int search;
    int target;
    vector<int> test2 = randomVector(10);
    mergeSort(test2,0,test2.size()-1);
    cout<<"---Casos Prueba Ordenamiento---"<<endl;
    cout<<endl;
    printarr(test2);
    cout<<endl;
    cout<<"Ingreda el número de búsquedas: ";
    cin>>search;
    cout<<endl;
    for (int i = 0; i < search; i++){
        cout<<"     Valor a búscar: ";
        cin>>target;
        cout<<endl;
        cout<<"Sequential Search: "<<seqSearch(test2, target);
        cout<<endl;
        printarr(test2);
        cout<<endl;
        cout<<"Binary Search: "<<seqSearch(test2, target);
        cout<<endl<<endl;
    }
}