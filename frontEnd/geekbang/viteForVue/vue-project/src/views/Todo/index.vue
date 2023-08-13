<script setup>
import { computed, reactive, ref } from 'vue';
let state = reactive({ list: [{ id: 1, task: 'eat' }, { id: 2, task: 'sport' }] });
let newTask = ref('abc');
const addTask = () => {
    let value = state.list;
    value.push({ id: value.at(-1)?.id ?? 0 + 1, task: newTask.value });
}
const clear = () => {
    state.list = state.list.filter(item => !item.done);
}
const allDone = computed({
    set(val) {
        state.list.forEach(item => { item.done = val });
    },
    get() {
        return state.list.filter(item => !item.done).length === 0
    }
})
const doneScale = computed(() => (state.list.length ? state.list.filter(item => item.done).length / state.list.length * 100 : 100).toFixed(2));
</script>
<template>
    <div>
        <h1>todos</h1>
        <div>
            <label for="">add task</label>
            <input v-model="newTask" type="text">
            <button @click="addTask">add</button>
        </div>
        <ul>
            <li :key="task.id" :class="{ done: task.done }" v-for="task in state.list">
                <input v-model="task.done" type="checkbox">
                {{ task.task }}
            </li>
        </ul>
    </div>
    <div>
        完成进度
        <input type="checkbox" v-model="allDone">
        {{ doneScale }} %
    </div>
    <div>
        <button @click="clear">清除已完成任务</button>
    </div>
</template>
<style scoped>
.done {
    color: rgb(159, 163, 163);
    text-decoration: line-through;
}
</style>