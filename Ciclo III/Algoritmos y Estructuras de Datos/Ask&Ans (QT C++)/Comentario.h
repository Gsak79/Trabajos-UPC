#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>

using namespace std;

class Comentario{
    string cuenta_nombre;
    string fecha;
    string comentario;

public:
    Comentario(){}
    ~Comentario(){}

    void setCuenta(string c) { cuenta_nombre = c; }
    void setFecha(string f) { fecha = f; }
    void setComentario(string c) { comentario = c; }

    string getCuenta() { return cuenta_nombre; }
    string getFecha() { return fecha; }
    string getComentario() { return comentario; }


};

#endif // COMENTARIO_H
