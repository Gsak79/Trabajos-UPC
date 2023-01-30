#ifndef PUBLICACIONES_H
#define PUBLICACIONES_H

#include <string>
#include <Lista.h>
#include <Comentario.h>
#include <functional>
#include <vector>
#include <Arbol_busqueda.h>

using namespace std;

class Publicacion{
    string cuenta_nombre;
    string titulo;
    string descripcion;
    string FechaPublicacion;
    string tituloInvertido;
    int id;
    int numLikes;
    int vistas;
    int recomendaciones;

    Arbol_busqueda<Comentario*, string>* comentarios_recientes;
    Arbol_busqueda<int>* arbol_cuenta_id;
    Arbol_busqueda<string>* arbol_visualizacion;

    function<string(Comentario*)> comparar_fechaComentario= [](Comentario* comentario) { return comentario->getFecha(); };

 public:
    Publicacion(){
        comentarios_recientes = new Arbol_busqueda<Comentario*, string>(comparar_fechaComentario);
        arbol_cuenta_id = new Arbol_busqueda<int>;
        arbol_visualizacion = new Arbol_busqueda<string>;
        vistas = 0;
        recomendaciones = 0;
    }
    ~Publicacion(){}

    void setCuenta(string c) { cuenta_nombre = c; }
    void setTitulo(string t) { titulo = t; }
    void setDescripcion(string d) { descripcion = d; }
    void setFechaPublicacion(string f) { FechaPublicacion = f; }
    void setLikes(int l) { numLikes = l; }
    void setId(int i) { id = i; }

    void setTituloInvertido(string t){
        string invertido = "";

        for(long i = t.size() - 1; i >= 0; i--){
            invertido += t[i];
        }

        tituloInvertido = invertido;
    }

    void BorrarArbolLikes(){
        arbol_cuenta_id->BorrarArbol();
    }
    void BorrarArbolVisualizacion(){
        arbol_visualizacion->BorrarArbol();
    }

    void AgregarComentario(Comentario* c){
        comentarios_recientes->AgregarElemento(c);
    }

    void AgregarLike(int id){
        arbol_cuenta_id->AgregarElemento(id);
        numLikes++;
    }

    int getTotalInteracciones(){
        return numLikes * 2 + comentarios_recientes->getCantidad() * 3 + vistas + recomendaciones * 3;
    }

    void AgregarRecomendacion(){
        recomendaciones++;
    }

    void EliminarRecomendacion(){
        recomendaciones--;
    }

    void AgregarVisualizacion(string c){
        vistas++;
        arbol_visualizacion->AgregarElemento(c);
    }

    void EliminarLike(int id){
        arbol_cuenta_id->EliminarElemento(id);
        numLikes--;
    }

    bool BuscarLike(int id){
        if(arbol_cuenta_id->BuscarElemento(id) == 0) return false;
        else return true;
    }
    int getLikesUsuarios(){
        return arbol_cuenta_id->getCantidad();
    }

    int getCantidadComentarios(){ return comentarios_recientes->getCantidad(); }
    vector<Comentario*> getComentariosRecientes() {
        vector<Comentario*> p;

        function<void(Comentario*)> AgregarVector = [&](Comentario* com) { p.push_back(com); };

        comentarios_recientes->EnOrden(AgregarVector);

        return p;
    }

    string getCuenta(){return cuenta_nombre;}
    string getDescripcion(){return descripcion;}
    string getFechaPublicacion(){return FechaPublicacion;}
    string getTituloInvertido(){ return tituloInvertido; }
    int getLikes(){ return numLikes; }
    int getId() { return id; }
    string getTitulo() { return titulo; }
};

#endif // PUBLICACIONES_H
