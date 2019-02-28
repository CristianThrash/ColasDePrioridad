#include <cstdlib>
#include <iostream>
#include "colapriori.h"

using namespace std;

int main(int argc, char *argv[])
{
    char t;
    ColaDePrioridad<char> colaP;
    colaP.insertar('A',90);
    colaP.insertar('B',95);
    colaP.insertar('C',60);
    colaP.insertar('D',30);
    colaP.insertar('E',75);
    colaP.insertar('F',50);
    
    /*Los recorridos se muestran con las prioridades y no con la info para 
    prevenir errores con el operador ya que la info es de un tipo genérico T*/
    cout<<"Preorden: ";
    colaP.preorden(colaP.raizArbol());
    cout<<endl;
    cout<<"Inorden: ";
    colaP.inorden(colaP.raizArbol());
    cout<<endl;
    cout<<"Postorden: ";
    colaP.posorden(colaP.raizArbol());
    cout<<endl;
    
    t = colaP.atender();
    cout<<"Atendido: "<<t<<endl;
    t = colaP.atender();
    cout<<"Atendido: "<<t<<endl;
    t = colaP.atender();
    cout<<"Atendido: "<<t<<endl;
    
    
    cout<<"Preorden: ";
    colaP.preorden(colaP.raizArbol());
    cout<<endl;
    cout<<"Inorden: ";
    colaP.inorden(colaP.raizArbol());
    cout<<endl;
    cout<<"Postorden: ";
    colaP.posorden(colaP.raizArbol());
    cout<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
