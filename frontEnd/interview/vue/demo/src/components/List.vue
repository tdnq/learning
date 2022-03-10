<template>
  <ul>
    <li v-for="item in listData" :key="item.name">
      {{ item.name }} <button @click="deleteItem(item.name)">delete</button>
    </li>
  </ul>
</template>
<script>
export default {
  name: "ListItems",
  props: {
    list: {
      type: Array,
      default: () => [],
    },
  },
  data() {
    return {
      listData: this.list.map((name, index) => {
        return { name, index };
      }),
    };
  },
  watch: {
    list: {
      handler: function (val) {
        this.listData = val.map((name, index) => {
          return { name, index };
        });
      },
      deep: true,
    },
  },
  methods: {
    deleteItem(title) {
      this.$emit("del", title);
      this.$emit("addItem");
    },
  },
};
</script>