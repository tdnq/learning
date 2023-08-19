<script setup>
import Rate from '@/components/Rate/index.vue';
import { Button } from 'ant-design-vue';
import { ref } from 'vue'

const data = ref({
    name: '1b'
})
const changeAppName = () => {
    data.value.name = '2323';
}
</script>
<template>
    <h2>app name is : {{ data.name }}</h2>
    <Button @click="changeAppName">change name</Button>
    <div>
        <Rate :value="3" />
        <Rate :value="2" color="blue" />
    </div>
</template>

