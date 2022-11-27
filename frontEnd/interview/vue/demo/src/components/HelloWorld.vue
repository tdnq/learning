<template>
  <div class="hello">
    <h1>{{ msg }}</h1>
    <ul>
      <li v-if="true">1</li>
      <li v-if="false">2</li>
      <li v-show="false">3</li>
      <li v-show="true">4</li>
    </ul>
    <h2>{{ age }}</h2>
    <input
      @change="change(), diychane('fa', $event)"
      v-model="info.age"
      type="text"
    />
  </div>
</template>

<script>
export default {
  name: "HelloWorld",
  props: {
    msg: String,
    isHiden: Boolean,
  },
  data() {
    // eslint-disable-next-line no-debugger
    debugger;
    return {
      n: false,
      info: {
        age: 12,
      },
    };
  },
  computed: {
    age() {
      return 121;
    },
  },
  watch: {
    info: {
      handler(old, newV) {
        console.log("new", newV, old);
      },
      deep: true,
    },
  },
  methods: {
    change: (e) => {
      console.log(e);
    },
    diychane: (data, e) => {
      //e 是原生的Event
      console.log(data, e);
    },
  },
};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}
</style>
