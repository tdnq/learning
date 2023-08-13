import { createRouter, createWebHistory } from 'vue-router'
import Basic from '../views/Basic/index.vue';
import Todo from '../views/Todo/index.vue';
import VuexView from '../views/Vuex/index.vue';

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/basic',
      name: 'basic',
      component: Basic
    },
    {
      path: '/todo',
      name: 'todo',
      component: Todo
    },
    {
      path: '/vuex',
      name: 'vuex',
      component: VuexView
    }
  ]
})

export default router
