<template>
  <!-- <h1>{{ name }}</h1> -->
  <input v-model="name" type="text" />
  <button @click="addHandler(title)">add</button>
  <h2>events:</h2>
  <ListItems @del="delHandler" :list="event" />
</template>
<script>
import ListItems from "./List.vue";
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
  },
};
</script>