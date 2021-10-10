#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector <int> > permute(vector<int> &nums)
    {
        vector<vector <int> > res;
        if(nums.size()==0){
            return res;
        }
        vector<int> temp;
        backTrack(nums, res, temp);
        return res;
    }
    void backTrack(vector<int> &nums, vector<vector <int> > &res, vector<int> temp)
    {
        if (nums.size() == temp.size())
        {
            vector<int> ele(temp);
            res.push_back(ele);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(temp.begin(),temp.end(),nums[i])!=temp.end())
            {
                continue;
            }
            temp.push_back(nums[i]);
            backTrack(nums, res, temp);
            temp.pop_back();
        }
    }
};

int main()
{
    Solution test;
    vector<int> data = {1, 2, 3,4,5};
    test.permute(data);
}