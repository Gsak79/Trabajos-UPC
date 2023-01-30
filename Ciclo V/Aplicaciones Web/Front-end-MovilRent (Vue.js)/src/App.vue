<script>
import { UserApiService } from "./social-med/services/user-api.service";
import { StorageService } from "./core/services/storage.service";

export default {
  data() {
    return {
      usuarioApiService: null,
      storage: null,
      iniciosesion: false,
      loginDialog: false,
      submitted: false,
      submittedLogin: false,
      coincidencia: false,
      incorrecto: false,
      inicioOpcion: "Sign in",
      usuario: "",
      user: {},
      contrasena: "",
      opciones: ["Sign in", "Sign up"],
      items: [
        { label: "Home", to: "/home" },
        { label: "Forums", to: "/forums" },
        { label: "My entries", to: "/entrances" },
        { label: "Report Errors", to: "/report-bugs" },
      ],
    };
  },
  created() {
    this.usuarioApiService = new UserApiService()
    this.storage = new StorageService()

    if(this.storage.get("usuario") >= 1) this.iniciosesion = true
  },
  methods: {
    openDialog(){
      this.incorrecto = false
      this.submittedLogin = false
      this.coincidencia = false
      this.user = {}
      this.submitted = false
      this.loginDialog = true
      this.usuario = ""
      this.contrasena = ""
    },
    iniciarSesion(){
      this.submittedLogin = true
      this.usuarioApiService.getByEmailAndPassword(this.usuario, this.contrasena).then(response =>{
        if(response.data.id === 0){
          this.incorrecto = true
          this.$toast.add({
            severity: "error",
            summary: "Log in error",
            detail: "Email and password do not match",
            life: 3000,
          });
          return;
        }
        else{
          this.$toast.add({
            severity: "success",
            summary: "Logged in",
            life: 3000,
          });
          this.iniciosesion = true
          this.loginDialog = false
          console.log(response.data)
          this.storage.set("usuario", response.data.id)
          this.storage.set("nombre", response.data.name)
        }
      })
    },
    Registrarse(){
      this.submitted = true;
      if(this.user.name || this.user.email || this.user.password || this.user.lastname || this.user.specialist || this.user.workplace || this.user.biography || this.user.image || this.user.age){
        this.user.recommendation = 0
        this.usuarioApiService.create(this.user).then(response => {
          this.storage.set("usuario", response.data.id)
          this.storage.set("nombre", response.data.name)
          this.$toast.add({
            severity: "success",
            summary: "Sign up successfully",
            detail: "Logged in",
            life: 3000,
          });
          this.loginDialog = false
          this.iniciosesion = true
        })
      }
      else{
        this.$toast.add({
          severity: "error",
          summary: "Sign up failed",
          detail: "Put your data correctly",
          life: 3000,
        });
      }
    }
  },

};
</script>

