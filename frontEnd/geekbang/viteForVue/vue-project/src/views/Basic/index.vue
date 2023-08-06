<template>
    <form>
        <input class="" v-model="name" placeholder="用户名称" />
        <br />
        <textarea v-model="data.info" placeholder="用户信息" />
        <div>名称: {{ name }}</div>
        <div>信息: {{ data.info }}</div>
    </form>
    <button @click="_show">show</button>
</template>

<script setup>
import { reactive } from 'vue';
const state = reactive({
    name: '张三',
    info: '某某公司前端开发工程师，有3年前端工作经验',
});
const data = {
    name: '张三',
    info: '某某公司前端开发工程师，有3年前端工作经验',
};
let { name } = state;
let _show = () => {
    console.log(data, name);
}
</script>