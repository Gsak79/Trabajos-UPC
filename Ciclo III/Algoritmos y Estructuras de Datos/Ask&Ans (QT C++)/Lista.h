#ifndef LISTA_H
#define LISTA_H

template <typename T>
class Lista
{
private:
    struct Nodo
    {
         T elemento;
         Nodo* next;
         Nodo(T elemento, Nodo* next = nullptr): elemento(elemento), next(next){}
    };

    Nodo* head;
    long cantidad;
public:
    Lista() : head(nullptr), cantidad(0){}
    ~Lista(){}

    long getCantidad();

    void AnadirComienzo(T elemento);
    void AnadirPosicion(T elemento, long pos);
    void AnadirFinal(T elemento);

    T getComienzo();
    T getPosicion(int pos);
    T getFinal();

    bool BuscarElemento(T elemento);

    void EliminarPrimero();
    void EliminarLista();
    void EliminarPorValor(T elemento);

    bool EsVacio();

};


template <typename T>
long Lista<T>::getCantidad(){
    return cantidad;
}

template<typename T>
bool Lista<T>::EsVacio(){
    if(cantidad == 0) return true;
    else return false;
}

template <typename T>
void Lista<T>::AnadirComienzo(T elemento){
    head = new Nodo(elemento, head);
    cantidad++;
}

template <typename T>
void Lista<T>::AnadirPosicion(T elemento, long pos){
    if(pos < 0 || pos > cantidad){
        return;
    }
    else if(pos == 0){
        AnadirComienzo(elemento);
    }
    else{
        Nodo* aux = head;
        for(long i = 1; i < pos; i++){
            aux = aux->next;
        }
        aux->next = new Nodo(elemento, aux->next);
        cantidad++;
    }
}

template<typename T>
void Lista<T>::AnadirFinal(T elemento){
    AnadirPosicion(elemento, cantidad);
}

template<typename T>
T Lista<T>::getComienzo(){
    return head->elemento;
}

template<typename T>
T Lista<T>::getPosicion(int pos){
    if(pos < 0 || pos >= cantidad) return 0;
    Nodo* aux = head;
    for(long i = 0; i < pos; i++){
        aux = aux->next;
    }
    return aux->elemento;
}

template<typename T>
T Lista<T>::getFinal(){
    return getPosicion(cantidad - 1);
}

template<typename T>
void Lista<T>::EliminarPorValor(T valor){
    Nodo* aux = head;
    Nodo* anterior = nullptr;
    while(aux->elemento != valor){
        anterior = aux;
        aux = aux->next;
    }
    if(anterior == nullptr){
        head = head->next;
        delete aux;
    }
    else{
        anterior->next = aux->next;
        delete aux;
    }
    cantidad--;
}

template<typename T>
bool Lista<T>::BuscarElemento(T elemento){
    Nodo* aux = head;
        for (int i = 0; i < cantidad; ++i) {
            if (aux->elemento == elemento) {
                return true;
            }
            aux = aux->next;
        }
        return false;
}

template<typename T>
void Lista<T>::EliminarLista(){
   while(cantidad > 0){
       EliminarPrimero();
   }
}

template<typename T>
void Lista<T>::EliminarPrimero(){
    if (cantidad > 0) {
           Nodo* aux = head;
           head = head->next;
           delete aux;
           --cantidad;
     }
}

#endif // LISTA_H
