#include "arbin.h"
#include<iostream>
#include "Lista.h"

using namespace std;

int main(){

    //menu para probar todas las funciones sobre el arbol

    Arbin<int> arbol;
    int opcion= 2101;
    while (opcion !=0) {

        cout << "ingrese 1 si quiere insertar un elemento en el arbol " << endl;
        cout << "ingrese 2 si quiere saber si un elemento pertenece al arbol " << endl;
        cout << "ingrese 3 si quiere saber la profundidad del arbol " << endl;
        cout << "ingrese 4 si quiere saber si el arbol es vacio " << endl;
        cout << "ingrese 5 si quiere crear y mostrar una lista ordenada de menor a mayor " << endl;
        cout << "ingrese 6 si quiere crear y mostrar una lista de las hojas del arbol " << endl;
        cout << "ingrese 0 si quiere salir " << endl;
        cin >> opcion;

        if (opcion == 1) {
            int elemento;
            cout << "ingrese el elemento que quiere insertar en el arbol " << endl;
            cin >> elemento;
            arbol.insertar(elemento);
        }

        if (opcion == 2) {
            int elemento;
            cout << "ingrese el elemento que quiere saber si pertenece al arbol " << endl;
            cin >> elemento;
            if (arbol.pertence(elemento))
                cout << "el elemento pertenece al arbol " << endl;
            else
                cout << "el elemento no pertenece al arbol " << endl;
        }

        if (opcion == 3) {
            cout << "la profundidad del arbol es " << arbol.profundidad() << endl;
        }

        if (opcion == 4){
            if (arbol.esvacio())
                cout << "el arbol es vacio " << endl;
            else
                cout << "el arbol no es vacio " << endl;
        }

        if (opcion == 5){
            Lista<int> lis= arbol.listarordenado();
            cout << "Lista en orden menor a mayor: " << endl;
            int k=1;
            while(k<=lis.cantElementos()){
                cout << lis.obtenerElemento(k) << endl;
                k++;
            }
        }

        if(opcion == 6){
            Lista<int> fronterinha=arbol.frontera();
            cout << "Lista de las hojas: " << endl;
            int j=1;
            while(j<=fronterinha.cantElementos()){
                cout << fronterinha.obtenerElemento(j) << endl;
                j++;
            }

        }

    }

}
