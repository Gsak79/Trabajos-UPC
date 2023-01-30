#ifndef SEGUIDORES_H
#define SEGUIDORES_H

#include <QWidget>
#include <Cuenta.h>

namespace Ui {
class Seguidores;
}

class Seguidores : public QWidget
{
    Q_OBJECT

public:
    explicit Seguidores(QWidget *parent = nullptr);
    ~Seguidores();

    void CargarSeguidores(Cuenta* cuenta, int opcion, Arbol_busqueda<Cuenta*, int>* arbol_id);

    string nombre;

signals:
    void RegresarPerfil();
    void IrPerfil();

private slots:
    void on_bt_Regresar_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::Seguidores *ui;
};

#endif // SEGUIDORES_H
