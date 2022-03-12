<template>
  <h1 @click="changeName">{{ name }}</h1>
</template>
<script>
export default {
  name: "Customize_vModel",
  data() {
    return {};
  },
  props: {
    name: {
      type: String,
      default: "td",
    },
  },
  beforeCreate() {
    console.log("child beforeCreate");
  },
  created() {
    console.log("child create");
  },
  beforeUpdate() {
    console.log("child beforeupdate");
  },
  beforeMount() {
    console.log("child beforeMount");
  },
  mounted() {
    console.log(" child mounted");
  },
  updated() {
    console.log("child updated");
  },
  methods: {
    changeName() {
      this.$emit("changeName");
    },
  },
};
</script>