//recursive
// let preorderTraversal=function(root){
//     let res=[];
//     preorderTraversalHelper(root,res);
//     return res;
// }
// let preorderTraversalHelper=function(root,res){
//     if(!root){
//         return null;
//     }
//     res.push(root.val);
//     preorderTraversalHelper(root.left,res);
//     preorderTraversalHelper(root.right,res)
// }

// non-recursive

let preorderTraversal=function(root){
    if (!root) {
        return []
    }
    let res = [], temp = [];
    temp.push(root);
    while (temp.length) {
        let node = temp.pop();
        res.push(node.val);
        if (node.right) {
            temp.push(node.right);
        }
        if (node.left) {
            temp.push(node.left);
        }
    }
    return res;
}
let inOrderTraversal=function(root){
    if(!root){
        return [];
    }
    let res=[],temp=[];
    while(temp.length||root){
        while(root){
            temp.push(root);
            root=root.left;
        }
        if(temp.length){
            let root=temp.pop();
            res.push(root.val);
            root=root.right;
        }
    }
    return res;
}

let postorderTraversal = function(root) {
    if(!root){
        return [];
    }
    let temp=[],res=[];
    temp.push(root)
    while(temp.length){
       root=temp.pop();
       res.push(root.val);
       if(root.left){
           temp.push(root.left);
       }
       if(root.right){
           temp.push(root.right);
       }
    }
    return res.reverse();
}

let levelOrder=function(root){
    if(!root){
        return [];
    }
    let temp=[],res=[];
    temp.push(root);
    while(temp.length){
        let node=[],len=temp.length;
        for(let i=0;i<len;i++){
            root=temp.shift();
            node.push(root.val);
            if(root.left){
                temp.push(root.left);
            }
            if(root.right){
                temp.push(root.right);
            }
        }
        res.push(node);
    }
    return res;
}