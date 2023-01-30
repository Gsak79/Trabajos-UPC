#include "seguidores.h"
#include "ui_seguidores.h"

Seguidores::Seguidores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Seguidores)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0, 120);
    ui->tableWidget->setColumnWidth(1, 300);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->setFont(QFont("calibri", 12));

}

Seguidores::~Seguidores()
{
    delete ui;
}

void Seguidores::CargarSeguidores(Cuenta* cuenta, int opcion, Arbol_busqueda<Cuenta*, int>* arbol_id){
    ui->tableWidget->setRowCount(0);

    if(opcion == 0){
        ui->label->setText("Seguidores");

        vector<int> arreglo = cuenta->getSeguidores();

        for(long i = 0; i < (long)arreglo.size(); i++){

            ui->tableWidget->insertRow(ui->tableWidget->rowCount());

            ui->tableWidget->setRowHeight(ui->tableWidget->rowCount() - 1, 80);

            QLabel* lbl_foto = new QLabel();
            QPixmap foto(":/resources/img/FotoPerfil.png");
            lbl_foto->setPixmap(foto);
            lbl_foto->setFixedWidth(120);
            lbl_foto->setFixedHeight(80);
            lbl_foto->setScaledContents(true);

            QTableWidgetItem* nom = new QTableWidgetItem(QString::fromStdString(arbol_id->BuscarElemento(arreglo[i])->getNombre()));
            nom->setTextAlignment(Qt::AlignCenter);

            ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 0, lbl_foto);
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, nom);
        }


    }
    if(opcion == 1){
        ui->label->setText("Seguidos");

        vector<int> arreglo = cuenta->getSeguidos();

        for(long i = 0; i < (long)arreglo.size(); i++){

            ui->tableWidget->insertRow(ui->tableWidget->rowCount());

            ui->tableWidget->setRowHeight(ui->tableWidget->rowCount() - 1, 80);

            QLabel* lbl_foto = new QLabel();
            QPixmap foto(":/resources/img/FotoPerfil.png");
            lbl_foto->setPixmap(foto);
            lbl_foto->setFixedWidth(120);
            lbl_foto->setFixedHeight(80);
            lbl_foto->setScaledContents(true);

            QTableWidgetItem* nom = new QTableWidgetItem(QString::fromStdString(arbol_id->BuscarElemento(arreglo[i])->getNombre()));
            nom->setTextAlignment(Qt::AlignCenter);

            ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 0, lbl_foto);
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, nom);
        }

    }

}

void Seguidores::on_bt_Regresar_clicked()
{
    RegresarPerfil();
}

void Seguidores::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QTableWidgetItem* it = ui->tableWidget->item(row, 1);

    nombre = it->text().toUtf8().constData();

    IrPerfil();
}
