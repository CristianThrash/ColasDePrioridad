#include "cola.h"

#ifndef COLAPRIORI_H
#define COLAPRIORI_H

template <class T>
struct NODO{
    T info;
    int prioridad;
    NODO<T> *padre;
    NODO<T> *izq;
    NODO<T> *der;
};

template <class T>
class ColaDePrioridad{
    NODO <T> *raiz;
    
    public:
    
    ColaDePrioridad(){
        raiz = NULL;
    }
    
    NODO<T> *raizArbol(){
        return raiz;
    }
    void insertar(T info, int prioridad);
    T atender();
    void *inorden(NODO<T> *nod);
    void *preorden(NODO<T> *nod);
    void *posorden(NODO<T> *nod);
};

template <class T>
void ColaDePrioridad<T>::insertar(T info, int prioridad){
    NODO<T> *nuevo =  new NODO<T>;
    nuevo -> padre = NULL;
    nuevo -> izq = NULL;
    nuevo -> der = NULL;
    
    if(raiz == NULL){
        nuevo -> info = info;
        nuevo -> prioridad = prioridad;
        raiz = nuevo;
    }else{
        
        cola<NODO<T>*> colaAux;
        NODO<T> *aux;
        colaAux.insCola(raiz);
        
        while(nuevo -> padre == NULL){
            aux = colaAux.atenderCola();

            if(aux -> izq != NULL && aux -> der != NULL){
                colaAux.insCola(aux -> izq);
                colaAux.insCola(aux -> der);
            }else if(aux -> izq != NULL){
                aux -> der = nuevo;
                nuevo -> padre = aux;
            }else{
                aux -> izq = nuevo;
                nuevo -> padre = aux;
            }
        }
        
        while(aux != NULL && aux -> prioridad < prioridad){
            nuevo -> info = aux -> info;
            nuevo -> prioridad = aux -> prioridad;
            nuevo = aux;
            aux = aux -> padre;
        }
        
        nuevo -> info = info;
        nuevo -> prioridad = prioridad;
    }
}

template <class T>
T ColaDePrioridad<T>::atender(){
    NODO<T> *aux, *aux2;                  
    cola<NODO<T>*> colaAux;
    T auxInfo, retorno;
    int auxPriori;
    
    colaAux.insCola(raiz);
    while(!colaAux.colaVacia()){
        aux = colaAux.atenderCola();
        if(aux -> izq != NULL)
            colaAux.insCola(aux -> izq);
        if(aux -> der != NULL)
            colaAux.insCola(aux -> der);
    }
    
    if(aux == raiz){
        retorno = aux -> info;
        delete aux;
        raiz = NULL;
        return retorno;
    }
    
    auxInfo = aux -> info;
    auxPriori = aux -> prioridad;
    aux2 = aux -> padre;
    if(aux2->izq == aux)
        aux2->izq = NULL;
    else
        aux2->der = NULL;
    delete aux;
    
    retorno = raiz -> info;
    
    aux = raiz;
    
    while(aux!=NULL){
        if(aux -> der != NULL){
            if(aux->der->prioridad > aux->izq->prioridad && aux->der->prioridad > auxPriori){
                aux->info = aux->der->info;
                aux->prioridad = aux->der->prioridad;
                aux = aux->der;
            }else if(aux->izq->prioridad > aux->der->prioridad && aux->izq->prioridad > auxPriori){
                aux->info = aux->izq->info;
                aux->prioridad = aux->izq->prioridad;
                aux = aux->izq;
            }else{
                aux->info = auxInfo;
                aux->prioridad = auxPriori;
                aux = NULL;
            }      
        }else if(aux -> izq != NULL){
            if(aux->izq->prioridad > auxPriori){
                aux->info = aux->izq->info;
                aux->prioridad = aux->izq->prioridad;
                aux = aux->izq;
            }else{
                aux->info = auxInfo;
                aux->prioridad = auxPriori;
                aux = NULL;
            } 
        }else{
            aux->info = auxInfo;
            aux->prioridad = auxPriori;
            aux = NULL;
        }
    }
    
    return retorno;
}

template <class T>
void *ColaDePrioridad<T>::inorden(NODO<T> *nod){
	if(nod!=NULL){
		inorden(nod -> izq);
		cout << nod -> prioridad<<" ";
		inorden(nod -> der);
	}
}

template <class T>
void *ColaDePrioridad<T>::preorden(NODO<T> *nod){
	if(nod!=NULL){
        cout << nod -> prioridad<<" ";
		preorden(nod -> izq);
		preorden(nod -> der);
	}
}

template <class T>
void *ColaDePrioridad<T>::posorden(NODO<T> *nod){
	if(nod!=NULL){
		posorden(nod -> izq);
		posorden(nod -> der);
		cout << nod -> prioridad<<" ";
	}
}

#endif
