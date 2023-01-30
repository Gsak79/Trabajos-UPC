#include "registrarse.h"
#include "ui_registrarse.h"

Registrarse::Registrarse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registrarse)
{
    ui->setupUi(this);

    QPixmap CuadroBlanco(":/resources/img/blanco.jpg");
    ui->lbl_CuadroBlanco->setPixmap(CuadroBlanco);
    QPixmap logo(":/resources/img/logo.jpg");
    ui->lbl_logo->setPixmap(logo);

}

Registrarse::~Registrarse()
{
    delete ui;
}

void Registrarse::on_bt_IrIniciarSesion_clicked()
{
    ui->le_email->setText("");
    ui->le_nombre->setText("");
    IniciarSesion();
}

bool Registrarse::UsuariosIguales_(Arbol_busqueda<Cuenta*, string>* Arbol_Nombre, Arbol_busqueda<Cuenta*, string>* Arbol_Email){
    Cuenta* cuenta = Arbol_Nombre->BuscarElemento(nombreIngresado);

    if(cuenta == nullptr) {

        cuenta = Arbol_Email->BuscarElemento(emailIngresado);
        if(cuenta == nullptr) return false;
        else return true;
    }
    else return true;
}

void Registrarse::Registrar_(Arbol_busqueda<Cuenta*, string>*& arbol_nombre,  Arbol_busqueda<Cuenta*, string>*& arbol_email, Arbol_busqueda<Cuenta*, int>*& arbol_Id){
    ofstream archivo("C:/Users/Gonchis/Documents/Trabajo_final/users.tsv", ios::app);
    time_t ahora = time(0);
    tm* time = localtime(&ahora);

    string fecha = to_string(1900 + time->tm_year) + "-" +  to_string(1 + time->tm_mon) + "-" + to_string(time->tm_mday);

    if(archivo.is_open()){
        int id = arbol_Id->getCantidad();

        archivo << id << "\t" << emailIngresado << "\t" << nombreIngresado << "\t" << fecha << endl;

        Cuenta* cuenta = new Cuenta;

        cuenta->setNombre(nombreIngresado);
        cuenta->setEmail(emailIngresado);
        cuenta->setFechaDeCreacion(fecha);
        cuenta->setId(id);

        arbol_Id->AgregarElemento(cuenta);
        arbol_email->AgregarElemento(cuenta);
        arbol_nombre->AgregarElemento(cuenta);

        QMessageBox mensaje;
        mensaje.setText("Se ha creado la cuenta correctamente");
        mensaje.exec();

        archivo.close();
    }
}



void Registrarse::on_bt_CrearCuenta_clicked()
{
    nombreIngresado = ui->le_nombre->text().toUtf8().constData();
    emailIngresado = ui->le_email->text().toUtf8().constData();

    bool iguales = UsuariosIguales();

    if (iguales == true){
        QMessageBox mensaje;
        mensaje.setText("El nombre o el email ingresado ya existe");
        mensaje.exec();
        ui->le_nombre->setText("");
        ui->le_email->setText("");
        ui->le_nombre->setFocus();
        return;
    }
    else{
        Registrar();
    }

}
