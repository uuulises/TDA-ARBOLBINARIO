#include "arbin.h"
#include<iostream>

using namespace std;

int main(){

    //menu para probar todas las funciones sobre el arbol

    Arbin<int> arbol;
    int opcion;
    while (opcion !=0) {

        cout << "ingrese 1 si quiere insertar un elemento en el arbol " << endl;
        cout << "ingrese 2 si quiere saber si un elemento pertenece al arbol " << endl;
        cout << "ingrese 3 si quiere saber la profundidad del arbol " << endl;
        cout << "ingrese 4 si quiere saber si el arbol es vacio " << endl;
        //cout << "ingrese 5 si quiere imprimir el arbol " << endl;
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
        
        // me iba a poner a hacerla pero recorde que vico habia dicho que no iba a funcionar
        //o que simplemente no se podia hacer
        /*if (opcion == 5){
            cout << "el arbol es " << endl;
            arbol.listarelementosordenados();
        }*/

    }

}
