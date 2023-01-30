#ifndef REGISTRARSE_H
#define REGISTRARSE_H

#include <QWidget>
#include <string>
#include <fstream>
#include <QMessageBox>
#include <Arbol_busqueda.h>
#include <Cuenta.h>

using namespace std;

namespace Ui {
class Registrarse;
}

class Registrarse : public QWidget
{
    Q_OBJECT

public:
    explicit Registrarse(QWidget *parent = nullptr);
    ~Registrarse();

    bool UsuariosIguales_(Arbol_busqueda<Cuenta*, string>* arbol_nombre, Arbol_busqueda<Cuenta*, string>* arbol_email);
    void Registrar_(Arbol_busqueda<Cuenta*, string>*& arbol_nombre,  Arbol_busqueda<Cuenta*, string>*& arbol_email, Arbol_busqueda<Cuenta*, int>*& arbol_id);

signals:
   void IniciarSesion();
   bool UsuariosIguales();
   void Registrar();

private slots:
    void on_bt_IrIniciarSesion_clicked();

    void on_bt_CrearCuenta_clicked();

private:
    Ui::Registrarse *ui;
    string nombreIngresado;
    string emailIngresado;
};

#endif // REGISTRARSE_H
