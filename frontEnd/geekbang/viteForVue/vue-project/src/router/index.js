import { createRouter, createWebHistory } from 'vue-router'
import Basic from '../views/Basic/index.vue';
import Todo from '../views/Todo/index.vue';

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
    }
  ]
})

export default router
