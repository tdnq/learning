// 顺时针打印二维数组
#include<vector>
std::vector<int> spiralOrder(std::vector<std::vector<int>>&matrix){
    std::vector<int>res;
    if(matrix.empty()){
        return res;
    }
    int left =0,right=matrix[0].size()-1,top=0,bottom=matrix.size()-1,pos=0;
    while (true)
    {
        for(int i=left;i<=right;i++){
            res.push_back(matrix[top][i]);
        }
        if(++top>bottom){break;}
        for(int j=top;j<=bottom;j++){
            res.push_back(matrix[j][right]);
        }
        if(--right<left){break;}
        for(int k=right;k>=left;k--){
            res.push_back(matrix[bottom][k]);
        }
        if(--bottom<top){break;}
        for(int z=bottom;z>=top;z--){
            res.push_back(matrix[z][left]);
        }
        if(++left>right){
            break;
        }
    }
    return res;
    
}
int main(void){
    std::vector<std::vector<int>>temp=  {{1,2,3,4},
                                        {5,6,7,8},
                                        {9,10,11,12},
                                        {13,14,15,16}};
    std::vector<int>res=spiralOrder(temp);
    return 0;
}