<script setup>
// const name = this.;
import { useStore } from 'vuex';
const store = useStore();
const changeAppName = () => {
    store.commit('app/change', 'faf')
}
</script>
<template>
    <h2>app name is : {{ $store.state.app.name }}</h2>
    <button @click="changeAppName">change</button>
</template>