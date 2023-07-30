<script>
export default {
    data() {
        return {
            name: 'td',
            num: 0
        }
    }
}
</script>
<template>
    <div>hello{{ name }},{{ num }}</div>
    <button @click="num++">add num</button>
</template>
<style>
.demo {
    width: 200px;
    padding: 10px;
    box-shadow: 0px 0px 9px #00000066;
    text-align: center;
}

.demo .text {
    font-size: 28px;
    font-weight: bolder;
    color: #666666;
}

.demo .btn {

    font-size: 20px;
    padding: 0 10px;
    height: 32px;
    min-width: 80px;
    cursor: pointer;
}
</style>