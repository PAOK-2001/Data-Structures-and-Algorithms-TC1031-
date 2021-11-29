// El presente programa define 3 metodos (iterativo, recursivo y directo) para realizar una sumatoria de 1 hasta 1, con el fin de comparar su complejidad
// Autor: Pablo Agustín Ortega-Kral
// Matrícula: A00344664
// Fecha: 19/08/2021
#include <iostream>
using namespace std;

// Esta funcion toma como argumento un entero n, y utiliza un ciclo for para iterar y realizar una sumatoria de 1 a n.
// Tiene como salida un númmero entero correspondiente a la suma calculada
int sumaIterativa(int n){
    // Complejidad: Lineal O(n)
    // Tiene un big O de n, pues se trata de un solo ciclo for, por lo que el número de pasos se puede visualizar como la sumataria base 1 de 1 a n.
    int suma=0;
    for (int i = 1; i <= n; i++){
        suma=suma+i;
    }
    return suma;
}

// Esta funcion toma como argumento un entero n, y utiliza recursividad para realizar una sumatoria de 1 a n.
// Tiene como salida un númmero entero correspondiente a la suma calculada
int sumaRecursiva(int n){
    // Complejidad: Lineal O(n)
    // Tiene un big O de n, pues el algortimo se aplica n veces.

    if (n==0){ //Si n = 0 el programa ha recorrido n iteraciones, por lo que se termina de ejecutar el algoritmo
        return 0;
    }
    else{
        return sumaRecursiva(n-1)+n;
    }

}

// Esta funcion toma como argumento un entero n, y utiliza la formula correspondiente a una sumatoria matemática para realizar una sumatoria de 1 a n.
// Tiene como salida un númmero entero correspondiente a la suma calculada
int sumaDirecta(int n){
    // Complejidad: Constante O(1)
    // Al solo realizar una operación para evaluar la sumatoria, sin importar el valor de n, siempre se tendrá una complejidad de 1.
    return n*(n+1)/2;
}

int main(){
    // Caso de prueba 1 =5
    cout<<"Suma Iterativa: ";
    cout<<sumaIterativa(5)<<endl;
    cout<<"Suma Recursiva: ";
    cout<<sumaRecursiva(5)<<endl;
    cout<<"Suma Directa: ";
    cout<<sumaDirecta(5)<<endl;
    cout<<endl;
    // Caso de prueba 2 = 10
    cout<<"Suma Iterativa: ";
    cout<<sumaIterativa(10)<<endl;
    cout<<"Suma Recursiva: ";
    cout<<sumaRecursiva(10)<<endl;
    cout<<"Suma Directa: ";
    cout<<sumaDirecta(10)<<endl;
    cout<<endl;
    // Caso de prueba 3 = 25
    cout<<"Suma Iterativa: ";
    cout<<sumaIterativa(25)<<endl;
    cout<<"Suma Recursiva: ";
    cout<<sumaRecursiva(25)<<endl;
    cout<<"Suma Directa: ";
    cout<<sumaDirecta(25)<<endl;
    cout<<endl;
    // Caso de prueba 4 = 45
    cout<<"Suma Iterativa: ";
    cout<<sumaIterativa(45)<<endl;
    cout<<"Suma Recursiva: ";
    cout<<sumaRecursiva(45)<<endl;
    cout<<"Suma Directa: ";
    cout<<sumaDirecta(45)<<endl;
    cout<<endl;

}