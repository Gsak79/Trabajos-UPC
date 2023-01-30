#ifndef ARBOL_BUSQUEDA_H
#define ARBOL_BUSQUEDA_H

#include <functional>
#include <vector>
using namespace std;

template<typename T, typename R=T>
class Arbol_busqueda{
    struct Nodo {
        T elemento; Nodo* izquierda; Nodo* derecha; int altura;
        Nodo(T elemento): elemento(elemento),izquierda(nullptr),derecha(nullptr),altura(0) {}
    };

    Nodo*   raiz;
    int     cantidad;
    function<R(T)> CompararAtributo;
    function<bool(R, R)> Comparar;

public:
    Arbol_busqueda(function<R(T)> CompararAtributo=[](T a) {return a;}) : CompararAtributo(CompararAtributo), raiz(nullptr), cantidad(0) {}
    ~Arbol_busqueda() { Destruir(raiz); }

    void setComparar(function<bool(R, R)> c){ Comparar = c; };

    int     getAltura()                { return getAltura(raiz); }
    int     getCantidad()                  { return cantidad; }
    void    BorrarArbol()                 { Destruir(raiz); cantidad = 0; }

    void    AgregarElemento(T elemento)             { AgregarElemento(raiz, elemento); }


    T getMayor(){
        Nodo*& nodo = getMayor(raiz);

        return nodo->elemento;
    }

    void EnOrden(function<void(T)> proceso){
        EnOrden(raiz, proceso);
    }

    T BuscarElemento(R atributo) {
        Nodo*& nodo = BuscarElemento(raiz, atributo);

        if(nodo == nullptr){
            return 0;
        }
        else{
            return nodo->elemento;
        }
    }

    T BuscarElementoFiltro(R atributo, function<bool(R, R)> proceso){
        Nodo*& nodo = BuscarElementoFiltro(raiz, atributo, proceso);

        if(nodo == nullptr){
            return 0;
        }
        else{
            T aux = nodo->elemento;
            EliminarElementoFiltro(nodo);
            return aux;
        }
    }

    void EliminarElemento(R atributo){
        Nodo*& nodo = BuscarElemento(raiz, atributo);

        if (nodo == nullptr) return;
        if (nodo->izquierda == nullptr) {
            Nodo* aux = nodo;
            nodo = nodo->derecha;
            delete aux;
        } else {
            Nodo*& cand = getMayor(nodo->izquierda);
            nodo->elemento = cand->elemento;
            Nodo* aux = cand;
            cand = cand->izquierda;
            delete aux;
        }

        cantidad--;
    }
    void EliminarElementoFiltro(Nodo*& NodoEliminar){
        Nodo*& nodo = NodoEliminar;

        if (nodo == nullptr) return;
        if (nodo->izquierda == nullptr) {
            Nodo* aux = nodo;
            nodo = nodo->derecha;
            delete aux;
        } else {
            Nodo*& cand = getMayor(nodo->izquierda);
            nodo->elemento = cand->elemento;
            Nodo* aux = cand;
            cand = cand->izquierda;
            delete aux;
        }
        cantidad--;
    }
private:
    void Destruir(Nodo*& nodo) {
        if (nodo != nullptr) {
            Destruir(nodo->izquierda);
            Destruir(nodo->derecha);
            delete nodo;
            nodo = nullptr;
        }
    }
    int getAltura(Nodo* nodo) {
        if(nodo == nullptr){
            return -1;
        }
        else{
            return nodo->altura;
        }
    }
    void AgregarElemento(Nodo*& nodo, T elemento) {
        if (nodo == nullptr) {
            nodo = new Nodo(elemento);
            cantidad++;
        }
        else {
            if (CompararAtributo(elemento) < CompararAtributo(nodo->elemento)) {
                AgregarElemento(nodo->izquierda, elemento);
            }
            else {
                AgregarElemento(nodo->derecha, elemento);
            }
            balancear(nodo);
        }
    }

