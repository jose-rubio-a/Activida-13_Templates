#ifndef ARREGLODINAMICO_H
#define ARREGLODINAMICO_H

#include <iostream>
using namespace std;

template <class T>
class ArregloDinamico
{
private:
    T *arreglo;
    size_t tam;
    size_t cont;
    const static size_t MAX = 5;

    void expandir();
public:
    ArregloDinamico();
    ~ArregloDinamico();
    void insertar_inicio(const T& v);
    void insertar_final(const T& v);
    void insertar(const T& v, size_t pos);
    
    void eliminar_final();
    void eliminar_inicio();
    void eliminar(size_t pos);

    void mostrar();
    size_t size();
    T operator[] (size_t p){
        return arreglo[p];
    }

};

template <class T>
ArregloDinamico<T>::ArregloDinamico(){
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}

template <class T>
ArregloDinamico<T>::~ArregloDinamico(){
    delete[] arreglo;
}

template <class T>
void ArregloDinamico<T>::insertar_final(const T& v){
    if(cont == tam){
        expandir();
    }
    arreglo[cont++] = v;
}

template <class T>
void ArregloDinamico<T>::insertar_inicio(const T& v){
    if(cont == tam){
        expandir();
    }
    for(size_t i = cont; i > 0;i--){
        arreglo[i] = arreglo[i-1];
    }
    arreglo[0] = v;
    cont++;
}

template <class T>
void ArregloDinamico<T>::insertar(const T& v, size_t pos){
    if (pos >= cont) {
        cout << "Posicion no valida" << endl;
        return;
    }
    if(cont == tam){
        expandir();
    }
    for(size_t i = cont; i > pos; i--){
        arreglo[i] = arreglo[i-1];
    }
    arreglo[pos] = v;
    cont++;
}

template <class T>
void ArregloDinamico<T>::eliminar_final(){
    if(cont == 0){
        cout << "El arreglo esta vacio" << endl;
        return;
    }
    cont--;
}

template <class T>
void ArregloDinamico<T>::eliminar_inicio(){
    if(cont == 0){
        cout << "El arreglo esta vacio" << endl;
        return;
    }
    for(size_t i = 0; i < cont-1; i++){
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}

template <class T>
void ArregloDinamico<T>::eliminar(size_t pos){
    if(cont == 0){
        cout << "El arreglo esta vacio" << endl;
        return;
    }
    for(size_t i = pos; i < cont-1; i++){
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}

template <class T>
size_t ArregloDinamico<T>::size(){
    return cont;
}

template <class T>
void ArregloDinamico<T>::expandir(){
    T *nuevo = new T[tam+MAX];

    for(size_t i = 0; i < cont; i++){
        nuevo[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = nuevo;
    tam += MAX;
}

template <class T>
void ArregloDinamico<T>::mostrar(){
    cout << "Arreglo Dinamico: " << endl;
    for(size_t i = 0; i < cont; i++){
        cout << arreglo[i] << endl;
    }
    cout << endl;
}

#endif