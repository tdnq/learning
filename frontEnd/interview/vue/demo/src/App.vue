<template>
  <!-- <img alt="Vue logo" src="./assets/logo.png" /> -->
  <!-- <HelloWorld isHiden msg="Welcome to Your Vue.js App" /> -->
  <!-- <ComunicationComponent /> -->
  <Customize @changeName="changeName" :name="name" />
</template>

<script>
import HelloWorld from "./components/HelloWorld.vue";
import ComunicationComponent from "./components/Comulication.vue";
import Customize from "./components/Customize.vue";

export default {
  name: "App",
  components: {
    // eslint-disable-next-line vue/no-unused-components
    HelloWorld,
    // eslint-disable-next-line vue/no-unused-components
    ComunicationComponent,
    Customize,
  },
  methods: {
    changeName() {
      this.name += Math.random();
    },
  },
  data() {
    return { name: "a" };
  },
  beforeCreate() {
    console.log("father beforeCreate");
  },
  created() {
    console.log("father create");
  },
  beforeUpdate() {
    console.log("father beforeupdate");
  },
  updated() {
    console.log("father updated");
  },
  beforeMount() {
    console.log("father beforeMount");
  },
  mounted() {
    console.log(" father mounted");
  },
};
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
