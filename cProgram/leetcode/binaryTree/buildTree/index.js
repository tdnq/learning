/**
 * build tree from midOrder and postOrder
 */
 
let buildTree=function(inorder=[],postorder=[]){
    const helper=(left,right)=>{
        if(left>right){
            return null;
        }
        let val=postorder.pop();
        let root=new TreeNode(val);
        let index=inorder.indexOf(val);
        root.right=helper(index+1,right);
        root.left=helper(left,index-1);
        return root;
    }
    return helper(0,postorder.length-1);
}
buildTree=function(preorder=[],inorder=[]){
    let helper=(left,right)=>{
        if(left>right){
            return null;
        }
        let val=preorder.shift();
        let index=inorder.indexOf(val);
        let root=new TreeNode(val);
        root.left=helper(left,index-1);
        root.right=helper(index+1,right);
        return root;
    }
    return helper(0,inorder.length-1);
}