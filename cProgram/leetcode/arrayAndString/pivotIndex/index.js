let pivotIndex=function(nums=[]){
    if(nums.length===0){
        return -1;
    }
    let sum=nums.reduce((prev,next)=>prev+next,0);
    let preSum=0;
    for(let i=0;i<nums.length;i++){
        if(sum-preSum-nums[i]===preSum){
            return i;
        }
        preSum+=nums[i];
    }
    return -1;
}
pivotIndex([1,7,3,6,5,6]);