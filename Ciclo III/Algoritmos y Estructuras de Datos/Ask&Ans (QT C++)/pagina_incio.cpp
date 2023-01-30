#include "pagina_incio.h"
#include "ui_pagina_incio.h"

Pagina_incio::Pagina_incio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pagina_incio)
{
    ui->setupUi(this);

    QPixmap CuadroBuscar(":/resources/img/fondo beige.jpg");
    ui->lbl_CuadroBuscar->setPixmap(CuadroBuscar);
    ui->lbl_Filtrar->setPixmap(CuadroBuscar);

    QStringList titulos;
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

    titulos << "Usuario" << "Pregunta" << "Descripcion" << "Respuestas" << "Likes" << "Fecha de publicación";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    QStringList ordenes;
    ordenes << "Más relevantes" << "Más likes" << "Más recientes" << "Más antiguos";

    QStringList filtros;
    filtros << "Igual a" << "Inicia con" << "Finaliza con" << "Contiene" << "No contiene";

    ui->cb_ordenar->addItems(ordenes);
    ui->cb_filtrar->addItems(filtros);

    CargarPublicaciones();
}

Pagina_incio::~Pagina_incio()
{
    delete ui;
}

void Pagina_incio::ImprimirTabla(vector<Publicacion*> arreglo, int i){

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    ui->tableWidget->setRowHeight(ui->tableWidget->rowCount() - 1, 80);

    QTableWidgetItem* usuario = new QTableWidgetItem(QString::fromStdString(arreglo[i]->getCuenta()));
    usuario->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, usuario);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(arreglo[i]->getTitulo())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(arreglo[i]->getDescripcion())));

    QTableWidgetItem* comentarios =  new QTableWidgetItem(QString::number(arreglo[i]->getCantidadComentarios()));
    comentarios->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, comentarios);

    int CantidadLikes = arreglo[i]->getLikes();

    QTableWidgetItem* likes =  new QTableWidgetItem(QString::number(CantidadLikes));
    likes->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, likes);

    QTableWidgetItem* fecha_publicacion =  new QTableWidgetItem(QString::fromStdString(arreglo[i]->getFechaPublicacion()));
    fecha_publicacion->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 5, fecha_publicacion);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 6, new QTableWidgetItem(QString::number(arreglo[i]->getId())));

}

void Pagina_incio::OrdenarLikes_(Arbol_busqueda<Publicacion*, int>* arbol_likes){
    ui->tableWidget->setRowCount(0);

    vector<Publicacion*> arreglo;

    function<void(Publicacion*)>  AgregarVector = [&](Publicacion* publicacion) { arreglo.push_back(publicacion); };

    arbol_likes->EnOrden(AgregarVector);

    for(long i = arreglo.size() - 1; i >= (long)arreglo.size() - 51 && i >= 0; i--){
        ImprimirTabla(arreglo, i);
    }

}



