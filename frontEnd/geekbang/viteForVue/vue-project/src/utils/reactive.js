// eslint-disable-next-line vue/prefer-import-from-vue, no-undef
const { effect, reactive } = require('@vue/reactivity');
// eslint-disable-next-line no-undef
// const { effect, reactive } = require('./reactivePolyfill');

const data = reactive({ a: 12, b: 3, all: 15, temp: { arr: 1 } });
effect(() => {
    data.all = data.a + data.b
    console.log(data.all, data.temp.arr)
})
setTimeout(() => {
    data.a++;
    data.b++;
}, 1000);