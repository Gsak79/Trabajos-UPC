<template>
  <pv-card class="mt-3">
    <template #title>
      Historial
    </template>
    <template #content>
      <pv-datatable
          ref="dt"
          :value="bonos"
          dataKey="id"
          responsiveLayout="scroll"
      >
        <template #empty>
          No ha creado ningún bono
        </template>
        <pv-column
            field="id"
            header="N° Bono"
        ></pv-column>
        <pv-column
            field="nominal"
            header="Valor nominal"
        ></pv-column>
        <pv-column
            field="comercial"
            header="Valor comercial"
        ></pv-column>
        <pv-column
            field="anos"
            header="Años"
        ></pv-column>
        <pv-column
            field="interes"
            header="Tasa de interes"
        ></pv-column>
        <pv-column
            field="descuento"
            header="Tasa de descuento"
        ></pv-column>
        <pv-column
            field="fecha"
            header="Fecha"
        ></pv-column>

        <pv-column>
          <template #body="slotProps">
            <router-link
                :to="{ name: 'resultado', params: slotProps.data }"
                style="text-decoration: none"
            >
              <pv-button
                  label="Ver resultados"
                  class="p-button-outlined"
                  @click="resultados(slotProps.data.id)"
              ></pv-button>
            </router-link>
          </template>
        </pv-column>
      </pv-datatable>
    </template>
  </pv-card>
</template>

<script>
import {BonoApiService} from "../services/bono-api.service";
import {StorageService} from "../../core/services/storage.service";

export default {
  name: "historial-view.component",
  data() {
    return {
      bonoApiService: null,
      storageService: null,
      bonos: []
    }
  },
  created() {
    this.bonoApiService = new BonoApiService()
    this.storageService = new StorageService()

    this.bonoApiService.getByUserId(this.storageService.get("usuario")).then(response => {
      this.bonos = response.data
    })
  },
  methods: {
    resultados(id) {
      this.storageService.set("bono", id)
    }
  }
}
</script>

<style scoped>

</style>