#include <iostream>
#include "arregloDinamico.h"
using namespace std;

int main(){
    ArregloDinamico<string> arreglo;
    // agregar 4 string's a arreglo usando insertar_final e insersar_inicio()
    arreglo.insertar_final("Comentario #4");
    arreglo.insertar_inicio("Comentario #2");
    arreglo.insertar_final("Comentario #5");
    arreglo.insertar_inicio("Comentario #1");
    // mostrar() los elementos de arreglo
    arreglo.mostrar();
    // insertar() el elemento en la posición 2
    arreglo.insertar("Comentario #3",2);
    // mostrar los elementos de arreglo
    arreglo.mostrar();
    // eliminar_inicio() y eliminar_final()
    arreglo.eliminar_inicio();
    arreglo.eliminar_final();
    // eliminar() el elemento de la posición 1
    arreglo.eliminar(1);
    // mostrar() los elementos de arreglo
    arreglo.mostrar();
    return 0;
}