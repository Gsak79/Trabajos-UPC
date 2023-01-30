#ifndef PAGINA_INCIO_H
#define PAGINA_INCIO_H

#include <QWidget>
#include <Arbol_busqueda.h>
#include <vector>
#include <Cuenta.h>
#include <QHBoxLayout>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;

namespace Ui {
class Pagina_incio;
}

class Pagina_incio : public QWidget
{
    Q_OBJECT

public:
    explicit Pagina_incio(QWidget *parent = nullptr);
    void OrdenarLikes_(Arbol_busqueda<Publicacion*, int>* arbol_likes);
    void OrdenarPublicaciones_(Arbol_busqueda<Publicacion*, string>* arbol_publicaciones, int opcion);
    void EsIgual(Arbol_busqueda<Publicacion*, string>* arbol_titulos);
    void IniciaCon(Arbol_busqueda<Publicacion*, string>* arbol_titulos);
    void Contiene(vector<Publicacion*> vector_publicaciones);
    void NoContiene(vector<Publicacion*> vector_publicaciones);
    void FinalizaCon(Arbol_busqueda<Publicacion*, string>* arbol_titulos_final);
    void Relevante(vector<Publicacion*> arreglo_interaccion);

    ~Pagina_incio();

    string str_titulo;
    string str_descripcion;
    string str_usuario;
    string inicio;
    string filtro;
    int publicacion_id;
    int opcion_filtro;

public slots:
    void on_cb_ordenar_currentIndexChanged(int index);

signals:
    void OrdenarLikes();
    void OrdenarPublicacionesRecientes();
    void OrdenarPublicacionesAntiguas();
    void OrdenarRelevantes();
    void DetallarPublicacion();
    void Filtrar();

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_bt_Filtrar_clicked();

private:
    Ui::Pagina_incio *ui;
    void CargarPublicaciones();
    void ImprimirTabla(vector<Publicacion*> arreglo, int i);
};

#endif // PAGINA_INCIO_H
