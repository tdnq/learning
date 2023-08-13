<script setup>
import { RouterLink, RouterView } from 'vue-router'
</script>

<template>
  <header>
    <div class="wrapper">
      <nav>
        <RouterLink to="/basic">basic</RouterLink>
        <br />
        <RouterLink to="/todo">todo</RouterLink>
      </nav>
    </div>
  </header>

  <RouterView />
</template>
