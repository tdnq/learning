#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<string>> sloveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> checkerboard(n,string(n,'.'));
        backTrack(res, checkerboard,0);
        return res;
    }
    void backTrack(vector<vector<string>> &res, vector<string> &checkerboard,int row)
    {
        if (row==checkerboard.size()){
            vector <string> temp(checkerboard);
            res.push_back(temp);
        }
        for(int i=0;i<checkerboard.size();i++){
            if(!isConfict(checkerboard,row,i)){
                continue;
            }
            checkerboard[row][i] = 'Q';
            backTrack(res,checkerboard,row+1);
            checkerboard[row][i] = '.';
        }
    }
    bool isConfict(vector<string> checkerboard,int row,int col){
        for (int i = 0; i < row; i++)
        {
            if (checkerboard[i][col] == 'Q')
            {
                return false;
            }
        }
        //左上方
        for (int i = col, j = row; i >= 0 && j >= 0; j--, i--)
        {
            if (checkerboard[j][i] == 'Q')
            {
                return false;
            }
        }
        for (int i = col, j = row; i <= checkerboard.size() && j >= 0; j--, i++)
        {
            if (checkerboard[j][i] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution test;
    test.sloveNQueens(4);
    return 0;
}