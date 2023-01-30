#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    this->setWindowState(Qt::WindowMaximized);
    this->setWindowTitle("Ask&Ans");

    QPixmap bkgnd(":/resources/img/fondo.jpg");
    bkgnd = bkgnd.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPixmap CuadroBlanco(":/resources/img/blanco.jpg");
    ui->lbl_CuadroBlanco->setPixmap(CuadroBlanco);
    QPixmap logo(":/resources/img/logo.jpg");
    ui->lbl_logo->setPixmap(logo);
    ui->lbl_logo_2->setPixmap(logo);

    ui->bt_Preguntar->setVisible(false);
    ui->bt_Inicio->setVisible(false);
    ui->bt_MiPerfil->setVisible(false);
    ui->lbl_logo_2->setVisible(false);
    ui->bt_cerrar_sesion->setVisible(false);

    ui->le_nombre->setFocus();

    ui->stackedWidget->addWidget(&registrarse);
    ui->stackedWidget->addWidget(&pagina_inicio);
    ui->stackedWidget->addWidget(&DetallePublicacion);
    ui->stackedWidget->addWidget(&publicar);
    ui->stackedWidget->addWidget(&perfil);
    ui->stackedWidget->addWidget(&seguidores);

    connect(&registrarse, SIGNAL(IniciarSesion()), this, SLOT(IniciarSesionH()));
    connect(&registrarse, SIGNAL(UsuariosIguales()), this, SLOT(UsuariosIgualesH()));
    connect(&registrarse, SIGNAL(Registrar()), this, SLOT(RegistrarH()));
    connect(&pagina_inicio, SIGNAL(OrdenarLikes()), this, SLOT(OrdenarLikesH()));
    connect(&pagina_inicio, SIGNAL(OrdenarPublicacionesAntiguas()), this, SLOT(OrdenarPublicacionesAntiguasH()));
    connect(&pagina_inicio, SIGNAL(OrdenarPublicacionesRecientes()), this, SLOT(OrdenarPublicacionesRecientesH()));
    connect(&pagina_inicio, SIGNAL(OrdenarRelevantes()), this, SLOT(OrdenarRelevantesH()));
    connect(&pagina_inicio, SIGNAL(DetallarPublicacion()), this, SLOT(DetallarPublicacionH()));
    connect(&DetallePublicacion, SIGNAL(AgregarLike()), this, SLOT(AgregarLikeH()));
    connect(&DetallePublicacion, SIGNAL(EnviarComentario()), this, SLOT(EnviarComentarioH()));
    connect(&publicar, SIGNAL(PublicarPublicacion()), this, SLOT(PublicarPublicacionH()));
    connect(&perfil, SIGNAL(DetallarPublicacion()), this, SLOT(DetallarPublicacionHH()));
    connect(&DetallePublicacion, SIGNAL(IrPerfil()), this, SLOT(IrPerfilH()));
    connect(&seguidores, SIGNAL(IrPerfil()), this, SLOT(IrPerfilHH()));
    connect(&pagina_inicio, SIGNAL(Filtrar()), this, SLOT(FiltrarH()));
    connect(&perfil, SIGNAL(IrSeguidores()), this, SLOT(IrSeguidoresH()));
    connect(&perfil, SIGNAL(SeguirCuenta()), this, SLOT(SeguirCuentaH()));
    connect(&perfil, SIGNAL(DejarSeguir()), this, SLOT(DejarSeguirH()));
    connect(&seguidores, SIGNAL(RegresarPerfil()), this, SLOT(RegresarPerfilH()));
    connect(&DetallePublicacion, SIGNAL(RecomendarPublicacion()), this, SLOT(RecomendarPublicacionH()));
    connect(&perfil, SIGNAL(OrdenarLikes()), this, SLOT(OrdenarLikesP()));
    connect(&perfil, SIGNAL(OrdenarPublicacionesAntiguas()), this, SLOT(OrdenarPublicacionesAntiguasP()));
    connect(&perfil, SIGNAL(OrdenarPublicacionesRecientes()), this, SLOT(OrdenarPublicacionesRecientesP()));
    connect(&perfil, SIGNAL(OrdenarRelevantes()), this, SLOT(OrdenarRelevantesP()));

    function<string(Cuenta*)>  comparar_nombre = [](Cuenta* cuenta) { return cuenta->getNombre(); };
    function<string(Cuenta*)>  comparar_email = [](Cuenta* cuenta) { return cuenta->getEmail(); };
    function<int(Cuenta*)>  comparar_id = [](Cuenta* cuenta) { return cuenta->getId(); };
    function<int(Publicacion*)>  comparar_likes = [](Publicacion* publicacion) { return publicacion->getLikes(); };
    function<string(Publicacion*)> comparar_fechaPublicacion = [](Publicacion* publicacion) { return publicacion->getFechaPublicacion(); };
    function<int(Publicacion*)> comparar_publicacionId = [](Publicacion* publicacion) { return publicacion->getId(); };
    function<string(Publicacion*)> comparar_titulo = [](Publicacion* publicacion) { return publicacion->getTitulo(); };
    function<string(Publicacion*)> comparar_titulo_invertido = [](Publicacion* publicacion) { return publicacion->getTituloInvertido(); };

    Arbol_Nombre = new Arbol_busqueda<Cuenta*, string>(comparar_nombre);
    Arbol_Email = new Arbol_busqueda<Cuenta*, string>(comparar_email);
    Arbol_Id = new Arbol_busqueda<Cuenta*, int>(comparar_id);
    Arbol_likes = new Arbol_busqueda<Publicacion*, int>(comparar_likes);
    Arbol_fechaPublicacion = new Arbol_busqueda<Publicacion*, string>(comparar_fechaPublicacion);
    Arbol_Publicacion_id = new Arbol_busqueda<Publicacion*, int>(comparar_publicacionId);
    Arbol_Titulo = new Arbol_busqueda<Publicacion*, string>(comparar_titulo);
    Arbol_Titulo_Final = new Arbol_busqueda<Publicacion*, string>(comparar_titulo_invertido);

    CargarDatos();

}

