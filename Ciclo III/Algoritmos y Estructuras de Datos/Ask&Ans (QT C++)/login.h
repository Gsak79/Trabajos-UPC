#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <registrarse.h>
#include <fstream>
#include <string>
#include <sstream>
#include <Cuenta.h>
#include <Arbol_busqueda.h>
#include <pagina_incio.h>
#include <QMessageBox>
#include <functional>
#include <ctime>
#include <detalle_publicacion.h>
#include <publicar.h>
#include <perfil.h>
#include <Lista.h>
#include <seguidores.h>
#include <stdio.h>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_bt_IrRegistrar_clicked();
    void IniciarSesionH();
    void CargarDatos();
    bool UsuariosIgualesH();
    void RegistrarH();
    void on_bt_IniciarSesion_clicked();
    void OrdenarLikesH();
    void OrdenarPublicacionesRecientesH();
    void OrdenarPublicacionesAntiguasH();
    void DetallarPublicacionH();
    void EnviarComentarioH();
    void PublicarPublicacionH();
    void on_bt_Inicio_clicked();
    void DetallarPublicacionHH();
    void on_bt_Preguntar_clicked();
    void IrPerfilH();
    void IrPerfilHH();
    void on_bt_MiPerfil_clicked();
    void FiltrarH();
    void IrSeguidoresH();
    void RegresarPerfilH();
    void SeguirCuentaH();
    void DejarSeguirH();
    void AgregarLikeH();
    void RecomendarPublicacionH();
    void Mezclar(vector<Publicacion*>& arreglo, long inicio, long final);
    void Dividir(vector<Publicacion*>& arreglo, long inicio, long final);
    void OrdenamientoMerge(vector<Publicacion*>& arreglo);
    void OrdenarRelevantesH();
    void CargarUsuarios();
    void CargarPublicaciones();
    void CargarInteracciones();
    void CargarLikes();
    void CargarComentarios();
    void CargarFollowers();
    void OrdenarLikesP();
    void OrdenarPublicacionesRecientesP();
    void OrdenarPublicacionesAntiguasP();
    void OrdenarRelevantesP();


    void on_bt_cerrar_sesion_clicked();

private:
    Ui::Login *ui;
    Registrarse registrarse;
    Pagina_incio pagina_inicio;
    detalle_publicacion DetallePublicacion;
    Cuenta* cuenta_activa;
    Publicar publicar;
    Perfil perfil;
    Seguidores seguidores;
    Lista<Publicacion*>* lista_publicaciones;
    Arbol_busqueda<Cuenta*, string>* Arbol_Nombre;
    Arbol_busqueda<Cuenta*, string>* Arbol_Email;
    Arbol_busqueda<Cuenta*, int>* Arbol_Id;
    Arbol_busqueda<Publicacion*, int>* Arbol_likes;
    Arbol_busqueda<Publicacion*, string>* Arbol_fechaPublicacion;
    Arbol_busqueda<Publicacion*, int>* Arbol_Publicacion_id;
    Arbol_busqueda<Publicacion*, string>* Arbol_Titulo;
    Arbol_busqueda<Publicacion*, string>* Arbol_Titulo_Final;
    vector<Publicacion*> arreglo_interaccion;
};
#endif // LOGIN_H
