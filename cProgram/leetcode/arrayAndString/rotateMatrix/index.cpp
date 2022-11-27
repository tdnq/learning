#include<vector>
#include<iostream>
using std::swap;
using std::vector;
class  Solution{
    public:
        void rotate(vector<vector <int>>&matrix){
            int row = matrix.size(),col=matrix[0].size();
            for(int i=0,j=row-1;i<j;i++,j--){
                for(int k=0;k<col;k++){
                    swap(matrix[i][k],matrix[j][k]);
                }
            }
            for(int i=0;i<row;i++){
                for(int j=i;j<col;j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
};