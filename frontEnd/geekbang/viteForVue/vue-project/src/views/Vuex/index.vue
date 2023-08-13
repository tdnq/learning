<script setup>
import { useStore } from 'vuex';
import Rate from '@/components/Rate/index.vue';
const store = useStore();
const changeAppName = () => {
    store.commit('app/change', 'faf')
}
</script>
<template>
    <h2>app name is : {{ $store.state.app.name }}</h2>
    <button @click="changeAppName">change</button>
    <div>
        <Rate :value="3" />
        <Rate :value="2" color="blue" />
    </div>
</template>

