const app = {
    namespaced: true,
    state: () => ({
        name: 'vue taste'
    }),
    mutations: {
        change(state, name) {
            state.name = name;
        }
    }
}
export default app;