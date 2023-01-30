#ifndef PUBLICAR_H
#define PUBLICAR_H

#include <QWidget>
#include <QMessageBox>
#include <fstream>
#include <string>
#include <Cuenta.h>
#include <Arbol_busqueda.h>

using namespace std;

namespace Ui {
class Publicar;
}

class Publicar : public QWidget
{
    Q_OBJECT

public:
    explicit Publicar(QWidget *parent = nullptr);
    ~Publicar();
    void PublicarPublicacion_(Cuenta* cuenta_activa, int id, Arbol_busqueda<Publicacion*, int>*& arbol1, Arbol_busqueda<Publicacion*, string>*& arbol2, Arbol_busqueda<Publicacion*, int>*& arbol3);

signals:
    void PublicarPublicacion();

private slots:
    void on_bt_publicar_clicked();

private:
    Ui::Publicar *ui;
};

#endif // PUBLICAR_H
