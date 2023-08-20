const mutableHandlers = {
    get: createGetter(),
    set: createSetter()
}
const trackMap = new Map();
let activeEffect = null;
function reactive(target) {
    return new Proxy(target, mutableHandlers);
}
function track(target, type, key) {
    let depMap = trackMap.get(target);
    if (!depMap) {
        trackMap.set(target, depMap = new Map());
    }
    let deps = depMap.get(key);
    if (!deps) {
        depMap.set(key, deps = new Set());
    }
    if (!deps.has(activeEffect) && activeEffect) {
        deps.add(activeEffect);
    }
}
function createGetter(shallow = false) {
    return function get(target, key, receiver) {
        const res = Reflect.get(target, key, receiver);
        track(target, 'get', key);
        if (typeof res === 'object') {
            return shallow ? res : reactive(res)
        }
        return res;
    }
}
function createSetter() {
    return function set(target, key, value, receiver) {
        let oldVlaue = target[key];
        let res = Reflect.set(target, key, value, receiver);
        if (value !== oldVlaue) {
            let depMap = trackMap.get(target);
            if (depMap) {
                let deps = depMap.get(key);
                deps?.forEach(fn => {
                    if (activeEffect === fn) {
                        return;
                    }
                    activeEffect = fn;
                    fn()
                    activeEffect = null;
                });
            }
        }
        return res;
    }
}
function effect(fn) {
    activeEffect = fn;
    fn();
    activeEffect = null;
}
// eslint-disable-next-line no-undef
module.exports = {
    effect,
    reactive
}