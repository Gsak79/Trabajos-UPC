import { createApp } from "vue";
import App from "./App.vue";
import router from "./router";
import PrimeVue from "primevue/config";

import "primevue/resources/themes/lara-light-blue/theme.css";
import "primevue/resources/primevue.min.css";
import "primeicons/primeicons.css";
import "/node_modules/primeflex/primeflex.css";

import Toolbar from "primevue/toolbar";
import Button from "primevue/button";
import Sidebar from "primevue/sidebar";
import Divider from "primevue/divider";
import RadioButton from "primevue/radiobutton";
import Card from "primevue/card";
import ToastService from "primevue/toastservice";
import Toast from "primevue/toast";
import InputText from "primevue/inputtext";
import InputNumber from "primevue/inputnumber";
import Dropdown from "primevue/dropdown";
import Calendar from "primevue/calendar";
import DataTable from "primevue/datatable";
import Column from "primevue/column";
import Dialog from "primevue/dialog";
import SelectButton from "primevue/selectbutton";

const app = createApp(App);

app.use(ToastService);
app.use(router);
app.use(PrimeVue, { ripple: true });

app.component("pv-toolbar", Toolbar);
app.component("pv-button", Button);
app.component("pv-sidebar", Sidebar);
app.component("pv-divider", Divider);
app.component("pv-radio-button", RadioButton);
app.component("pv-card", Card);
app.component("pv-toast", Toast);
app.component("pv-input-text", InputText);
app.component("pv-input-number", InputNumber);
app.component("pv-dropdown", Dropdown);
app.component("pv-calendar", Calendar);
app.component("pv-datatable", DataTable);
app.component("pv-column", Column);
app.component("pv-dialog", Dialog);
app.component("pv-select-button", SelectButton)

app.mount("#app");
