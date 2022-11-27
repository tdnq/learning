#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <unordered_set>
using std::fmin;
using std::queue;
using std::string;
using std::unordered_set;
using std::vector;
namespace leetCode
{
    class MyCircularQueue
    {
    private:
        vector<int> data;
        int maxSize, front, rear;

    public:
        MyCircularQueue(int k)
        {
            maxSize = k + 1;
            data.assign(maxSize, 0);
            front = rear = 0;
        }
        bool enQueue(int value)
        {
            int index = (rear + 1) % maxSize;
            if (isFull())
            {
                return false;
            }
            else
            {
                data[rear] = value;
                rear = index;
                return true;
            }
        }

        bool deQueue()
        {
            if (isEmpty())
            {
                return false;
            }
            else
            {
                int index = (front + 1) % maxSize;
                front = index;
                return true;
            }
        }

        int Front()
        {
            if (isEmpty())
            {
                return -1;
            }
            return data[front];
        }

        int Rear()
        {
            if (isEmpty())
            {
                return -1;
            }
            return data[(rear - 1 + maxSize) % maxSize];
        }

        bool isEmpty()
        {
            return front == rear;
        }

        bool isFull()
        {
            return (rear + 1) % maxSize == front;
        }
        int length()
        {
            return (rear - front + maxSize) % maxSize;
        }
    };

    class Island
    {
    public:
        int numIslands(vector<vector<char>> &grid)
        {
            int res = 0;
            int rowLen = grid.size(), colLen = grid[0].size();
            for (int i = 0; i < rowLen; i++)
            {
                for (int j = 0; j < colLen; j++)
                {
                    if (grid[i][j] == '1')
                    {
                        treavlGrid(grid, i, j);
                        res++;
                    }
                }
            }
            return res;
        }
        void treavlGrid(vector<vector<char>> &grid, int row, int col)
        {
            if (!isInsideOfGrid(grid, row, col))
            {
                return;
            }
            if (grid[row][col] != '1')
            {
                return;
            }
            grid[row][col] = '2';
            treavlGrid(grid, row + 1, col);
            treavlGrid(grid, row - 1, col);
            treavlGrid(grid, row, col + 1);
            treavlGrid(grid, row, col - 1);
        }
        bool isInsideOfGrid(vector<vector<char>> &grid, int row, int col)
        {
            return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
        }
    };

    class Lock
    {
        string plusOne(string str, int i)
        {
            str[i] = str[i] == '9' ? '0' : str[i] + 1;
            return str;
        }
        string downOne(string str, int i)
        {
            str[i] = str[i] == '0' ? '9' : str[i] - 1;
            return str;
        }
        int openLock(vector<string> &deadends, string target)
        {
            queue<string> temp;
            unordered_set<string> deadNumbers(deadends.begin(), deadends.end());
            unordered_set<string> visited;
            temp.push("0000");
            visited.emplace("0000");
            int res = 0;
            while (!temp.empty())
            {
                int size = temp.size();
                for (int i = 0; i < size; i++)
                {
                    string front = temp.front();
                    temp.pop();
                    if (deadNumbers.count(front))
                    {
                        continue;
                    }
                    if (front == target)
                    {
                        return res;
                    }
                    for (int i = 0; i < 4; i++)
                    {
                        string up = plusOne(front, i);
                        if (!visited.count(up))
                        {
                            temp.push(up);
                            visited.emplace(up);
                        }
                        string down = downOne(front, i);
                        if (!visited.count(down))
                        {
                            temp.push(down);
                            visited.emplace(down);
                        }
                    }
                }
                res++;
            }
            return -1;
        }
    };
    class SpecialNums
    {
    public:
        int numSquares(int n)
        {
            vector<int>dp(n+1);
            for (int i = 1; i <= n; i++)
            {
                dp[i] = i;
                for (int j = 1; i - j * j >= 0; j++)
                {
                    dp[i] = (int)fmin(dp[i], dp[i - j * j] + 1);
                }
            }
            return dp[n];
        }
    };
} // namespace leetCode