Login::~Login()
{
    delete ui;
}


void Login::on_bt_IrRegistrar_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Login::IniciarSesionH(){
    ui->stackedWidget->setCurrentIndex(0);
    ui->le_email->setText("");
    ui->le_nombre->setText("");
}

void Login::CargarUsuarios(){
    ifstream archivo("C:/Users/Gonchis/Documents/Trabajo_final/users.tsv", ios::in);
    string linea;
    string atributo;
    int contador;

    if(archivo.is_open()){

        getline(archivo, linea);

        while(!archivo.eof()){

            contador = 0;

            getline(archivo, linea);

            stringstream s(linea);

            Cuenta* cuenta = new Cuenta;

            bool termino = true;

            while(getline(s, atributo, '\t')){
                switch(contador){
                case 0: cuenta->setId(stoi(atributo)); break;
                case 1: cuenta->setEmail(atributo); break;
                case 2: cuenta->setNombre(atributo); break;
                case 3: cuenta->setFechaDeCreacion(atributo); termino = false; break;
                }

                contador++;
            }
            if(termino == false){
                Arbol_Nombre->AgregarElemento(cuenta);
                Arbol_Email->AgregarElemento(cuenta);
                Arbol_Id->AgregarElemento(cuenta);
            }


        }
        archivo.close();
    }

}

void Login::CargarPublicaciones(){
    string linea;
    string atributo;
    int contador;

    ifstream archivo2("C:/Users/Gonchis/Documents/Trabajo_final/publications.tsv", ios::in);

    if(archivo2.is_open()){

        getline(archivo2, linea);

        while(!archivo2.eof()){

            contador = 0;

            getline(archivo2, linea);

            stringstream s(linea);

            Publicacion* publicacion = new Publicacion;

            bool termino = true;

            while(getline(s, atributo, '\t')){
                switch(contador){
                case 0: publicacion->setId(stoi(atributo)); break;
                case 1: publicacion->setCuenta(Arbol_Id->BuscarElemento(stoi(atributo))->getNombre()); break;
                case 2: publicacion->setTitulo(atributo); publicacion->setTituloInvertido(atributo); break;
                case 3: publicacion->setDescripcion(atributo); break;
                case 4: publicacion->setFechaPublicacion(atributo); break;
                case 5: publicacion->setLikes(stoi(atributo)); termino = false; break;
                }

                contador++;
            }
            if(termino == false) {
                Arbol_fechaPublicacion->AgregarElemento(publicacion);
                Arbol_Publicacion_id->AgregarElemento(publicacion);
                Arbol_Nombre->BuscarElemento(publicacion->getCuenta())->AgregarPublicaciones(publicacion);
                Arbol_Titulo->AgregarElemento(publicacion);
                Arbol_Titulo_Final->AgregarElemento(publicacion);
                arreglo_interaccion.push_back(publicacion);
            }
        }
        archivo2.close();
    }
}

