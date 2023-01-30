<template>
  <pv-toast />
  <pv-card class="mt-3">
    <template #title>
      Configuración
    </template>
    <template #content>
      <h4>Método de pago:</h4>
      <div class="field-radiobutton">
        <pv-radio-button
          id="americano"
          name="metodo"
          value="americano"
          v-model="this.configuration.method"
        />
        <label for="americano">Americano</label>
      </div>
      <div class="field-radiobutton">
        <pv-radio-button
          id="frances"
          name="metodo"
          value="frances"
          v-model="this.configuration.method"
        />
        <label for="frances">Francés</label>
      </div>
      <div class="field-radiobutton">
        <pv-radio-button
          id="aleman"
          name="metodo"
          value="aleman"
          v-model="this.configuration.method"
        />
        <label for="aleman">Alemán</label>
      </div>

      <h4>Tasa de descuento:</h4>
      <div class="field-radiobutton">
        <pv-radio-button
          id="nominal"
          name="tasa"
          value="nominal"
          v-model="this.configuration.rate"
        />
        <label for="nominal">Nominal</label>
      </div>
      <div class="field-radiobutton">
        <pv-radio-button
          id="efectiva"
          name="tasa"
          value="efectiva"
          v-model="this.configuration.rate"
        />
        <label for="efectiva">Efectiva</label>
      </div>

      <h4>Moneda:</h4>
      <div class="field-radiobutton">
        <pv-radio-button
          id="soles"
          name="moneda"
          value="soles"
          v-model="this.configuration.currency"
        />
        <label for="soles">Soles peruanos (PEN)</label>
      </div>
      <div class="field-radiobutton">
        <pv-radio-button
          id="dolares"
          name="moneda"
          value="dolares"
          v-model="this.configuration.currency"
        />
        <label for="dolares">Dólares estadounidenses (USD)</label>
      </div>
      <div class="flex justify-content-center">
        <pv-button class="flex align-items-center justify-content-center mt-3" @click="updateConfiguration">Guardar cambios</pv-button>
      </div>
    </template>
  </pv-card>
</template>

<script>
import { ConfiguracionApiService } from "../services/configuracion-api.service"

export default {
  name: "configuracion-view.component",
  data() {
    return {
      configurationApiService: null,
      configuration: {},
    };
  },
  created() {
    this.configurationApiService = new ConfiguracionApiService();
    this.configurationApiService.getByUserId(1).then( response =>{
      this.configuration.method = response.data[0].method
      this.configuration.rate = response.data[0].rate
      this.configuration.currency = response.data[0].currency
    })
  },
  methods: {
    updateConfiguration() {
      this.configuration.id = 1;
      this.configuration.userId = 1;
      this.configurationApiService.update(1, this.configuration).then(p => {
        this.$toast.add({
          severity: "success",
          summary: "Configuración guardada",
          life: 3000,
        });
      })

    }
  }
};
</script>

<style scoped></style>
