<template>
  <pv-toast />
  <pv-card class="mt-3">
    <template #title>
      Datos del bono
    </template>
    <template #content>
      <div class="flex flex-row align-items-center justify-content-center">
        <h4 class="flex">Valor nominal:</h4>
        <pv-input-number class="flex ml-2" v-model="bono.nominal"></pv-input-number>
        <h4 class="flex ml-2">Valor comercial:</h4>
        <pv-input-number class="flex ml-2" v-model="bono.comercial"></pv-input-number>
        <h4 class="flex ml-2">Número de años:</h4>
        <pv-input-number class="flex ml-2" v-model="bono.anos"></pv-input-number>
      </div>
      <div class="flex flex-row align-items-center justify-content-center">
        <h4 class="flex">Frecuencia del cupón:</h4>
        <pv-dropdown class="p-dropdown flex w-12rem ml-2" :options="frecuencias" optionLabel="name" optionValue="code" v-model="bono.frecuencia"></pv-dropdown>
        <h4 class="flex ml-2 ">Días por año:</h4>
        <pv-dropdown class="flex w-12rem ml-2" :options="dias" optionLabel="name" optionValue="code" v-model="bono.dias"></pv-dropdown>
        <h4 class="flex ml-2">Tipo de tasa de interes:</h4>
        <pv-dropdown class="flex w-12rem ml-2" :options="tasas" optionLabel="name" optionValue="code" v-model="bono.tasa"></pv-dropdown>
      </div>
      <div class="flex flex-row align-items-center justify-content-center">
        <h4 class="flex">Capitalización:</h4>
        <pv-dropdown class="p-dropdown flex w-12rem ml-2" :options="capitalizaciones" optionLabel="name" optionValue="code" v-model="bono.capitalizacion"></pv-dropdown>
        <h4 class="flex ml-2 ">Tasa de interés anual:</h4>
        <pv-input-number class="flex ml-2" v-model="bono.interes" mode="decimal" suffix="%"></pv-input-number>
        <h4 class="flex ml-2">Tasa anual de descuento:</h4>
        <pv-input-number class="flex ml-2" v-model="bono.descuento" mode="decimal" suffix="%"></pv-input-number>
      </div>
      <div class="flex flex-row align-items-center justify-content-center">
        <h4 class="flex">Impuesto a la renta:</h4>
        <pv-input-number class="flex ml-2" v-model="bono.renta" mode="decimal" suffix="%"></pv-input-number>
        <h4 class="flex ml-2 ">Fecha de emisión:</h4>
        <pv-calendar class="flex ml-2" v-model="bono.fecha" dateFormat="dd/mm/yy" :showIcon="true" />
      </div>
    </template>
  </pv-card>

  <pv-card class="mt-3">
    <template #title>
      Datos de los costos/gastos iniciales
    </template>
    <template #content>
      <div class="flex flex-row align-items-center justify-content-center">
        <h4 class="flex ml-2">% Prima:</h4>
        <pv-input-number class="flex ml-2" v-model="bono.prima" mode="decimal" suffix="%"></pv-input-number>
      </div>
      <div class="flex flex-row align-items-center justify-content-center">
        <h4 class="flex ml-2 ">% Estructuracion:</h4>
        <pv-input-number class="flex ml-2" v-model="bono.estructuracion" mode="decimal" suffix="%"></pv-input-number>
      </div>
      <div class="flex flex-row align-items-center justify-content-center">
        <h4 class="flex ml-2 ">% Colocación:</h4>
        <pv-input-number class="flex ml-2" v-model="bono.colocacion" mode="decimal" suffix="%"></pv-input-number>
      </div>
      <div class="flex flex-row align-items-center justify-content-center">
        <h4 class="flex ml-2 ">% Flotación:</h4>
        <pv-input-number class="flex ml-2" v-model="bono.flotacion" mode="decimal" suffix="%"></pv-input-number>
      </div>
      <div class="flex flex-row align-items-center justify-content-center">
        <h4 class="flex ml-2 ">% CAVALI:</h4>
        <pv-input-number class="flex ml-2" v-model="bono.cavali" mode="decimal" suffix="%"></pv-input-number>
      </div>
    </template>
    <template #footer>
      <div class="flex justify-content-center">
        <router-link :to="{ name: 'resultado', params: { id: this.storageService.get('bono') } }" style="text-decoration: none">
          <pv-button class="flex justify-content-center w-8rem" @click="addBono">Crear bono</pv-button>
        </router-link>
      </div>
    </template>
  </pv-card>