void Login::CargarComentarios(){
    string linea;
    string atributo;
    int contador;

    ifstream archivo3("C:/Users/Gonchis/Documents/Trabajo_final/comments.tsv", ios::in);

    if(archivo3.is_open()){

        getline(archivo3, linea);

        while(!archivo3.eof()){

            contador = 0;

            getline(archivo3, linea);

            stringstream s(linea);

            Comentario* comentario = new Comentario;
            int publicacionId;

            bool termino = true;

            while(getline(s, atributo, '\t')){
                switch(contador){
                case 0: comentario->setCuenta(Arbol_Id->BuscarElemento(stoi(atributo))->getNombre()); break;
                case 1: publicacionId = stoi(atributo); break;
                case 2: comentario->setFecha(atributo); break;
                case 3: comentario->setComentario(atributo); termino = false; break;
                }
                contador++;
            }
            if(termino == false) {
                Arbol_Publicacion_id->BuscarElemento(publicacionId)->AgregarComentario(comentario);
            }

        }
        archivo3.close();
    }

}

void Login::CargarFollowers(){
    string linea;
    string atributo;
    int contador;

    ifstream archivo4("C:/Users/Gonchis/Documents/Trabajo_final/followers.tsv", ios::in);

    if(archivo4.is_open()){

        getline(archivo4, linea);

        while(!archivo4.eof()){

            contador = 0;

            getline(archivo4, linea);

            stringstream s(linea);

            bool termino = true;

            int id_seguido;
            int id_seguidor;

            while(getline(s, atributo, '\t')){
                switch(contador){
                case 0: id_seguidor = stoi(atributo); break;
                case 1: id_seguido = stoi(atributo); termino = false; break;
                }
                contador++;
            }
            if(termino == false) {
                Arbol_Id->BuscarElemento(id_seguidor)->AgregarSeguidos(id_seguido);
                Arbol_Id->BuscarElemento(id_seguido)->AgregarSeguidores(id_seguidor);
            }
        }
        archivo4.close();
    }
}

void Login::CargarLikes(){
    string linea;
    string atributo;
    int contador;

    ifstream archivo5("C:/Users/Gonchis/Documents/Trabajo_final/likes.tsv", ios::in);

    if(archivo5.is_open()){

        getline(archivo5, linea);

        while(!archivo5.eof()){

            contador = 0;

            getline(archivo5, linea);

            stringstream s(linea);

            bool termino = true;

            int id_cuenta;
            int id_publicacion;

            while(getline(s, atributo, '\t')){
                switch(contador){
                case 0: id_cuenta = stoi(atributo); break;
                case 1: id_publicacion = stoi(atributo); termino = false; break;
                }
                contador++;
            }
            if(termino == false) {
                Arbol_Publicacion_id->BuscarElemento(id_publicacion)->AgregarLike(id_cuenta);
            }
        }
        archivo5.close();
        for(long i = 0; i < (long)arreglo_interaccion.size(); i++){
            Arbol_likes->AgregarElemento(arreglo_interaccion[i]);
            Arbol_Nombre->BuscarElemento(arreglo_interaccion[i]->getCuenta())->AgregarPublicacionesLike(arreglo_interaccion[i]);
        }
    }
}

void Login::CargarInteracciones(){
    string linea;
    string atributo;
    int contador;

    ifstream archivo6("C:/Users/Gonchis/Documents/Trabajo_final/interaction.tsv", ios::in);

    if(archivo6.is_open()){

        getline(archivo6, linea);

        while(!archivo6.eof()){

            contador = 0;

            getline(archivo6, linea);

            stringstream s(linea);

            bool termino = true;

            int id_cuenta;
            int id_publicacion;

            while(getline(s, atributo, '\t')){
                switch(contador){
                case 0: id_cuenta = stoi(atributo); break;
                case 1: id_publicacion = stoi(atributo); break;
                case 2: Arbol_Publicacion_id->BuscarElemento(id_publicacion)->AgregarVisualizacion(atributo); break;
                case 3: if(atributo == "TRUE") {
                        Arbol_Id->BuscarElemento(id_cuenta)->AgregarRecomendados(Arbol_Publicacion_id->BuscarElemento(id_publicacion));
                        Arbol_Publicacion_id->BuscarElemento(id_publicacion)->AgregarRecomendacion();
                    }
                    termino = false;
                }
                contador++;
            }
            if(termino == false){

            }
        }
        archivo6.close();
    }
}

