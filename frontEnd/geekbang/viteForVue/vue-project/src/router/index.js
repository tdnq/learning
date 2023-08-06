import { createRouter, createWebHistory } from 'vue-router'
import Basic from '../views/Basic/index.vue';

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/basic',
      name: 'basic',
      component: Basic
    }
  ]
})

export default router
