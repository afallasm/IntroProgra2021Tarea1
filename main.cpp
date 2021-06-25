#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int size  = 81;
    //Declaracion de los array es cuando se guarda el espacio pero todavia no se ve el valor

    int original[size]; //declaracion del array original
    int copia [size]; //declaracion de array copia
    int indice = 0;
    int numeroElementosEnBloque=0;
    int inicioBloque=0;


    //Inicializacion es cuando se le asigna un valor
    //Inicializacion de los array
    srand(time(0));
    for (int i=0; i<size;i++){
        original[i] = (rand()%2)+1;
        //cout << original [i] << endl;
        //cout << "el numero de indice es " << i << " el valor es " << original[i] << endl;
    }

    //Tabular
    for (int i = 0; i<size ;i++){
        cout << " | " << original[i] << "(" << i << ")";
        if ((i+1)%9 == 0)
            cout << endl;
    }

    //Array copia
    for (int i =0; i <size; i++){
        copia[i] = original[i];
    }

    //Tabulacion del array copia
    cout << "copia"<< endl;
    for (int i=0; i< size; i++){
        cout << " | " << copia[i];
        if ((i+1)%9 == 0)
        cout << endl;
    }

    //Solicitar la entrada posicion al jugador necesito 2 do while
    do{
        numeroElementosEnBloque = 0;
        cout << "Ingrese una posicion entre 1-81" << endl;
        cin >> indice;
        numeroElementosEnBloque =1;

        //evaluar el monto guardado en el indice
        cout << " El valor de la posicion es: " << copia[indice-1] << endl;

        //evaluar si existen valores iguales a la izquierda y a la derecha toda la fila
        //Teoria se debe evaluar la fila completa, ocupo 2 form uno hacia la derecha y otro hacia la izquierda
        //For hacia la izquierda
        for (int i=indice-2; ((i%9)>=0) && ((i%9)<indice); i--){
            //cout <<"Posiciones hacia la izquierda: "<< i << endl;
            //cout <<"Valores de las posiciones hacia la izquierda: " << copia[i]<<endl;

            if (copia[i] != copia[indice-1]){
                break;
            }
            if (copia[i] == copia[indice-1]){
                    cout << "El valor en " << i << " es igual al valor de " << indice-1 << endl;
                    numeroElementosEnBloque = numeroElementosEnBloque + 1;
                    inicioBloque = i;
            }
        }
        cout << "La cantidad de elementos por lo que esta compuesto el bloque es de: " << numeroElementosEnBloque << endl;
        cout << "El indice inicial es: " << inicioBloque << endl;
        if (numeroElementosEnBloque > 2){
            cout << "El bloque debe ser eliminado" << endl;
        }

        //For hacia la derecha
        for (int i = indice;(i%9)<=8 & (i%9)>indice; i++){
            cout <<"Posiciones hacia la derecha: "<< i << endl;
            cout <<"Valores de las posiciones hacia la derecha: " << copia[i]<<endl;
        }

        //En caso que los valores de la izquierda y la derecha sean iguales, los debe considerar como un bloque
        //El bloque se debe eliminar de izquierda a derecha en la matriz

            }while(indice >= 1 && indice <= 81); //El while no debe ser un loop infinito se debe castigar el 0 y otros con la salida
        do{
          cout << "Ingrese una posicion valida" << endl;
          cin >> indice;
        } while (indice <= 0 || indice > 81);

        //Corrimiento


    return 0;
}
