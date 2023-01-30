#ifndef DETALLE_PUBLICACION_H
#define DETALLE_PUBLICACION_H

#include <Cuenta.h>
#include <QWidget>
#include <string>
#include <vector>
#include <Arbol_busqueda.h>
#include <fstream>
#include <QMessageBox>
#include <sstream>

using namespace std;

namespace Ui {
class detalle_publicacion;
}

class detalle_publicacion : public QWidget
{
    Q_OBJECT

public:
    explicit detalle_publicacion(QWidget *parent = nullptr);
    ~detalle_publicacion();
    void CargarPublicacion(string titulo, string descripcion, string usuario);
    void CargarComentarios(Publicacion* publicacion, Cuenta* cuenta_activa);
    void EnviarComentario_(Cuenta* cuenta_activa, Arbol_busqueda<Publicacion*, int>* arbol_publicaciones);
    void AgregarLike_(Cuenta* cuenta_activa, Arbol_busqueda<Publicacion*, int>* arbol_publicaciones_id);
    void RecomendarPublicacion_(Cuenta *cuenta_activa, Arbol_busqueda<Publicacion *, int>*& arbol_publicaciones);

    int publicacion_id;
    string nombre;

signals:

    void EnviarComentario();
    void IrPerfil();
    void AgregarArbol();
    void AgregarLike();
    void RecomendarPublicacion();


private slots:
    void on_bt_EnviarComentario_clicked();

    void on_bt_IrPerfil_clicked();

    void on_tabla_comentarios_cellDoubleClicked(int row, int column);

    void on_bt_like_clicked();

    void on_bt_recomendar_clicked();

private:
    Ui::detalle_publicacion *ui;
};

#endif // DETALLE_PUBLICACION_H
