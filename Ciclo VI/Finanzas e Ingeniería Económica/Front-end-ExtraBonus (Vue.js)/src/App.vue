<script>
import { UsuarioApiService } from "./extrabonus/services/usuario-api.service";
import { StorageService } from "./core/services/storage.service";

export default {
  data() {
    return {
      usuarioApiService: null,
      storageService: null,
      drawer: false,
      submitted: false,
      submittedLogin: false,
      iniciosesion: false,
      loginDialog: false,
      coincidencia: false,
      incorrecto: false,
      usuario: "",
      user: {},
      contrasena: "",
      inicioOpcion: "Iniciar sesión",
      opciones: ["Iniciar sesión", "Registrarse"],
    };
  },
  created() {
    this.usuarioApiService = new UsuarioApiService();
    this.storageService = new StorageService();

    if(this.storageService.get("usuario") < 0 || this.storageService.get("usuario") === null) this.iniciosesion = false
    else this.iniciosesion = true

  },
  methods: {
    openDialog(){
      this.incorrecto = false
      this.submittedLogin = false
      this.coincidencia = false
      this.user = {}
      this.submitted = false
      this.drawer = false
      this.loginDialog = true
      this.usuario = ""
      this.contrasena = ""
    },
    iniciarSesion(){
      this.submittedLogin = true
      this.usuarioApiService.getByUsernameAndPassword(this.usuario, this.contrasena).then(response =>{
        if(response.data.length === 0){
          this.incorrecto = true
          this.$toast.add({
            severity: "error",
            summary: "Inicio de sesión fallido",
            detail: "El correo electrónico y/o la contraseña ingresada no son correctos",
            life: 3000,
          });
        }
        else{
          this.$toast.add({
            severity: "success",
            summary: "Sesión iniciada correctamente",
            life: 3000,
          });
          this.iniciosesion = true
          this.loginDialog = false
          console.log(response.data)
          this.storageService.set("usuario", response.data.id)
          this.storageService.set("nombre", response.data.name)
        }
      })
    },
    Registrarse(){
      this.submitted = true;
      if(this.user.name || this.user.email || this.user.password || this.user.ruc){
        this.usuarioApiService.create(this.user).then(response => {
          this.storageService.set("usuario", response.data.id)
          this.storageService.set("nombre", response.data.name)
          this.$toast.add({
            severity: "success",
            summary: "Registrado correctamente",
            detail: "Sesión iniciada",
            life: 3000,
          });
          this.loginDialog = false
          this.iniciosesion = true
        })
      }
      else{
        this.$toast.add({
          severity: "error",
          summary: "Registro fallido",
          detail: "Ingrese todos los datos correctamente",
          life: 3000,
        });
      }
    }
  },
};
</script>

