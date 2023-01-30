<template>
  <pv-card class="mt-3">
    <template #title>
      Perfil
    </template>
    <template #content>
      <div class="flex flex-row">
        <h3>Nombre de usuario:</h3>
        <h3 class="ml-1 font-normal">{{ perfil.name }} </h3>
      </div>
      <div class="flex flex-row">
        <h3>Email:</h3>
        <h3 class="ml-1 font-normal">{{ perfil.email }}</h3>
      </div>
      <div class="flex flex-row">
        <h3>Ruc:</h3>
        <h3 class="ml-1 font-normal">{{ perfil.ruc }}</h3>
      </div>
    </template>
  </pv-card>
</template>

<script>
import { UsuarioApiService } from "../services/usuario-api.service";
import { StorageService } from "../../core/services/storage.service";

export default {
  name: "perfil-view.component",
  data(){
    return{
      usuarioApiService: null,
      storageService: null,
      perfil: {}
    }
  },
  created() {
    this.usuarioApiService  = new UsuarioApiService()
    this.storageService = new StorageService()

    this.usuarioApiService.getById(this.storageService.get("usuario")).then(response => {
      this.perfil = response.data
    })
  }
}
</script>

<style scoped>

</style>