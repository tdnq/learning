#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map(0);
        vector<pair<int, int>> frequentNums;
        for (auto val : nums)
        {
            auto ele = map.find(val);
            if (ele != map.end())
            {
                ele->second = ele->second + 1;
            }
            else
            {
                map.insert({val,1});
            }
        }
        for(auto iter = map.begin(); iter!=map.end();iter++){
            frequentNums.push_back(pair<int,int>{ iter->second,iter->first });
        }
        qSort(frequentNums);

        vector<int> res;
        for (int i= 0; i < k; i++)
        {
            res.push_back(frequentNums[i].second);
        }
        return res;
    }
    vector<pair<int, int>> qSort(vector<pair<int, int>> &nums)
    {
        qSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
    void qSortHelper(vector<pair<int, int>> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int index = partition(nums, left, right);
        // int index = partition_book1(nums, left, right);
        qSortHelper(nums, left, index - 1);
        qSortHelper(nums, index + 1, right);
    }
    int partition(vector<pair<int, int>> &nums, int left, int right)
    {
        int midIndex = (left + right) / 2, left_b = left;
        pair<int,int> midVal = nums[midIndex];
        swap(nums, left, midIndex); //move the middle element to first
        for (int i = left; i <= right; i++)
        {
            if ((nums[i].first) > midVal.first)
            {
                left++;              // the count bigger than midVal
                swap(nums, i, left); //move smaller element to left
            }
        }
        swap(nums, left, left_b);
        return left;
    }
    void swap(vector<pair<int,int>> &nums, int index_a, int index_b)
    {
        pair<int,int> temp = nums[index_a];
        nums[index_a] = nums[index_b];
        nums[index_b] = temp;
    }
};
int main()
{
    vector<int> data = {1, 1, 1, 2, 2, 3};
    Solution test;
    test.topKFrequent(data, 2);
    return 0;
}