<template>
  <pv-toast />
  <pv-toolbar :style="'backgroundColor: #9CD4E7;'">
    <template #start>
      <img :src="'../media/logo.png'" class="logo" />
    </template>
    <template #end>
      <div v-if="iniciosesion" class="flex-column">
        <router-link
          v-for="item in items"
          :to="item.to"
          custom
          v-slot="{ navigate, href }"
          :key="item.label"
        >
          <pv-button
            :StyleClass="Botones - nav"
            :style="'backgroundColor: #9CD4E7; borderColor: #9CD4E7; margin-right: 0.5rem; color: #000000;'"
            :href="href"
            @click="navigate"
          >{{ item.label }}</pv-button>
        </router-link>
        <router-link
          :to="'/profile/1'"
          style="text-decoration: none"
        >
          <pv-button
            icon="pi pi-user"
            :style="'backgroundColor: #9CD4E7; borderColor: #9CD4E7; margin-right: 0.5rem; color: #000000;'"
            @click="storage.set('profile', parseInt(storage.get('usuario')))"
          ></pv-button>
        </router-link>
        <router-link to="/notifications" style="text-decoration: none">
          <pv-button
            icon="pi pi-bell"
            :style="'backgroundColor: #9CD4E7; borderColor: #9CD4E7; margin-right: 0.5rem; color: #000000;'"
          />
        </router-link>
        <router-link to="/home" style="text-decoration: none">
          <pv-button
            icon="pi pi-sign-out"
            label="Log out"
            @click="iniciosesion = false;
          this.storageService.set('usuario', -1)"
            :style="'backgroundColor: #9CD4E7; borderColor: #9CD4E7; margin-right: 0.5rem; color: #000000;'"
          />
        </router-link>
      </div>
      <div v-else>
        <pv-button
          icon="pi pi-user"
          label="Sign in"
          @click="openDialog"
          :style="'backgroundColor: #9CD4E7; borderColor: #9CD4E7; margin-right: 0.5rem; color: #000000;'"
        />
      </div>
    </template>
  </pv-toolbar>
  <pv-dialog
    v-model:visible="loginDialog"
    :style="{ width: '600px' }"
    :modal="true"
    class="p-fluid"
  >
    <pv-select-button class="mt-1 w-full" v-model="inicioOpcion" :options="opciones" />
    <div v-if="inicioOpcion === 'Sign in'" class="w-full">
      <pv-card class="mt-3 surface-card p-4 shadow-2 border-round w-full">
        <template #content>
          <div class="text-center mb-5">
            <div class="text-900 text-3xl font-medium mb-3">Sign in</div>
          </div>

          <div>
            <label for="email1" class="block text-900 font-medium mb-2">Email</label>
            <pv-input-text id="email1" type="text" v-model="usuario" class="w-full mb-3" :class="{ 'p-invalid': submittedLogin && incorrecto }"/>

            <label for="password1" class="block text-900 font-medium mb-2">Password</label>
            <pv-input-text id="password1" type="password" v-model="contrasena" class="w-full mb-3" :class="{ 'p-invalid': submittedLogin && incorrecto }" />
            <small class="p-error" v-if="submittedLogin && incorrecto"
            >The email or password are incorrect</small>
            <pv-button label="Sign in " @click="iniciarSesion" class="mt-3 w-full"></pv-button>
          </div>
        </template>
      </pv-card>
    </div>
    <div v-else class="w-full">
      <pv-card class="mt-3 surface-card p-4 shadow-2 border-round w-full">
        <template #content>
          <div class="text-center mb-5">
            <div class="text-900 text-3xl font-medium mb-3">Sign up</div>
          </div>

          <div>
            <label class="block text-900 font-medium mb-2 mt-3">Email</label>
            <pv-input-text v-model="user.email" type="text" class="w-full" :class="{ 'p-invalid': submitted && !user.email || submitted && coincidencia }"/>
            <small class="p-error" v-if="submitted && !user.email"
            >Email is required</small>
            <small class="p-error" v-if="submitted && coincidencia"
            >Email already exists</small>

            <label class="block text-900 font-medium mb-2 mt-3">Password</label>
            <pv-input-text v-model="user.password" type="password" class="w-full" :class="{ 'p-invalid': submitted && !user.password }"/>
            <small class="p-error" v-if="submitted && !user.password"
            >Password is required</small>

            <label class="block text-900 font-medium mb-2 mt-3">Name</label>
            <pv-input-text v-model="user.name" type="text" class="w-full" :class="{ 'p-invalid': submitted && !user.name }"/>
            <small class="p-error" v-if="submitted && !user.name"
            >Name is required</small>

            <label  class="block text-900 font-medium mb-2 mt-3">Lastname</label>
            <pv-input-text v-model="user.lastName" type="text" class="w-full" :class="{ 'p-invalid': submitted && !user.lastName }"/>
            <small class="p-error" v-if="submitted && !user.lastName"
            >Lastname is required</small>

            <label  class="block text-900 font-medium mb-2 mt-3">Age</label>
            <pv-input-number v-model="user.age" class="w-full" :class="{ 'p-invalid': submitted && !user.age }"/>
            <small class="p-error" v-if="submitted && !user.age"
            >Age is required</small>

            <label  class="block text-900 font-medium mb-2 mt-3">Specialist</label>
            <pv-input-text v-model="user.specialist" type="text" class="w-full" :class="{ 'p-invalid': submitted && !user.specialist }"/>
            <small class="p-error" v-if="submitted && !user.specialist"
            >Specialist is required</small>

            <label  class="block text-900 font-medium mb-2 mt-3">Work place</label>
            <pv-input-text v-model="user.workPlace" type="text" class="w-full" :class="{ 'p-invalid': submitted && !user.workPlace }"/>
            <small class="p-error" v-if="submitted && !user.workPlace"
            >Work place is required</small>

            <label  class="block text-900 font-medium mb-2 mt-3">Image</label>
            <pv-input-text v-model="user.image" type="text" class="w-full" :class="{ 'p-invalid': submitted && !user.image }"/>
            <small class="p-error" v-if="submitted && !user.image"
            >Image is required</small>

            <label  class="block text-900 font-medium mb-2 mt-3">Biography</label>
            <pv-textarea :autoResize="true"
                         rows="2"
                         cols="100" v-model="user.biography" type="text" class="w-full" :class="{ 'p-invalid': submitted && !user.biography }"/>
            <small class="p-error" v-if="submitted && !user.biography"
            >Biography is required</small>

            <pv-button label="Sign up" @click="Registrarse" class="mt-3 w-full"></pv-button>
          </div>
        </template>
      </pv-card>
    </div>
  </pv-dialog>

  <RouterView />
</template>

<style>
.logo {
  width: 10rem;
  height: 3.5rem;
}

.p-input-icon-left {
  margin-left: 2rem;
}
</style>