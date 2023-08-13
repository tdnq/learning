import { createStore } from 'vuex';
import app from './app/index'

const store = createStore({
    modules: {
        app
    }
})

export default store;