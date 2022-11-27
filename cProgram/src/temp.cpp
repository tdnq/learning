#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
bool com(pair<int, int>& a, pair<int, int>& b){return a.second > b.second; }
class Solution
{
private:
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> hash;
        for (auto item : nums)
        {
            hash[item]++;
        }
        vector<pair<int, int>> hashv(hash.begin(), hash.end());
        sort(hashv.begin(),hashv.end(),com);
        vector<int> res;
        auto a = hashv.begin();
        while (k--)
        {
            res.push_back(a->first);
            a++;
        }
        return res;
    }
    static bool compare(int a,int b){
        return a<b;
    }
};
int main()
{
    Solution test;
    int a[]={1,4,3,2,1};
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    test.topKFrequent(nums, 2);
    return 0;
}