void Login::CargarDatos(){
    CargarUsuarios();
    CargarPublicaciones();
    CargarLikes();
    CargarComentarios();
    CargarFollowers();
    CargarInteracciones();
}

void Login::on_bt_IniciarSesion_clicked()
{
    QMessageBox mensaje;
    string NombreIngresado = ui->le_nombre->text().toUtf8().constData();
    string EmailIngresado = ui->le_email->text().toUtf8().constData();
    ui->le_nombre->setText("");
    ui->le_email->setText("");

    Cuenta* CuentaInicioSesion = Arbol_Nombre->BuscarElemento(NombreIngresado);

    if(CuentaInicioSesion == nullptr){
        mensaje.setText("El usuario o el email ingresado es incorrecto");
        mensaje.exec();
        ui->le_nombre->setFocus();
        return;
    }
    else if(CuentaInicioSesion->getEmail() != EmailIngresado){
        mensaje.setText("El usuario o el email ingresado es incorrecto");
        ui->le_nombre->setFocus();
        mensaje.exec();
        return;
    }
    else{
        QPixmap bkgnd(":/resources/img/fondo celeste.jpg");
        bkgnd = bkgnd.scaled(this->size());
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

        cuenta_activa = CuentaInicioSesion;

        ui->bt_Preguntar->setVisible(true);
        ui->bt_Inicio->setVisible(true);
        ui->bt_MiPerfil->setVisible(true);
        ui->lbl_logo_2->setVisible(true);
        ui->bt_cerrar_sesion->setVisible(true);

        ui->stackedWidget->setCurrentIndex(2);

        pagina_inicio.OrdenarLikes_(Arbol_likes);
    }

}

bool Login::UsuariosIgualesH(){
    return registrarse.UsuariosIguales_(Arbol_Nombre, Arbol_Email);
}

void Login::RegistrarH(){
    registrarse.Registrar_(Arbol_Nombre, Arbol_Email, Arbol_Id);
    ui->stackedWidget->setCurrentIndex(0);
}

void Login::OrdenarLikesH(){
    pagina_inicio.OrdenarLikes_(Arbol_likes);
}

void Login::OrdenarPublicacionesRecientesH(){
    pagina_inicio.OrdenarPublicaciones_(Arbol_fechaPublicacion, 0);
}

void Login::OrdenarPublicacionesAntiguasH(){
    pagina_inicio.OrdenarPublicaciones_(Arbol_fechaPublicacion, 1);

}

void Login::DetallarPublicacionH(){
    ui->stackedWidget->setCurrentIndex(3);
    DetallePublicacion.publicacion_id = pagina_inicio.publicacion_id;
    DetallePublicacion.CargarPublicacion(pagina_inicio.str_titulo, pagina_inicio.str_descripcion, pagina_inicio.str_usuario);
    DetallePublicacion.CargarComentarios(Arbol_Publicacion_id->BuscarElemento(pagina_inicio.publicacion_id), cuenta_activa);

    if(cuenta_activa->BuscarRecomendados(DetallePublicacion.publicacion_id) == false){

        cuenta_activa->AgregarRecomendados(Arbol_Publicacion_id->BuscarElemento(DetallePublicacion.publicacion_id));

        time_t ahora = time(0);
        tm* time = localtime(&ahora);

        string fecha = to_string(1900 + time->tm_year) + "-" +  to_string(1 + time->tm_mon) + "-" + to_string(time->tm_mday);

        ofstream archivo("C:/Users/Gonchis/Documents/Trabajo_final/interaction.tsv", ios::app);

        if(archivo.is_open()){
            archivo << cuenta_activa->getId() << '\t' << DetallePublicacion.publicacion_id << '\t' << fecha << '\t' << "FALSE" << endl;
        }

    }
}

void Login::EnviarComentarioH(){
    DetallePublicacion.EnviarComentario_(cuenta_activa, Arbol_Publicacion_id);
}

