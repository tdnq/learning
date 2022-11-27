<template>
  <!-- <h1>{{ name }}</h1> -->
  <input v-model="name" type="text" />
  <button @click="addHandler(title)">add</button>
  <h2>events:</h2>
  <ListItems @del="delHandler" :list="event" />
</template>
<script>
import ListItems from "./List.vue";
// import {define} from "./event.js";
export default {
  name: "ComunicationComponent",
  components: {
    ListItems,
  },
  data() {
    return {
      name: "dd",
      event: ["test"],
    };
  },
  methods: {
    addHandler() {
      console.log(this.event);
      this.event.push(`${this.name}`);
    },
    delHandler(title) {
      this.event = this.event.filter((item) => item !== title);
    },
    addItem() {
      console.log("adding");
    },
  },
  mounted() {
    // this.$emit("addItem", this.addItem); // vue2 通过自定义事件实现兄弟间通信,vue3通过父组件或其他库来实现
  },
  beforeUnmount() {
    // this.$off("addItem", this.addItem);
  },
};
</script>