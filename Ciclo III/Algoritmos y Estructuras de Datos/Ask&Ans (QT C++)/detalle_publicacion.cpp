#include "detalle_publicacion.h"
#include "ui_detalle_publicacion.h"

detalle_publicacion::detalle_publicacion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::detalle_publicacion)
{
    ui->setupUi(this);

    QPixmap foto(":/resources/img/FotoPerfil.png");
    ui->lbl_foto->setPixmap(foto);

    ui->tabla_comentarios->setColumnCount(3);
    ui->tabla_comentarios->setColumnWidth(0, 150);
    ui->tabla_comentarios->setColumnWidth(1, 950);
    ui->tabla_comentarios->setColumnWidth(2, 200);


    ui->tabla_comentarios->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tabla_comentarios->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tabla_comentarios->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tabla_comentarios->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabla_comentarios->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tabla_comentarios->verticalHeader()->hide();

    QStringList titulos;
    titulos << "Usuario" << "Comentario" << "Fecha de publicación";
    ui->tabla_comentarios->setHorizontalHeaderLabels(titulos);

}

detalle_publicacion::~detalle_publicacion()
{
    delete ui;
}



void detalle_publicacion::CargarPublicacion(string titulo, string descripcion, string usuario){

    ui->lbl_titulo->setText(QString::fromStdString(titulo));
    ui->lbl_descripcion->setText(QString::fromStdString(descripcion));
    ui->lbl_usuario->setText(QString::fromStdString(usuario));

}

void detalle_publicacion::CargarComentarios(Publicacion* publicacion, Cuenta* cuenta_activa){
    nombre = publicacion->getCuenta();

    if(publicacion->BuscarLike(cuenta_activa->getId())){
        ui->bt_like->setStyleSheet("QPushButton{\nbackground-color: #086FE6;\ncolor: white;\nborder-radius: 10px;\nfont-weight: bold;}");
    }
    else{
        ui->bt_like->setStyleSheet("QPushButton{\nbackground-color: #086FE6;\ncolor: white;\nborder-radius: 10px;\n}");
    }
    if(cuenta_activa->BuscarRecomendados(publicacion_id)){
        ui->bt_recomendar->setStyleSheet("QPushButton{\nbackground-color: #086FE6;\ncolor: white;\nborder-radius: 10px;\nfont-weight: bold;}");
    }
    else{
        ui->bt_recomendar->setStyleSheet("QPushButton{\nbackground-color: #086FE6;\ncolor: white;\nborder-radius: 10px;\n}");
    }

    ui->tabla_comentarios->setRowCount(0);

    ui->lbl_comentarios->setText("Respuestas (" + QString::number(publicacion->getCantidadComentarios()) + "):");

    vector<Comentario*> arreglo;

    arreglo = publicacion->getComentariosRecientes();

    for(long i = arreglo.size() - 1; i >= 0; i--){
        ui->tabla_comentarios->insertRow(ui->tabla_comentarios->rowCount());

        QTableWidgetItem* usuario = new QTableWidgetItem(QString::fromStdString(arreglo[i]->getCuenta()));
        usuario->setTextAlignment(Qt::AlignCenter);

        ui->tabla_comentarios->setItem(ui->tabla_comentarios->rowCount() - 1, 0, usuario);
        ui->tabla_comentarios->setItem(ui->tabla_comentarios->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(arreglo[i]->getComentario())));


        QTableWidgetItem* fecha = new QTableWidgetItem(QString::fromStdString(arreglo[i]->getFecha()));
        fecha->setTextAlignment(Qt::AlignCenter);

        ui->tabla_comentarios->setItem(ui->tabla_comentarios->rowCount() - 1, 2, fecha);

    }
}

void detalle_publicacion::on_bt_EnviarComentario_clicked()
{
    if(ui->le_comentario->text() != "") {
        EnviarComentario();
        ui->le_comentario->setText("");
    }
    else {
        QMessageBox mensaje;
        mensaje.setText("Escriba un comentario antes de enviar");
        mensaje.exec();
    }
}

void detalle_publicacion::EnviarComentario_(Cuenta* cuenta_activa, Arbol_busqueda<Publicacion*, int>* arbol_publicaciones){
    string comentario = ui->le_comentario->text().toUtf8().constData();

    ofstream archivo("C:/Users/Gonchis/Documents/Trabajo_final/comments.tsv", ios::app);

    Comentario* comment = new Comentario;

    time_t ahora = time(0);
    tm* time = localtime(&ahora);

    string fecha = to_string(1900 + time->tm_year) + "-" +  to_string(1 + time->tm_mon) + "-" + to_string(time->tm_mday);

    comment->setCuenta(cuenta_activa->getNombre());
    comment->setComentario(comentario);
    comment->setFecha(fecha);

    Publicacion* publicacion = arbol_publicaciones->BuscarElemento(publicacion_id);

    publicacion->AgregarComentario(comment);

    if(archivo.is_open()){
        archivo << to_string(cuenta_activa->getId()) << '\t' << to_string(publicacion_id) << '\t' << fecha << '\t' << comentario << endl;

        archivo.close();
    }

    CargarComentarios(publicacion, cuenta_activa);

}

void detalle_publicacion::on_bt_IrPerfil_clicked()
{

    IrPerfil();
}

void detalle_publicacion::on_tabla_comentarios_cellDoubleClicked(int row, int column)
{
    QTableWidgetItem* it = ui->tabla_comentarios->item(row, 0);

    nombre = it->text().toUtf8().constData();

    IrPerfil();
}

void detalle_publicacion::on_bt_like_clicked()
{
    AgregarLike();
}