</template>

<script>
import { BonoApiService } from "../services/bono-api.service"
import { ResultadoApiService } from "../services/resultado-api.service";
import { StorageService } from "../../core/services/storage.service";
import { CuotaApiService } from "../services/cuota-api.service";
import { irr } from "node-irr";

export default {
  name: "crear-bono.component",
  data(){
    return{
      bonoApiService: null,
      resultadoApiService: null,
      cuotaApiService: null,
      storageService: null,
      bono: {},
      resultado: {},
      cuota: {},
      frecuencias: [
        { name: "Mensual", code: 30},
        { name: "Bimestral", code: 60},
        { name: "Trimestral", code: 90 },
        { name: "Cuatrimestral", code: 120 },
        { name: "Semestral", code: 180 },
        { name: "Anual", code: 360 }
      ],
      dias: [
        { name: "Año ordinario (360 días)", code: 360},
        { name: "Año exacto (365 días)", code: 365}
      ],
      tasas: [
        { name: "Nominal", code: "nominal"},
        { name: "Efectiva", code: "efectiva"}
      ],
      capitalizaciones: [
        { name: "Diaria", code: 1},
        { name: "Quincenal", code: 15},
        { name: "Mensual", code: 30},
        { name: "Bimestral", code: 60},
        { name: "Trimestral", code: 90 },
        { name: "Cuatrimestral", code: 120 },
        { name: "Semestral", code: 180 },
        { name: "Anual", code: 360 }
      ],
    }
  },
  created() {
    this.bonoApiService = new BonoApiService();
    this.resultadoApiService = new ResultadoApiService();
    this.cuotaApiService = new CuotaApiService();
    this.storageService = new StorageService();
    this.storageService.set("bono", 1);

    this.bonoApiService.getAll().then(response => {
      this.storageService.set("bono", response.data.pop().id + 1)
    })
  },
  methods: {
    van(tasa, arreglo){
      let resultado = 0
      for(var i = 1; i <= arreglo.length; i++ ){
        resultado += (arreglo[i - 1])/(Math.pow(1 + tasa, i))
      }
      return resultado
    },
    tir(arreglo){
      let minimo = 0.0;
      let correcto = false
      let maximo = 1.0;
      let vna;
      let supuesto = (minimo + maximo) / 2
      let anteriorVna = this.van(supuesto, arreglo)
      do{
        supuesto = (minimo + maximo) / 2;
        vna = this.van(supuesto, arreglo)
        if(correcto === false){
          if (vna > 0) maximo = supuesto;
          else minimo = supuesto;
          if (Math.abs(anteriorVna) < Math.abs(vna)) {
            correcto = true
            minimo = 0
            maximo = 1
          }
        }
        else{
          if (vna < 0) maximo = supuesto;
          else minimo = supuesto;
        }
      } while(Math.abs(vna) > 0.00001);
      return supuesto;
    },
    addBono() {
      this.bono.userId = parseInt(this.storageService.get("usuario"))
      this.bonoApiService.create(this.bono).then(response => {
        this.resultado.bondId = parseInt(this.storageService.get("bono"))
        if (this.bono.frecuencia === 360) this.resultado.frecuencia = this.bono.dias
        else this.resultado.frecuencia = this.bono.frecuencia

        if (this.bono.capitalizacion === 360) this.resultado.capitalizacion = this.bono.dias
        else this.resultado.capitalizacion = this.bono.capitalizacion

        this.resultado.periodo = this.bono.dias / this.resultado.frecuencia
        this.resultado.totalPeriodo = this.resultado.periodo * this.bono.anos

        if (this.bono.tasa === "efectiva") this.resultado.efectivaAnual = this.bono.interes
        else this.resultado.efectivaAnual = (Math.pow(1 + this.bono.interes / 100 / (this.bono.dias / this.resultado.capitalizacion), this.bono.dias / this.resultado.capitalizacion) - 1) * 100

        this.resultado.efectiva = (Math.pow(1 + this.resultado.efectivaAnual / 100, this.resultado.frecuencia / this.bono.dias) - 1) * 100
        this.resultado.cok = (Math.pow(1 + this.bono.descuento / 100, this.resultado.frecuencia / this.bono.dias) - 1) * 100

        this.resultado.costoEmisor = ((this.bono.estructuracion + this.bono.cavali + this.bono.colocacion + this.bono.flotacion) / 100) * this.bono.comercial
        this.resultado.costoInversor = ((this.bono.cavali + this.bono.flotacion) / 100) * this.bono.comercial

        let sumaPlazo = 0
        let sumaActivo = 0
        let sumaConvexidad = 0
        let emisor = []
        let bonista = []
        let emisorEscudo = []

        for (var i = 0; i <= this.resultado.totalPeriodo; i++) {
          this.cuota.bondId = parseInt(this.storageService.get("bono"));
          this.cuota.numero = i;

          if (this.cuota.numero !== 0) {

            this.cuota.inflacion = 0
            this.cuota.inflacionPeriodo = 0

            if (this.cuota.numero === 1) this.cuota.bono = this.bono.nominal
            else this.cuota.bono = this.cuota.indexado

            this.cuota.indexado = this.cuota.bono * (1 + this.cuota.inflacionPeriodo)
            this.cuota.cupon = -1 * this.cuota.indexado * (this.resultado.efectiva / 100)

            if (this.cuota.numero === this.resultado.totalPeriodo) {
              this.cuota.prima = -1 * (this.bono.prima / 100) * this.cuota.indexado
              this.cuota.amortizacion = -1 * this.cuota.indexado
            } else {
              this.cuota.prima = 0
              this.cuota.amortizacion = 0
            }

            this.cuota.escudo = -1 * this.cuota.cupon * (this.bono.renta / 100)

            if (this.cuota.numero < this.resultado.totalPeriodo) this.cuota.emisor = this.cuota.cupon
            else this.cuota.emisor = -1 * this.cuota.indexado + this.cuota.cupon + this.cuota.prima

            this.cuota.emisorEscudo = this.cuota.emisor + this.cuota.escudo
            this.cuota.bonista = -1 * this.cuota.emisor

            this.cuota.activo = this.cuota.bonista / (Math.pow(1 + this.resultado.cok / 100, this.cuota.numero))
            sumaActivo += this.cuota.activo
            this.cuota.plazo = this.cuota.activo * this.cuota.numero * this.resultado.frecuencia / this.bono.dias
            sumaPlazo += this.cuota.plazo
            this.cuota.convexidad = this.cuota.activo * this.cuota.numero * (1 + this.cuota.numero)
            sumaConvexidad += this.cuota.convexidad
          } else {
            this.cuota.emisor = this.bono.comercial - this.resultado.costoEmisor
            this.cuota.bonista = -1 * this.bono.comercial - this.resultado.costoInversor
            this.cuota.emisorEscudo = this.cuota.emisor

          }
          bonista.push(this.cuota.bonista)
          emisorEscudo.push(this.cuota.emisorEscudo)
          emisor.push(this.cuota.emisor)
          this.cuotaApiService.create(this.cuota).then(response => {
            console.log(response.data.id)
          })
        }
        this.resultado.precio = this.van(this.resultado.cok / 100, bonista)

        this.resultado.utilidad = -1 * this.bono.comercial - this.resultado.costoInversor + this.resultado.precio

        this.resultado.duracion = sumaPlazo / sumaActivo
        this.resultado.convexidad = sumaConvexidad / (Math.pow(1 + this.resultado.cok / 100, 2) * sumaActivo * Math.pow(this.bono.dias / this.resultado.frecuencia, 2))
        this.resultado.total = this.resultado.duracion + this.resultado.convexidad
        this.resultado.duracionModif = this.resultado.duracion / (1 + this.resultado.cok / 100)

        this.resultado.TCEAemisor = (Math.pow(irr(emisor) + 1, this.bono.dias / this.resultado.frecuencia) - 1) * 100
        this.resultado.TCEAemisorEscudo = (Math.pow(irr(emisorEscudo) + 1, this.bono.dias / this.resultado.frecuencia) - 1) * 100
        this.resultado.TREAbonista = (Math.pow(irr(bonista) + 1, this.bono.dias / this.resultado.frecuencia) - 1) * 100

        this.resultadoApiService.create(this.resultado).then(response => {
          var id = response.data.id
        })

        this.resultado = {}
        this.bono = {}
        this.cuota = {}

      })
    }
  }
}
</script>

<style scoped>

</style>