    void EliminarNodo(Nodo*& nodo){
        if (nodo == nullptr) return;
        if (nodo->izquierda == nullptr) {
            Nodo* aux = nodo;
            nodo = nodo->derecha;
            delete aux;
        }
        else {
            Nodo*& cand = getMayor(nodo->izquierda);
            nodo->elemento = cand->elemento;
            Nodo* aux = cand;
            cand = cand->izquierda;
            delete aux;
        }
        cantidad--;

    }

    Nodo*& getMayor(Nodo*& nodo) {
        if(nodo->derecha == nullptr){
            return nodo;
        }
        else {
            return getMayor(nodo->derecha);
        }
    }
    Nodo*& BuscarElemento(Nodo*& nodo, R atributo) {
        if (nodo == nullptr) {
            return dummynull;
        }
        else if (CompararAtributo(nodo->elemento) == atributo) {
            return nodo;
        }
        else if (atributo < CompararAtributo(nodo->elemento)) {
            return BuscarElemento(nodo->izquierda, atributo);
        }
        else {
            return BuscarElemento(nodo->derecha, atributo);
        }
    }

    Nodo*& BuscarElementoFiltro(Nodo*& nodo, R atributo, function<bool(R, R)> proceso) {
        if (nodo == nullptr) {
            return dummynull;
        }
        else if (proceso(CompararAtributo(nodo->elemento), atributo)) {
            return nodo;
        }
        else if (atributo < CompararAtributo(nodo->elemento)) {
            return BuscarElementoFiltro(nodo->izquierda, atributo, proceso);
        }
        else {
            return BuscarElementoFiltro(nodo->derecha, atributo, proceso);
        }
    }

    void BuscarElementos(Nodo*& nodo, R atributo, function<void(T)>AgregarVector, function<bool(string, string)> proceso) {
        if(nodo != nullptr){
            if(proceso(CompararAtributo(nodo->elemento), atributo)){
                BuscarElementos(nodo->izquierda, atributo, AgregarVector, proceso);
                AgregarVector(nodo->elemento);
                BuscarElementos(nodo->derecha, atributo, AgregarVector, proceso);
            }
        }
    }

    void ActualizarAltura(Nodo* nodo) {
        if (nodo != nullptr) {
            nodo->altura = max(getAltura(nodo->izquierda), getAltura(nodo->derecha)) + 1;
        }
    }
    void RotarIzquierda(Nodo*& nodo) {
        Nodo* aux = nodo->derecha;
        nodo->derecha = aux->izquierda;
        ActualizarAltura(nodo);
        aux->izquierda = nodo;
        ActualizarAltura(aux);
        nodo = aux;
    }
    void RotarDerecha(Nodo*& nodo) {
        Nodo* aux = nodo->izquierda;
        nodo->izquierda = aux->derecha;
        ActualizarAltura(nodo);
        aux->derecha = nodo;
        ActualizarAltura(aux);
        nodo = aux;
    }
    void balancear(Nodo*& nodo) {
        int AlturaIzquierda = getAltura(nodo->izquierda);
        int AlturaDerecha = getAltura(nodo->derecha);

        if (AlturaDerecha - AlturaIzquierda < -1) {
            AlturaIzquierda = getAltura(nodo->izquierda->izquierda);
            AlturaDerecha = getAltura(nodo->izquierda->derecha);
            if (AlturaDerecha > AlturaIzquierda) {
                RotarIzquierda(nodo->izquierda);
            }
            RotarDerecha(nodo);
        }
        else if (AlturaDerecha - AlturaIzquierda > 1) {
            AlturaIzquierda = getAltura(nodo->derecha->izquierda);
            AlturaDerecha = getAltura(nodo->derecha->derecha);
            if (AlturaIzquierda > AlturaDerecha) {
                RotarDerecha(nodo->derecha);
            }
            RotarIzquierda(nodo);
        }
        else {
            ActualizarAltura(nodo);
        }
    }

    void EnOrden(Nodo* nodo, function<void(T)> proceso) {
        if (nodo != nullptr) {

            EnOrden(nodo->izquierda, proceso);
            proceso(nodo->elemento);
            EnOrden(nodo->derecha, proceso);
        }
    }

    Nodo* dummynull = nullptr;


};

#endif // ARBOL_BUSQUEDA_H
