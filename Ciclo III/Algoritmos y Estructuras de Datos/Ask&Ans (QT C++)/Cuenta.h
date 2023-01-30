#ifndef CUENTA_H
#define CUENTA_H

#include <string>
#include <Publicacion.h>
#include <Lista.h>
#include <Arbol_busqueda.h>

using namespace std;

class Cuenta{
    int id;
    string nombre;
    string email;
    string FechaDeCreacion;
    vector<Publicacion*> publicaciones;
    Arbol_busqueda<Publicacion*, string>* publicaciones_recientes;
    Arbol_busqueda<Publicacion*, int>* publicaciones_likes;
    Arbol_busqueda<Publicacion*, int>* arbol_recomendados;
    Arbol_busqueda<int>* arbol_seguidos;
    Arbol_busqueda<int>* arbol_seguidores;
    Lista<Publicacion*>* lista_publicaciones;

    function<string(Publicacion*)> comparar_fechaPublicacion = [](Publicacion* publicacion) { return publicacion->getFechaPublicacion(); };
    function<int(Publicacion*)> comparar_likes = [](Publicacion* publicacion) { return publicacion->getLikes(); };
    function<int(Publicacion*)> comparar_id_publicacion = [](Publicacion* publicacion) { return publicacion->getId(); };

public:

    Cuenta() {
        publicaciones_recientes = new Arbol_busqueda<Publicacion*, string>(comparar_fechaPublicacion);
        publicaciones_likes = new Arbol_busqueda<Publicacion*, int>(comparar_likes);
        arbol_recomendados = new Arbol_busqueda<Publicacion*, int>(comparar_id_publicacion);
        arbol_seguidores = new Arbol_busqueda<int>;
        arbol_seguidos =  new Arbol_busqueda<int>;
        lista_publicaciones = new Lista<Publicacion*>;
    }
    ~Cuenta(){}

    void setId(int i) { id = i; }
    void setNombre(string n) { nombre = n; }
    void setEmail (string e) {email = e; }
    void setFechaDeCreacion(string f) { FechaDeCreacion = f; }

    void BorrarArbolRecomendados(){
        arbol_recomendados->BorrarArbol();
    }

    void AgregarPublicaciones(Publicacion* p){
        publicaciones.push_back(p);
        publicaciones_recientes->AgregarElemento(p);

    }

    void AgregarPublicacionesLike(Publicacion* p){
        publicaciones_likes->AgregarElemento(p);
    }

    int getCantidadSeguidores(){
        return arbol_seguidores->getCantidad();
    }
    int getCantidadSeguidos(){
        return arbol_seguidos->getCantidad();
    }

    vector<int> getSeguidores(){
        vector<int> seguidores;

        function<void(int)> AgregarVector = [&](int id){ seguidores.push_back(id); };

        arbol_seguidores->EnOrden(AgregarVector);

        return seguidores;
    }
    vector<int> getSeguidos(){
        vector<int> seguidos;

        function<void(int)> AgregarVector = [&](int id){ seguidos.push_back(id); };

        arbol_seguidos->EnOrden(AgregarVector);

        return seguidos;
    }

    void AgregarSeguidores(int c){
        arbol_seguidores->AgregarElemento(c);
    }
    void AgregarSeguidos(int c){
        arbol_seguidos->AgregarElemento(c);
    }
    void AgregarRecomendados(Publicacion* p){
        arbol_recomendados->AgregarElemento(p);
    }
    bool BuscarRecomendados(int id){
        if(arbol_recomendados->BuscarElemento(id) == 0) return false;
        else return true;
    }

    void EliminarSeguidos(Cuenta* c){
        arbol_seguidos->EliminarElemento(c->getId());
    }

    void EliminarSeguidor(Cuenta* c){
       arbol_seguidores->EliminarElemento(c->getId());
    }

    void EliminarRecomendados(Publicacion* p){
        arbol_recomendados->EliminarElemento(p->getId());
    }

    bool BuscarCuentaId(int id){
        if(arbol_seguidos->BuscarElemento(id) == 0) return false;
        else return true;
    }

    vector<Publicacion*> getPublicacionesRecientes() {
        vector<Publicacion*> p;

        function<void(Publicacion* pub)> AgregarVector = [&](Publicacion* pub) { p.push_back(pub); };

        publicaciones_recientes->EnOrden(AgregarVector);

        return p;
    }

    vector<Publicacion*> getPublicacionesRelevantes(){
        OrdenamientoMerge(publicaciones);
        return publicaciones;
    }

    vector<Publicacion*> getPublicacionesLikes() {
        vector<Publicacion*> p;

        function<void(Publicacion* pub)> AgregarVector = [&](Publicacion* pub) { p.push_back(pub); };

        publicaciones_likes->EnOrden(AgregarVector);

        return p;
    }

    int getId() {return id; }
    string getNombre(){ return nombre; }
    string getEmail() { return email; }
    string getFechaDeCreacion() { return FechaDeCreacion; }

private:

    void Mezclar(vector<Publicacion*>& arreglo, long inicio, long final) {
        vector<Publicacion*> aux;
        long mitad = (inicio + final) / 2;
        long IndiceIzquierda = inicio;
        long IndiceDerecha = mitad + 1;

        for (long i = inicio; i <= final; i++) {
            if (IndiceDerecha <= final) {
                if (IndiceIzquierda >= mitad + 1 || arreglo[IndiceIzquierda]->getTotalInteracciones() > arreglo[IndiceDerecha]->getTotalInteracciones()) {

                    aux.push_back(arreglo[IndiceDerecha]);
                    IndiceDerecha++;
                }
                else {
                    aux.push_back(arreglo[IndiceIzquierda]);
                    IndiceIzquierda++;
                }
            }
            else {
                aux.push_back(arreglo[IndiceIzquierda]);
                IndiceIzquierda++;
            }
        }
        for (long i = 0; i < (long)aux.size(); i++) {
            arreglo[inicio + i] = aux[i];
        }
    }

    void Dividir(vector<Publicacion*>& arreglo, long inicio, long final) {
        if (inicio < final) {
            long mitad = (inicio + final) / 2;

            Dividir(arreglo, inicio, mitad);
            Dividir(arreglo, mitad + 1, final);
            Mezclar(arreglo, inicio, final);
        }

    }

    void OrdenamientoMerge(vector<Publicacion*>& arreglo) {
        Dividir(arreglo, 0, arreglo.size() - 1);
    }


};


#endif // CUENTA_H