void Login::on_bt_Inicio_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    pagina_inicio.on_cb_ordenar_currentIndexChanged(0);
}

void Login::on_bt_Preguntar_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Login::PublicarPublicacionH(){
    Publicacion* maximo = Arbol_Publicacion_id->getMayor();
    publicar.PublicarPublicacion_(cuenta_activa, maximo->getId() + 1, Arbol_Publicacion_id, Arbol_fechaPublicacion, Arbol_likes);
    pagina_inicio.on_cb_ordenar_currentIndexChanged(0);
    ui->stackedWidget->setCurrentIndex(2);
}

void Login::on_bt_MiPerfil_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    perfil.CargarMuro(cuenta_activa, cuenta_activa);
    perfil.Relevante(perfil.cuenta_muro);
}

void Login::DetallarPublicacionHH(){
    ui->stackedWidget->setCurrentIndex(3);
    DetallePublicacion.publicacion_id = perfil.publicacion_id;
    DetallePublicacion.CargarPublicacion(perfil.str_titulo, perfil.str_descripcion, perfil.str_usuario);
    DetallePublicacion.CargarComentarios(Arbol_Publicacion_id->BuscarElemento(perfil.publicacion_id), cuenta_activa);



    if(cuenta_activa->BuscarRecomendados(DetallePublicacion.publicacion_id) == false){

        cuenta_activa->AgregarRecomendados(Arbol_Publicacion_id->BuscarElemento(DetallePublicacion.publicacion_id));

        time_t ahora = time(0);
        tm* time = localtime(&ahora);

        string fecha = to_string(1900 + time->tm_year) + "-" +  to_string(1 + time->tm_mon) + "-" + to_string(time->tm_mday);

        Arbol_Publicacion_id->BuscarElemento(DetallePublicacion.publicacion_id)->AgregarVisualizacion(fecha);

        ofstream archivo("C:/Users/Gonchis/Documents/Trabajo_final/interaction.tsv", ios::app);

        if(archivo.is_open()){
            archivo << cuenta_activa->getId() << '\t' << DetallePublicacion.publicacion_id << '\t' << fecha << '\t' << "FALSE" << endl;
        }

    }
}

void Login::IrPerfilH(){
    ui->stackedWidget->setCurrentIndex(5);
    perfil.CargarMuro(Arbol_Nombre->BuscarElemento(DetallePublicacion.nombre), cuenta_activa);
    perfil.Relevante(perfil.cuenta_muro);
}

void Login::FiltrarH(){
    switch(pagina_inicio.opcion_filtro){
    case 0: pagina_inicio.EsIgual(Arbol_Titulo); break;
    case 1: pagina_inicio.IniciaCon(Arbol_Titulo); break;
    case 2: pagina_inicio.FinalizaCon(Arbol_Titulo_Final); break;
    case 3: pagina_inicio.Contiene(arreglo_interaccion); break;
    case 4: pagina_inicio.NoContiene(arreglo_interaccion); break;
    }
}

void Login::IrSeguidoresH(){
    ui->stackedWidget->setCurrentIndex(6);
    seguidores.CargarSeguidores(perfil.cuenta_muro, perfil.opcion, Arbol_Id);
}

void Login::RegresarPerfilH(){
    ui->stackedWidget->setCurrentIndex(5);
}

void Login::IrPerfilHH(){
    ui->stackedWidget->setCurrentIndex(5);
    perfil.CargarMuro(Arbol_Nombre->BuscarElemento(seguidores.nombre), cuenta_activa);
    perfil.Relevante(perfil.cuenta_muro);
}

void Login::SeguirCuentaH(){
    ofstream archivo("C:/Users/Gonchis/Documents/Trabajo_final/followers.tsv", ios::app);

    cuenta_activa->AgregarSeguidos(perfil.cuenta_muro->getId());
    perfil.cuenta_muro->AgregarSeguidores(cuenta_activa->getId());

    if(archivo.is_open()){
        archivo << cuenta_activa->getId() << '\t' << perfil.cuenta_muro->getId() << endl;
        archivo.close();
    }
}

