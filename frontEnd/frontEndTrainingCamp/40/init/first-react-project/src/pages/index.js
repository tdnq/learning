export default function Index(){
    let data="";
    const promise=new Promise((resolve,reject)=>{
        setTimeout(()=>{
            console.log("promise resolve");
            resolve();
        },2000)
    }).then(()=>{
        data="react r"
    })
return (<p>hello,{data}</p>);
}