// queue::push/pop
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, list<Cumpleanios*>cumpleanios)
{
    //Abre el archivo de forma binaria en un modo escritura
    ofstream out(nombre_archivo.c_str());
    //Ciclo que recorre la lista con un iterador
    for(list<Cumpleanios*>::iterator i=cumpleanios.begin();i!=cumpleanios.end();i++){
        //Esctitura de los datos en el archivo
        out<<(*i)->cumpleaniero
        <<" "
        <<(*i)->mes
        <<" "
        <<(*i)->dia
        <<" ";
    }
    //cierre del archivo
    out.close();
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
list<Cumpleanios*> leer(string nombre_archivo)
{
    list<Cumpleanios*>cumpleanios;
    //Abre el archivo en un modo lectura
    ifstream in(nombre_archivo.c_str());
    //declaracion de variables donde se va a almacenar los registros del archivo
    string cumpleaniero;
    int mes;
    int dia;
    //ciclo de lectura del archivo enseñado en clase
    while(in>>cumpleaniero){
        in>>mes;
        in>>dia;
        //Insercion de un cumpleañero en la lista de cumpleañeros
        cumpleanios.push_back(new Cumpleanios(cumpleaniero,dia,mes));
    }
    return cumpleanios;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
