<template>
  <pv-card class="mt-3">
    <template #title>
      Resultados de la estructuración del bono
    </template>
    <template #content>
      <div class="flex flex-row">
        <h3>Frecuencia del cupón:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.frecuencia }} días</h3>
      </div>
      <div class="flex flex-row">
        <h3>Días capitalización: </h3>
        <h3 class="ml-1 font-normal">{{ resultado.capitalizacion }} días</h3>
      </div>
      <div class="flex flex-row">
        <h3>Número de periodos por año: </h3>
        <h3 class="ml-1 font-normal">{{ resultado.periodo }} </h3>
      </div>
      <div class="flex flex-row">
        <h3>Total periodos: </h3>
        <h3 class="ml-1 font-normal">{{ resultado.totalPeriodo }} </h3>
      </div>
      <div class="flex flex-row">
        <h3>Tasa efectiva anual:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.efectivaAnual }} </h3>
      </div>
      <div class="flex flex-row">
        <h3>Tasa efectiva {{ this.frecuencia }}:</h3>
        <h3 class="ml-1 font-normal">{{resultado.efectiva }} </h3>
      </div>
      <div class="flex flex-row">
        <h3>COK {{ this.frecuencia }}:</h3>
        <h3 class="ml-1 font-normal">{{resultado.cok }} </h3>
      </div>
      <div class="flex flex-row">
        <h3>Costos/gastos iniciales del emisor:</h3>
        <h3 class="ml-1 font-normal"> {{ resultado.costoEmisor }} </h3>
      </div>
      <div class="flex flex-row">
        <h3>Costos/gastos iniciales del inversor:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.costoInversor }} </h3>
      </div>
    </template>
  </pv-card>
  <pv-card class="mt-3">
    <template #title>
      Resultados del precio actual y utilidad
    </template>
    <template #content>
      <div class="flex flex-row">
        <h3>Precio actual:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.precio }} </h3>
      </div>
      <div class="flex flex-row">
        <h3>Utilidad / Pérdida:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.utilidad }} </h3>
      </div>
    </template>
  </pv-card>
  <pv-card class="mt-3">
    <template #title>
      Ratios de decisión
    </template>
    <template #content>
      <div class="flex flex-row">
        <h3>Duración:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.duracion }} </h3>
      </div>
      <div class="flex flex-row">
        <h3>Convexidad:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.convexidad }}</h3>
      </div>
      <div class="flex flex-row">
        <h3>Total:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.total }}</h3>
      </div>
      <div class="flex flex-row">
        <h3>Duración modificada:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.duracionModif }}</h3>
      </div>
    </template>
  </pv-card>
  <pv-card class="mt-3">
    <template #title>
      Resultados de los indicadores de rentabilidad
    </template>
    <template #content>
      <div class="flex flex-row">
        <h3>TCEA Emisor:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.tceAemisor }} </h3>
      </div>
      <div class="flex flex-row">
        <h3>TCEA Emisor con escudo:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.tceAemisorEscudo }}</h3>
      </div>
      <div class="flex flex-row">
        <h3>TREA Bonista:</h3>
        <h3 class="ml-1 font-normal">{{ resultado.treAbonista }}</h3>
      </div>
    </template>
  </pv-card>
  <pv-card class="mt-3">
    <template #title>
      Cuotas
    </template>
    <template #content>
      <pv-datatable
          ref="dt"
          :value="cuotas"
          dataKey="id"
          responsiveLayout="scroll"
          sortField="numero"
          :sortOrder="1"
          editMode="cell"
      >
        <pv-column
            field="numero"
            header="N°"
        ></pv-column>
        <pv-column
            field="inflacion"
            header="Inflación anual"
        >
          <template #editor="slotProps">
            <pv-input-number  v-model="cuotas[slotProps.data.numero].inflacion" suffix="%" autofocus />
          </template>
        </pv-column>
        <pv-column
            field="bono"
            header="Bono"
        ></pv-column>
        <pv-column
            field="indexado"
            header="Bono indexado"
        ></pv-column>
        <pv-column
            field="cupon"
            header="Cupón (Interés)"
        ></pv-column>
        <pv-column
            field="amortizacion"
            header="Amort."
        ></pv-column>
        <pv-column
            field="prima"
            header="Prima"
        ></pv-column>
        <pv-column
            field="escudo"
            header="Escudo"
        ></pv-column>
        <pv-column
            field="emisor"
            header="Flujo Emisor"
        ></pv-column>
        <pv-column
            field="emisorEscudo"
            header="Flujo Emisor c/Escudo"
        ></pv-column>
        <pv-column
            field="bonista"
            header="Flujo Bonista"
        ></pv-column>
        <pv-column
            field="activo"
            header="Flujo Act."
        ></pv-column>
        <pv-column
            field="plazo"
            header="FA x Plazo"
        ></pv-column>
        <pv-column
            field="convexidad"
            header="Factor p/Convexidad"
        ></pv-column>
      </pv-datatable>
    </template>
  </pv-card>

</template>

<script>
import {ResultadoApiService} from "../services/resultado-api.service";
import {StorageService} from "../../core/services/storage.service";
import { CuotaApiService } from "../services/cuota-api.service";
import { BonoApiService } from "../services/bono-api.service";

export default {
  name: "resultado-view.component",
  data(){
    return{
      storageApiService: null,
      resultadoApiService: null,
      cuotaApiService: null,
      bonoApiService: null,
      resultado: {},
      bono: {},
      cuotas: [],
      frecuencia: "",
    }
  },
  created() {
    this.storageService = new StorageService()
    this.resultadoApiService = new ResultadoApiService()
    this.cuotaApiService = new CuotaApiService()
    this.bonoApiService = new BonoApiService()
    console.log(parseInt(this.storageService.get("bono")))

    this.resultadoApiService.getByBondId(this.storageService.get("bono")).then( response =>{
      this.resultado = response.data[0]
      switch (response.data[0].frecuencia){
        case 30: this.frecuencia = "mensual"; break;
        case 60: this.frecuencia = "bimestral"; break;
        case 90: this.frecuencia = "trimestral"; break;
        case 120: this.frecuencia = "cuatrimestral"; break;
        case 180: this.frecuencia = "semestral"; break;
        case 360: this.frecuencia = "anual"; break;
      }
    })

    this.bonoApiService.getById(this.storageService.get("bono")).then( response => {
      this.bono = response.data[0]
    })

    this.cuotaApiService.getByBondId(this.storageService.get("bono")).then( response => {
      this.cuotas = response.data
    })

  }
}
</script>

<style scoped>

</style>