void Pagina_incio::OrdenarPublicaciones_(Arbol_busqueda<Publicacion *, string>* arbol_publicaciones, int opcion){
    ui->tableWidget->setRowCount(0);

    vector<Publicacion*> arreglo;

    function<void(Publicacion*)>  AgregarVector = [&](Publicacion* publicacion) { arreglo.push_back(publicacion); };

    arbol_publicaciones->EnOrden(AgregarVector);

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

void Pagina_incio::EsIgual(Arbol_busqueda<Publicacion*, string>* arbol_titulos){
    ui->tableWidget->setRowCount(0);

    function<bool(string, string)> lmb_igual = [](string a, string b) {
        if(a == b) return true;
        else return false;
    };

    vector<Publicacion*> Iguales;
    bool termino = false;

    while(!termino){

        Publicacion* publicacion = arbol_titulos->BuscarElementoFiltro(filtro, lmb_igual);

        if(publicacion != 0) Iguales.push_back(publicacion);
        else termino = true;

    }
    for(long i = 0; i < (long)Iguales.size(); i++){
        ImprimirTabla(Iguales, i);
        arbol_titulos->AgregarElemento(Iguales[i]);
    }
}

void Pagina_incio::IniciaCon(Arbol_busqueda<Publicacion *, string>* arbol_titulos){
    ui->tableWidget->setRowCount(0);

    function<bool(string, string)> lmb_IniciaCon = [](string a, string b) {
        if(b == "") return false;

        if(a.size() < b.size()) return false;

        for(long i = 0; i < (long)b.size(); i++){
            if(b[i] != a[i]) return false;
        }
        return true;
    };

    vector<Publicacion*> IniciaCon;
    bool termino = false;

    while(!termino){

        Publicacion* publicacion = arbol_titulos->BuscarElementoFiltro(filtro, lmb_IniciaCon);

        if(publicacion != 0) IniciaCon.push_back(publicacion);
        else termino = true;

    }
    for(long i = 0; i < (long)IniciaCon.size(); i++){
        ImprimirTabla(IniciaCon, i);
        arbol_titulos->AgregarElemento(IniciaCon[i]);
    }
}

void Pagina_incio::FinalizaCon(Arbol_busqueda<Publicacion *, string> *arbol_titulos_final){
    ui->tableWidget->setRowCount(0);

    function<bool(string, string)> lmb_FinalizaCon = [](string a, string b) {
        if(b == "") return false;

        if(a.size() < b.size()) return false;

        for(long i = 0; i < (long)b.size(); i++){
            if(b[i] != a[i]) return false;
        }
        return true;
    };

    vector<Publicacion*> FinalizaCon;
    bool termino = false;

    string invertido = "";
    for(long i = filtro.size() - 1; i >= 0; i--){
        invertido += filtro[i];
    }

    while(!termino){

        Publicacion* publicacion = arbol_titulos_final->BuscarElementoFiltro(invertido, lmb_FinalizaCon);

        if(publicacion != 0) FinalizaCon.push_back(publicacion);
        else termino = true;

    }
    for(long i = 0; i < (long)FinalizaCon.size(); i++){
        ImprimirTabla(FinalizaCon, i);
        arbol_titulos_final->AgregarElemento(FinalizaCon[i]);
    }
}

void Pagina_incio::Contiene(vector<Publicacion*> vector_publicaciones){
    ui->tableWidget->setRowCount(0);

    vector<Publicacion*> arreglo_contiene;

    function<bool(string, string)> lmb_Contiene = [](string a, string b) {

        if(a.size() < b.size()) return false;

        QString qa = QString::fromStdString(a);
        QString qb = QString::fromStdString(b);

        if(qa.contains(qb)) return true;
        else return false;
    };

    for(long i = 0; i < (long)vector_publicaciones.size(); i++){
        if(lmb_Contiene(vector_publicaciones[i]->getTitulo(), filtro) == true) arreglo_contiene.push_back(vector_publicaciones[i]);
    }

    for(long i = 0; i < (long)arreglo_contiene.size() && i < 100; i++){
        ImprimirTabla(arreglo_contiene, i);
    }
}

void Pagina_incio::Relevante(vector<Publicacion*> arreglo_interaccion){
    ui->tableWidget->setRowCount(0);

    for(long i = arreglo_interaccion.size() - 1; i >= (long)arreglo_interaccion.size() - 51 && i >= 0; i--){
        ImprimirTabla(arreglo_interaccion, i);
    }
}

void Pagina_incio::NoContiene(vector<Publicacion*> vector_publicaciones){
    ui->tableWidget->setRowCount(0);

    vector<Publicacion*> arreglo_contiene;

    function<bool(string, string)> lmb_Contiene = [](string a, string b) {

        if(a.size() < b.size()) return false;

        QString qa = QString::fromStdString(a);
        QString qb = QString::fromStdString(b);

        if(qa.contains(qb)) return true;
        else return false;
    };

    for(long i = 0; i < (long)vector_publicaciones.size(); i++){
        if(lmb_Contiene(vector_publicaciones[i]->getTitulo(), filtro) == false) arreglo_contiene.push_back(vector_publicaciones[i]);
    }

    for(long i = 0; i < (long)arreglo_contiene.size() && i < 100; i++){
        ImprimirTabla(arreglo_contiene, i);
    }
}

void Pagina_incio::CargarPublicaciones(){
    OrdenarLikes();
}

void Pagina_incio::on_cb_ordenar_currentIndexChanged(int index)
{
    switch(ui->cb_ordenar->currentIndex()){
    case 0: OrdenarRelevantes(); break;
    case 1: OrdenarLikes(); break;
    case 2: OrdenarPublicacionesRecientes(); break;
    case 3: OrdenarPublicacionesAntiguas(); break;
    }
}



void Pagina_incio::on_tableWidget_cellDoubleClicked(int row, int column)
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



void Pagina_incio::on_bt_Filtrar_clicked()
{
    if(ui->bt_Filtrar->text() == "Filtrar"){
        opcion_filtro = ui->cb_filtrar->currentIndex();
        filtro = ui->le_filtro->text().toUtf8().constData();
        ui->bt_Filtrar->setText("Quitar Filtro");
        Filtrar();
    }
    else{
        on_cb_ordenar_currentIndexChanged(0);
        ui->le_filtro->setText("");
        ui->bt_Filtrar->setText("Filtrar");
    }
}
