#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        unordered_map<int, int> memoery;
        return dp(coins, amount, memoery);
    }
    int dp(vector<int> &coins, int amount, unordered_map<int, int> &memoery)
    {
        if (memoery.find(amount) != memoery.end())
        {
            return memoery.at(amount);
        }
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            return -1;
        }
        int res = INT_MAX;
        for (auto coin : coins)
        {
            int nextRes = dp(coins, amount - coin, memoery);
            if (nextRes == -1)
            {
                continue;
            }
            res = min(res, nextRes + 1);
        }
        memoery.insert({ amount, res == INT_MAX ? -1 : res});
        return res == INT_MAX ? -1 : res;
    }
};
int main()
{
    vector<int> data = {2};
    Solution test;
    int res = test.coinChange(data, 11);
    return 0;
}