#include "publicar.h"
#include "ui_publicar.h"

Publicar::Publicar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Publicar)
{
    ui->setupUi(this);
}

Publicar::~Publicar()
{
    delete ui;
}

void Publicar::PublicarPublicacion_(Cuenta* cuenta_activa, int id, Arbol_busqueda<Publicacion*, int>*& arbol1, Arbol_busqueda<Publicacion*, string>*& arbol2, Arbol_busqueda<Publicacion*, int>*& arbol3){
    ofstream archivo("C:/Users/Gonchis/Documents/Trabajo_final/publications.tsv", ios::app);

    string titulo = ui->le_titulo->text().toUtf8().constData();
    string descripcion = ui->le_descripcion->text().toUtf8().constData();

    time_t ahora = time(0);
    tm* time = localtime(&ahora);

    string fecha = to_string(1900 + time->tm_year) + "-" +  to_string(1 + time->tm_mon) + "-" + to_string(time->tm_mday);

    Publicacion* publicacion = new Publicacion;

    publicacion->setCuenta(cuenta_activa->getNombre());
    publicacion->setTitulo(titulo);
    publicacion->setDescripcion(descripcion);
    publicacion->setLikes(0);
    publicacion->setId(id);
    publicacion->setFechaPublicacion(fecha);

    cuenta_activa->AgregarPublicaciones(publicacion);

    arbol1->AgregarElemento(publicacion);
    arbol2->AgregarElemento(publicacion);
    arbol3->AgregarElemento(publicacion);

    if(archivo.is_open()){
        archivo << id << '\t' << cuenta_activa->getId() << '\t' << titulo << '\t' << descripcion << '\t' << fecha << '\t' << publicacion->getLikes() << endl;

        archivo.close();
    }
}

void Publicar::on_bt_publicar_clicked()
{
    QMessageBox mensaje;
    if(ui->le_titulo->text() == "" || ui->le_descripcion->text() == ""){
        mensaje.setText("No ha escrito un titulo y/o una descripción");
        mensaje.exec();
    }
    else{
        PublicarPublicacion();
        ui->le_descripcion->setText("");
        ui->le_titulo->setText("");
    }
}
