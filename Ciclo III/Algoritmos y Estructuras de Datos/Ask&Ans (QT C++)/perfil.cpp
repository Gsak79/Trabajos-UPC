#include "perfil.h"
#include "ui_perfil.h"

Perfil::Perfil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Perfil)
{
    ui->setupUi(this);

    QPixmap foto(":/resources/img/FotoPerfil.png");
    QPixmap CuadroBuscar(":/resources/img/fondo beige.jpg");
    ui->lbl_foto->setPixmap(foto);
    ui->lbl_cuadroblanco->setPixmap(CuadroBuscar);
    ui->lbl_CuadroBuscar->setPixmap(CuadroBuscar);

    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setColumnWidth(0, 150);
    ui->tableWidget->setColumnWidth(1, 565);
    ui->tableWidget->setColumnWidth(2, 200);
    ui->tableWidget->setColumnWidth(3, 100);
    ui->tableWidget->setColumnWidth(4, 100);
    ui->tableWidget->setColumnWidth(5, 150);
    ui->tableWidget->setColumnWidth(6, 0);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->hide();

    QStringList titulos;
    titulos << "Usuario" << "Preguntas" << "Descripcion" << "Respuestas" << "Likes" << "Fecha de publicación" << "";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    QStringList ordenes;
    ordenes << "Más relevantes" << "Más likes" << "Más recientes" << "Más antiguos";

    ui->cb_ordenar->addItems(ordenes);
}

Perfil::~Perfil()
{
    delete ui;
}

void Perfil::CargarMuro(Cuenta* cuenta, Cuenta* cuenta_activa){
    ui->tableWidget->setRowCount(0);
    ui->bt_seguir->setEnabled(true);

    cuenta_muro = cuenta;

    if(cuenta->getId() == cuenta_activa->getId()){
        ui->bt_seguir->setText("---");
        ui->bt_seguir->setDisabled(true);
    }
    else if(cuenta_activa->BuscarCuentaId(cuenta->getId()) == true){
        ui->bt_seguir->setText("Seguido");
    }
    else{
        ui->bt_seguir->setText("Seguir");
    }

    ui->lbl_usuario->setText(QString::fromStdString(cuenta->getNombre()));
    ui->bt_seguidores->setText(QString::number(cuenta->getCantidadSeguidores()));
    ui->bt_seguidos->setText(QString::number(cuenta->getCantidadSeguidos()));
    ui->lbl_correo->setText(QString::fromStdString(cuenta->getEmail()));

    vector<Publicacion*> arreglo;

    arreglo = cuenta->getPublicacionesRecientes();

}

void Perfil::ImprimirTabla(vector<Publicacion*> arreglo, int i){
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    ui->tableWidget->setRowHeight(ui->tableWidget->rowCount() - 1, 80);

    QTableWidgetItem* usuario = new QTableWidgetItem(QString::fromStdString(arreglo[i]->getCuenta()));
    usuario->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, usuario);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(arreglo[i]->getTitulo())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(arreglo[i]->getDescripcion())));

    QTableWidgetItem* comentarios = new QTableWidgetItem(QString::number(arreglo[i]->getCantidadComentarios()));
    comentarios->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, comentarios);

    QTableWidgetItem* likes = new QTableWidgetItem(QString::number(arreglo[i]->getLikes()));
    likes->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, likes);

    QTableWidgetItem* fecha = new QTableWidgetItem(QString::fromStdString(arreglo[i]->getFechaPublicacion()));
    fecha->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 5, fecha);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 6, new QTableWidgetItem(QString::number(arreglo[i]->getId())));
}

void Perfil::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QTableWidgetItem* titulo = ui->tableWidget->item(row, 1);
    QTableWidgetItem* descripcion = ui->tableWidget->item(row, 2);
    QTableWidgetItem* usuario = ui->tableWidget->item(row, 0);
    QTableWidgetItem* id = ui->tableWidget->item(row, 6);

    str_titulo = titulo->text().toUtf8().constData();
    str_descripcion = descripcion->text().toUtf8().constData();
    str_usuario = usuario->text().toUtf8().constData();
    publicacion_id = id->text().toInt();

    DetallarPublicacion();
}



void Perfil::on_bt_seguidores_clicked()
{
    opcion = 0;
    IrSeguidores();
}

void Perfil::on_bt_seguidore1_clicked()
{
    opcion = 0;
    IrSeguidores();
}

void Perfil::on_bt_seguidos_clicked()
{
    opcion = 1;
    IrSeguidores();
}

void Perfil::on_bt_seguidos1_clicked()
{
    opcion = 1;
    IrSeguidores();
}

void Perfil::on_bt_seguir_pressed()
{
    if(ui->bt_seguir->text() == "Seguir"){
        SeguirCuenta();
        ui->bt_seguidores->setText(QString::number(cuenta_muro->getCantidadSeguidores()));
        ui->bt_seguir->setText("Seguido");
    }
    else{
        DejarSeguir();
        ui->bt_seguidores->setText(QString::number(cuenta_muro->getCantidadSeguidores()));
        ui->bt_seguir->setText("Seguir");
    }
}

void Perfil::OrdenarLikes_(Cuenta* cuenta_activa){
    ui->tableWidget->setRowCount(0);

    vector<Publicacion*> arreglo = cuenta_activa->getPublicacionesLikes();

    for(long i = arreglo.size() - 1; i >= (long)arreglo.size() - 51 && i >= 0; i--){
        ImprimirTabla(arreglo, i);
    }

}

void Perfil::Relevante(Cuenta* cuenta_activa){
    ui->tableWidget->setRowCount(0);

    vector<Publicacion*> arreglo_interaccion = cuenta_activa->getPublicacionesRelevantes();

    for(long i = arreglo_interaccion.size() - 1; i >= (long)arreglo_interaccion.size() - 51 && i >= 0; i--){
        ImprimirTabla(arreglo_interaccion, i);
    }
}

void Perfil::OrdenarPublicaciones_(Cuenta* cuenta_activa, int opcion){
    ui->tableWidget->setRowCount(0);

    vector<Publicacion*> arreglo = cuenta_activa->getPublicacionesRecientes();

    if(opcion == 0) {
        for(long i = arreglo.size() - 1; i >= (long)arreglo.size() - 51 && i >= 0; i--){
            ImprimirTabla(arreglo, i);
        }
    }
    else if(opcion == 1){
        for(long i = 0; i < 50 && i < (long)arreglo.size(); i++){
            ImprimirTabla(arreglo, i);
        }
    }
}

void Perfil::on_cb_ordenar_currentIndexChanged(int index)
{
    switch(ui->cb_ordenar->currentIndex()){
    case 0: OrdenarRelevantes(); break;
    case 1: OrdenarLikes(); break;
    case 2: OrdenarPublicacionesRecientes(); break;
    case 3: OrdenarPublicacionesAntiguas(); break;
    }
}
