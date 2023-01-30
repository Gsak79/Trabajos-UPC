import { createRouter, createWebHistory } from "vue-router";

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: "/",
      redirect: "home",
    },
    {
      path: "/home",
      name: "home",
      component: () => import("../extrabonus/pages/home.component.vue"),
    },
    {
      path: "/crear-bono",
      name: "crear-bono",
      component: () => import("../extrabonus/pages/crear-bono.component.vue"),
    },
    {
      path: "/configuracion",
      name: "configuracion",
      component: () => import("../extrabonus/pages/configuracion.component.vue"),
    },
    {
      path: "/historial",
      name: "historial",
      component: () => import("../extrabonus/pages/historial.component.vue"),
    },
    {
      path: "/perfil",
      name: "perfil",
      component: () => import("../extrabonus/pages/perfil.component.vue"),
    },
    {
      path: "/resultado/:id",
      name: "resultado",
      component: () => import("../extrabonus/pages/resultado.component.vue"),
    },
  ],
});

export default router;
