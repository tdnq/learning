function getTimes( array ,  k ) {
    // write code here
    array.sort((a,b)=>a-b);
    let pos=array.length-1,res=0;
    while(pos>0&&k>0){
        if(array[pos]!==array[pos-1]){
            k--;
        }
        pos--;
    }
    pos++;
    while(pos<array.length&&array[pos]===array[++pos]){
        res++;
    }
    return ++res;
}

function greatestCommonpisor( a ,  b ) {
    // write code here
    let temp=Math.min(a,b),res=0;
    for(let i=1;i<=temp;i++){
        if(a%i===0&&b%i===0){
            res=i;
        }
    }
    return res;
}
function includes( s1 ,  s2 ) {
    // write code here
    let mark=0;
    for(let i=0;i<s1.length;i++){
        if(s1[i]===s2[mark]){
            mark++;
        }
    }
    if(mark===s2.length){
        return true;
    }
    mark=s2.length-1;
    for(let i=0;i<s1.length;i++){
        if(s1[i]===s2[mark]){
            mark--;
        }
    }
    return mark<0;
}


includes("arash","hsr");