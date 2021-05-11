#include<vector>
#include<unordered_set>
using std::vector;
using std::unordered_set;
class Solution{
    public:
        void setZeroes(vector<vector<int>>&matrix){
            unordered_set<int> clearRow,clearCol;
            int row=matrix.size(),col=matrix[0].size();
            for(int i=0;i<row;i++){
                for (int j = 0; j < col; j++)
                {
                    if(matrix[i][j]==0){
                        clearRow.insert(i);
                        clearCol.insert(j);
                    }
                }
            }
            for (auto &temp:clearRow)
            {
                for(int j=0;j<col;j++){
                    matrix[temp][j]=0;
                }
            }
            for(auto &temp:clearCol){
                  for(int j=0;j<row;j++){
                    matrix[j][temp]=0;
                }
            }
        }
};
int main(void){
    Solution test;
    vector<vector<int>> temp={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    test.setZeroes(temp);
    return 0;
}