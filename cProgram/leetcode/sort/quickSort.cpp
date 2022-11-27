#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> qSort(vector<int> &nums)
    {
        qSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
    void qSortHelper(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        // int index = partition(nums, left, right);
        int index = partition_book1(nums, left, right);
        qSortHelper(nums, left, index - 1);
        qSortHelper(nums, index + 1, right);
    }
    int partition(vector<int> &nums, int left, int right)
    {
        int midIndex = (left + right) / 2, left_b = left;
        int midVal = nums[midIndex];
        swap(nums, left, midIndex); //move the middle element to first
        for (int i = left; i <= right; i++)
        {
            if (nums[i] < midVal)
            {
                left++; // the count bigger than midVal
                swap(nums, i, left); //move smaller element to left
            }
        }
        swap(nums, left, left_b);
        return left;
    }
    int partition_book1(vector<int>&nums,int left,int right){
        int midIndex = (left + right) / 2;
        int midVal = nums[midIndex];
        swap(nums,left,midIndex);
        while (left<right)
        {
            while (left<right && nums[right]>=midVal)
            {
                right--;
            }
            if(left<right){
                nums[left] = nums[right]; // or use swap
            }
            while (left<right && nums[left]<=midVal)
            {
                left++;
            }
            if(left<right){
                nums[right] = nums[left];
            }
        }
        nums[left] = midVal; //delete it if use swap
        return left;
    }
    void swap(vector<int> &nums, int index_a, int index_b)
    {
        int temp = nums[index_a];
        nums[index_a] = nums[index_b];
        nums[index_b] = temp;
    }
};
int main(){
    vector<int> data = {3,4,1,2,5,1};
    Solution test;
    test.qSort(data);
}