<template>
  <pv-toast />
  <pv-toolbar class="bg-primary">
    <template #start>
      <pv-button icon="pi pi-bars" @click="drawer = !drawer"></pv-button>
      <h3 class="text-white font-medium">Extra  Bonus</h3>
    </template>
    <template #end>
      <i v-if="inicioSesion" class="pi pi-user"></i>
      <router-link
        v-if="iniciosesion"
        :to="{ name: 'perfil' }"
        style="text-decoration: None"
      >
        <pv-button icon="pi pi-user" iconPos="right" label="a">{{storageService.get('nombre').replace(/['"]+/g, '')}}</pv-button>
      </router-link>
      <pv-button
        v-else
        icon="pi pi-sign-in"
        @click="openDialog"
        label="Iniciar sesión"
      ></pv-button>
    </template>
  </pv-toolbar>

  <pv-dialog
    v-model:visible="loginDialog"
    :style="{ width: '600px' }"
    :modal="true"
    class="p-fluid"
  >
    <pv-select-button class="mt-1 w-full" v-model="inicioOpcion" :options="opciones" />
    <div v-if="inicioOpcion === 'Iniciar sesión'" class="w-full">
      <pv-card class="mt-3 surface-card p-4 shadow-2 border-round w-full">
        <template #content>
        <div class="text-center mb-5">
          <div class="text-900 text-3xl font-medium mb-3">Iniciar sesión</div>
        </div>

        <div>
          <label for="email1" class="block text-900 font-medium mb-2">Correo electrónico</label>
          <pv-input-text id="email1" type="text" v-model="usuario" class="w-full mb-3" :class="{ 'p-invalid': submittedLogin && incorrecto }"/>

          <label for="password1" class="block text-900 font-medium mb-2">Contraseña</label>
          <pv-input-text id="password1" type="password" v-model="contrasena" class="w-full mb-3" :class="{ 'p-invalid': submittedLogin && incorrecto }" />
          <small class="p-error" v-if="submittedLogin && incorrecto"
          >El nombre de usuario y/o la contraseña ingresada no son correctos</small>
          <pv-button label="Iniciar sesión" @click="iniciarSesion" class="mt-3 w-full"></pv-button>
        </div>
        </template>
      </pv-card>
    </div>
    <div v-else class="w-full">
      <pv-card class="mt-3 surface-card p-4 shadow-2 border-round w-full">
        <template #content>
          <div class="text-center mb-5">
            <div class="text-900 text-3xl font-medium mb-3">Registrarse</div>
          </div>

          <div>
            <label class="block text-900 font-medium mb-2 mt-3">Correo electrónico</label>
            <pv-input-text v-model="user.email" type="text" class="w-full" :class="{ 'p-invalid': submitted && !user.name || submitted && coincidencia }"/>
            <small class="p-error" v-if="submitted && !user.email"
            >Ingrese un correo electrónico</small>
            <small class="p-error" v-if="submitted && coincidencia"
            >El correo electrónico ingresado ya existe</small>

            <label class="block text-900 font-medium mb-2 mt-3">Contraseña</label>
            <pv-input-text v-model="user.password" type="password" class="w-full" :class="{ 'p-invalid': submitted && !user.password }"/>
            <small class="p-error" v-if="submitted && !user.password"
            >Ingrese una contraseña</small>

            <label class="block text-900 font-medium mb-2 mt-3">Nombre de usuario</label>
            <pv-input-text v-model="user.name" type="text" class="w-full" :class="{ 'p-invalid': submitted && !user.email }"/>
            <small class="p-error" v-if="submitted && !user.name"
            >Ingrese un nombre de usuario</small>

            <label  class="block text-900 font-medium mb-2 mt-3">RUC</label>
            <pv-input-text v-model="user.ruc" type="text" class="w-full" :class="{ 'p-invalid': submitted && !user.ruc }"/>
            <small class="p-error" v-if="submitted && !user.ruc"
            >Ingrese un RUC</small>

            <pv-button label="Registrarse" @click="Registrarse" class="mt-3 w-full"></pv-button>
          </div>
        </template>
      </pv-card>
    </div>
  </pv-dialog>

  <pv-sidebar v-if="iniciosesion" v-model:visible="drawer" class="p-sidebar-sm">
    <h3>Menú</h3>
    <div>
      <router-link :to="{ name: 'crear-bono' }" style="text-decoration: None">
        <pv-button
          class="p-button-text"
          icon="pi pi-plus-circle"
          iconPos="left"
          label="Crear bono"
          @click="drawer = false"
        />
      </router-link>
    </div>
    <div>
      <router-link :to="{ name: 'historial' }" style="text-decoration: None">
        <pv-button
          class="p-button-text"
          icon="pi pi-history"
          iconPos="left"
          label="Historial"
          @click="drawer = false"
        />
      </router-link>
    </div>
    <pv-divider />
    <div>
      <router-link
        :to="{ name: 'configuracion' }"
        style="text-decoration: None"
      >
        <pv-button
          class="p-button-text"
          icon="pi pi-cog"
          iconPos="left"
          label="Configuración"
          @click="drawer = false"
        />
      </router-link>
    </div>
    <div>
      <router-link
          :to="{ name: 'home' }"
          style="text-decoration: None"
      >
      <pv-button
        class="p-button-text"
        icon="pi pi-sign-out"
        iconPos="left"
        label="Cerrar sesión"
        @click="
          drawer = false;
          iniciosesion = false;
          this.storageService.set('usuario', -1)
        "
      />
      </router-link>
    </div>
  </pv-sidebar>
  <pv-sidebar v-else v-model:visible="drawer" class="p-sidebar-sm">
    <h3>Inicia sesión para acceder a Extra Bonus</h3>
    <div>
      <pv-button
        class="p-button-text"
        icon="pi pi-sign-in"
        iconPos="left"
        label="Iniciar sesión"
        @click="this.incorrecto = false;
        this.submittedLogin = false;
        this.coincidencia = false;
        this.user = {};
        this.submitted = false;
        this.drawer = false;
        this.loginDialog = true;
        this.usuario = '';
        this.contrasena = '';"

      />
    </div>
  </pv-sidebar>
  <RouterView />
</template>