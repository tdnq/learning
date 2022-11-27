#include<vector>
#include<iostream>
#include<queue>

using namespace std;

class QueueAndStack
{
private:
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> matrix)
    {
        queue<vector<int>> updateRecord;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    updateRecord.push(vector<int>{i, j});
                }
                else
                {
                    matrix[i][j] = -1;
                }
            }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while (!updateRecord.empty())
        {
            vector<int> front=updateRecord.front();
            updateRecord.pop();
            int x=front[0],y=front[1];
            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX>=0&&newX<m&&newY>=0&&newY<n&&matrix[newX][newY]==-1){
                    matrix[newX][newY]=matrix[x][y]+1;
                    updateRecord.push(vector<int>{newX,newY});
                }
            }
        }
        return matrix;
    }
    bool canVisitedAllRooms(vector<vector<int>>&rooms){
        int m=rooms.size();
        if(m==0){
            return false;
        }
        int initLen=rooms[0].size(),tarKey=0;
        vector<int> isVisited(m),isHasKey(m);
        queue<int> temp;
        temp.push(0);
        while (!temp.empty())
        {
            int tarKey=temp.front();
            isVisited[tarKey]=1;
            temp.pop();
            initLen=rooms[tarKey].size();
            for (int i = 0; i < initLen; i++)
            {
                if (!isHasKey[rooms[tarKey][i]])
                {
                    isHasKey[rooms[tarKey][i]]=1;
                    temp.push(rooms[tarKey][i]);
                }
            }
        }
        for(int i=0;i<m;i++){
            if(isVisited[i]==0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    QueueAndStack test;
    vector<vector<int>>temp={{1,3},{3,0,1},{2},{0}};
    bool res=test.canVisitedAllRooms(temp);
    return 0;
}