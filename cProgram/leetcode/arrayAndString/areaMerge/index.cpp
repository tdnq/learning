#include <vector>
#include <algorithm>
class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        if (intervals.size() == 0)
        {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> res;
        for (int i = 0; i < intervals.size(); i++)
        {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if (!res.size() || res.back()[1] < left)
            {
                res.push_back({left, right});
            }
            else
            {
                res.back()[1] = std::max(res.back()[1], right);
            }
        }
        return res;
    }
};
int main(){
    std::vector<std::vector<int>> temp({{0,1},{2,3},{0,3}});
    Solution test;
    std::vector<std::vector<int>> res=test.merge(temp);
    return 0;
}