function lengthOfLongestSubstring(str=""){
    let memory=new Set(),max=0,left=0;
    for(let i=0;i<str.length;i++){
        if(memory.has((str[i]))){
            max=Math.max(memory.size,max);
            while(str[left]!==str[i]){
                memory.delete(str[left]);
                left++;
            }
            left++;
        }else{
            memory.add(str[i],)
        }
    }
    return max;
}
lengthOfLongestSubstring("abcabcbb");