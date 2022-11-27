#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        stack<int> s;
        vector<int> res(T.size());
        for (int i = 0; i < T.size(); i++)
        {
            while (!s.empty() && T[s.top()] < T[i])
            {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty())
        {
            res[s.top()] = 0;
            s.pop();
        }
        return res;
    }
};
int main()
{
    vector<int> t = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution test;
    test.dailyTemperatures(t);
    return 0;
}