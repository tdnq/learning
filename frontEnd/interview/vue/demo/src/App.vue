/* eslint-disable vue/no-unused-components */
<template>
  <!-- <img alt="Vue logo" src="./assets/logo.png" /> -->
  <!-- <HelloWorld isHiden msg="Welcome to Your Vue.js App" /> -->
  <ComunicationComponent />
</template>

<script>
import HelloWorld from "./components/HelloWorld.vue";
import ComunicationComponent from "./components/Comulication.vue";

export default {
  name: "App",
  components: {
    // eslint-disable-next-line vue/no-unused-components
    HelloWorld,
    ComunicationComponent,
  },
  data() {
    return { currentCom: "ComunicationComponent", comps: this.components };
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