void detalle_publicacion::AgregarLike_(Cuenta *cuenta_activa, Arbol_busqueda<Publicacion*, int>* arbol_publicaciones_id){
    fstream archivo("C:/Users/Gonchis/Documents/Trabajo_final/likes.tsv", ios::app | ios::in);
    string linea;
    string atributo;

    if(archivo.is_open()){

        if(ui->bt_like->styleSheet() == "QPushButton{\nbackground-color: #086FE6;\ncolor: white;\nborder-radius: 10px;\n}"){
            ui->bt_like->setStyleSheet("QPushButton{\nbackground-color: #086FE6;\ncolor: white;\nborder-radius: 10px;\nfont-weight: bold;}");
            archivo << cuenta_activa->getId() << '\t' << publicacion_id << endl;
            arbol_publicaciones_id->BuscarElemento(publicacion_id)->AgregarLike(cuenta_activa->getId());
            archivo.close();
        }
        else{
            ui->bt_like->setStyleSheet("QPushButton{\nbackground-color: #086FE6;\ncolor: white;\nborder-radius: 10px;\n}");
            arbol_publicaciones_id->BuscarElemento(publicacion_id)->EliminarLike(cuenta_activa->getId());
            ofstream Nuevo("C:/Users/Gonchis/Documents/Trabajo_final/temporal.tsv", ios::app);

            string linea;
            string atributo;

            if(Nuevo.is_open()){
                getline(archivo, linea);

                Nuevo << linea << endl;

                while(!archivo.eof()){

                    getline(archivo, linea);

                    stringstream s(linea);

                    if(getline(s, atributo, '\t')){

                        if(stoi(atributo) == cuenta_activa->getId()){
                            getline(s, atributo, '\t');

                            if(stoi(atributo) != publicacion_id){
                                Nuevo << linea << endl;
                            }
                        }
                        else{
                            Nuevo << linea << endl;
                        }
                    }
                }
                archivo.close();
                Nuevo.close();
                remove("C:/Users/Gonchis/Documents/Trabajo_final/likes.tsv");
                rename("C:/Users/Gonchis/Documents/Trabajo_final/temporal.tsv", "C:/Users/Gonchis/Documents/Trabajo_final/likes.tsv");
            }


        }
    }
}



void detalle_publicacion::RecomendarPublicacion_(Cuenta *cuenta_activa, Arbol_busqueda<Publicacion *, int>*& arbol_publicaciones){
    fstream archivo("C:/Users/Gonchis/Documents/Trabajo_final/interaction.tsv", ios::app | ios::in);
    ofstream nuevo("C:/Users/Gonchis/Documents/Trabajo_final/nuevo.tsv", ios::app);
    string linea;
    string atributo;

    if(archivo.is_open() && nuevo.is_open()){
        if(ui->bt_recomendar->styleSheet() == "QPushButton{\nbackground-color: #086FE6;\ncolor: white;\nborder-radius: 10px;\n}"){
            getline(archivo, linea);
            arbol_publicaciones->BuscarElemento(publicacion_id)->AgregarRecomendacion();
            nuevo << linea << endl;

            while(!archivo.eof()){

                getline(archivo, linea);

                stringstream s(linea);

                if(getline(s, atributo, '\t')){
                    if(stoi(atributo) == cuenta_activa->getId()){
                        getline(s, atributo, '\t');
                        if(stoi(atributo) == publicacion_id){
                            nuevo << cuenta_activa->getId() << '\t' << publicacion_id << '\t';
                            getline(s, atributo, '\t');
                            nuevo << atributo << '\t' << "TRUE" << endl;
                        }
                        else{
                            nuevo << linea << endl;
                        }
                    }
                    else{
                        nuevo << linea << endl;
                    }
                }
            }

            ui->bt_recomendar->setStyleSheet("QPushButton{\nbackground-color: #086FE6;\ncolor: white;\nborder-radius: 10px;\nfont-weight: bold;}");
            cuenta_activa->AgregarRecomendados(arbol_publicaciones->BuscarElemento(publicacion_id));
            archivo.close();
            nuevo.close();
        }
        else{
            getline(archivo, linea);
            arbol_publicaciones->BuscarElemento(publicacion_id)->EliminarRecomendacion();
            nuevo << linea << endl;

            while(!archivo.eof()){

                getline(archivo, linea);

                stringstream s(linea);

                if(getline(s, atributo, '\t')){
                    if(stoi(atributo) == cuenta_activa->getId()){
                        getline(s, atributo, '\t');
                        if(stoi(atributo) == publicacion_id){
                            nuevo << cuenta_activa->getId() << '\t' << publicacion_id << '\t';
                            getline(s, atributo, '\t');
                            nuevo << atributo << '\t' << "FALSE" << endl;
                        }
                        else{
                            nuevo << linea << endl;
                        }
                    }
                    else{
                        nuevo << linea << endl;
                    }
                }
            }
            ui->bt_recomendar->setStyleSheet("QPushButton{\nbackground-color: #086FE6;\ncolor: white;\nborder-radius: 10px;}");
            cuenta_activa->EliminarRecomendados(arbol_publicaciones->BuscarElemento(publicacion_id));
            archivo.close();
            nuevo.close();
        }
        remove("C:/Users/Gonchis/Documents/Trabajo_final/interaction.tsv");
        rename("C:/Users/Gonchis/Documents/Trabajo_final/nuevo.tsv", "C:/Users/Gonchis/Documents/Trabajo_final/interaction.tsv");
    }


}

void detalle_publicacion::on_bt_recomendar_clicked()
{
    RecomendarPublicacion();
}
