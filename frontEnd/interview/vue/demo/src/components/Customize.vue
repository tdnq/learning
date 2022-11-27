<template>
  <input
    :value="modelValue"
    @input="$emit('update:modelValue', $event.target.value)"
  />
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
      default: "r",
    },
    modelValue: String,
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