<script setup>
import { computed } from 'vue';
const props = defineProps({
    value: { type: Number, default: 1 },
    color: { type: String, default: 'red' }
});
let rate = computed(() => "★★★★★☆☆☆☆☆".slice(5 - props.value, 10 - props.value))
</script>
<template>
    <div :style="{ color }">
        {{ rate }}
    </div>
</template>