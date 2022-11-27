const PENDING="pending";
const FULFILLED="fulfilled";
const REJECTED="rejected";

class MyPromise{
    constructor(executor){
        this._resolveQueue=[];
        this._rejectQueue=[];
        this._status=PENDING;
        let _resolve=(val)=>{
            if(this._status!==PENDING){
                return;
            }
            this._status=FULFILLED;
            while(this._resolveQueue.length){
                const callback=this._resolveQueue.shift();
                callback(val);
            }
        }
        let _reject=(val)=>{
            if(this._status!==PENDING){
                return;
            }
            this._status=REJECTED;
            while(this._rejectQueue.length){
                const callback=this._rejectQueue.shift();
                callback(val);
            }
        }
        executor(_resolve,_reject);
    }
    then(resolveFn,rejectFn){
        return new MyPromise((resolve,reject)=>{
            const fulfilledFn=val=>{
                let x=resolveFn(val);
                x instanceof MyPromise?x.then(resolve,reject):resolve(x);
            }
            this._resolveQueue.push(fulfilledFn);
            const rejectedFn=val=>{
                let x=rejectFn(val);
                x instanceof MyPromise?x.then(resolve,reject):resolve(x);
            }
            this._rejectQueue.push(rejectedFn);
        })
    }
};

let test=new MyPromise((resolve,reject)=>{
    setTimeout(()=>{
        resolve("result")
    },1000);
})
test.then(res=>console.log(1)).then(res=>console.log(2));