void Login::DejarSeguirH(){
    ifstream archivo("C:/Users/Gonchis/Documents/Trabajo_final/followers.tsv", ios::in);
    ofstream nuevo("C:/Users/Gonchis/Documents/Trabajo_final/Nuevo.tsv", ios::app);

    cuenta_activa->EliminarSeguidos(perfil.cuenta_muro);
    perfil.cuenta_muro->EliminarSeguidor(cuenta_activa);

    string linea;
    string atributo;

    if(archivo.is_open() && nuevo.is_open()){

        getline(archivo, linea);

        nuevo << linea << endl;

        while(!archivo.eof()){


            getline(archivo, linea);

            stringstream s(linea);

            if(getline(s, atributo, '\t')){

                if(stoi(atributo) == cuenta_activa->getId()){
                    getline(s, atributo, '\t');

                    if(stoi(atributo) != perfil.cuenta_muro->getId()){
                        nuevo << linea << endl;
                    }
                }
                else{
                    nuevo << linea << endl;
                }
            }
        }

        archivo.close();
        nuevo.close();
    }

    remove("C:/Users/Gonchis/Documents/Trabajo_final/followers.tsv");
    rename("C:/Users/Gonchis/Documents/Trabajo_final/Nuevo.tsv", "C:/Users/Gonchis/Documents/Trabajo_final/followers.tsv");
}

void Login::AgregarLikeH(){
    DetallePublicacion.AgregarLike_(cuenta_activa, Arbol_Publicacion_id);
    Arbol_likes->BorrarArbol();

    for(long i = 0; i < (long)arreglo_interaccion.size(); i++){
        Arbol_likes->AgregarElemento(arreglo_interaccion[i]);
    }
}

void Login::RecomendarPublicacionH(){
    DetallePublicacion.RecomendarPublicacion_(cuenta_activa, Arbol_Publicacion_id);
}

void Login::Mezclar(vector<Publicacion*>& arreglo, long inicio, long final) {
    vector<Publicacion*> aux;
    long mitad = (inicio + final) / 2;
    long IndiceIzquierda = inicio;
    long IndiceDerecha = mitad + 1;

    for (long i = inicio; i <= final; i++) {
        if (IndiceDerecha <= final) {
            if (IndiceIzquierda >= mitad + 1 || arreglo[IndiceIzquierda]->getTotalInteracciones() > arreglo[IndiceDerecha]->getTotalInteracciones()) {

                aux.push_back(arreglo[IndiceDerecha]);
                IndiceDerecha++;
            }
            else {
                aux.push_back(arreglo[IndiceIzquierda]);
                IndiceIzquierda++;
            }
        }
        else {
            aux.push_back(arreglo[IndiceIzquierda]);
            IndiceIzquierda++;
        }
    }
    for (long i = 0; i < (long)aux.size(); i++) {
        arreglo[inicio + i] = aux[i];
    }
}

void Login::Dividir(vector<Publicacion*>& arreglo, long inicio, long final) {
    if (inicio < final) {
        long mitad = (inicio + final) / 2;

        Dividir(arreglo, inicio, mitad);
        Dividir(arreglo, mitad + 1, final);
        Mezclar(arreglo, inicio, final);
    }

}

void Login::OrdenamientoMerge(vector<Publicacion*>& arreglo) {
    Dividir(arreglo, 0, arreglo.size() - 1);
}

void Login::OrdenarRelevantesH(){
    OrdenamientoMerge(arreglo_interaccion);
    pagina_inicio.Relevante(arreglo_interaccion);
}

void Login::OrdenarLikesP(){
    perfil.OrdenarLikes_(perfil.cuenta_muro);
}

void Login::OrdenarPublicacionesRecientesP(){
    perfil.OrdenarPublicaciones_(perfil.cuenta_muro, 0);
}

void Login::OrdenarPublicacionesAntiguasP(){
    perfil.OrdenarPublicaciones_(perfil.cuenta_muro, 1);
}

void Login::OrdenarRelevantesP(){
    perfil.Relevante(perfil.cuenta_muro);
}

void Login::on_bt_cerrar_sesion_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->le_nombre->setFocus();
    ui->bt_Preguntar->setVisible(false);
    ui->bt_Inicio->setVisible(false);
    ui->bt_MiPerfil->setVisible(false);
    ui->lbl_logo_2->setVisible(false);
    ui->bt_cerrar_sesion->setVisible(false);
    QPixmap bkgnd(":/resources/img/fondo.jpg");
    bkgnd = bkgnd.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}
