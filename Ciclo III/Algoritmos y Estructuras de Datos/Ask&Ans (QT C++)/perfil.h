#ifndef PERFIL_H
#define PERFIL_H

#include <QWidget>
#include <string>
#include <Cuenta.h>
using namespace std;

namespace Ui {
class Perfil;
}

class Perfil : public QWidget
{
    Q_OBJECT

public:
    explicit Perfil(QWidget *parent = nullptr);
    ~Perfil();

    void CargarMuro(Cuenta* cuenta, Cuenta* cuenta_activa);
    void OrdenarLikes_(Cuenta* cuenta_activa);
    void OrdenarPublicaciones_(Cuenta* cuenta_activa, int opcion);
    void Relevante(Cuenta* cuenta_activa);

    string str_titulo;
    string str_descripcion;
    string str_usuario;
    int publicacion_id;
    Cuenta* cuenta_muro;
    int opcion;

signals:
    void DetallarPublicacion();
    void IrSeguidores();
    void SeguirCuenta();
    void DejarSeguir();
    void OrdenarLikes();
    void OrdenarPublicacionesRecientes();
    void OrdenarPublicacionesAntiguas();
    void OrdenarRelevantes();

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_bt_seguidores_clicked();
    void on_bt_seguidore1_clicked();
    void on_bt_seguidos_clicked();
    void on_bt_seguidos1_clicked();
    void on_bt_seguir_pressed();
    void ImprimirTabla(vector<Publicacion*> arreglo, int i);
    void on_cb_ordenar_currentIndexChanged(int index);

private:
    Ui::Perfil *ui;
};

#endif // PERFIL_H
