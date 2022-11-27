#include<vector>
using namespace std;
class Solution{
    public:
        int searchInsert(vector<int>&nums,int target){
            return searchInsertHelper(nums,target,0,nums.size()-1);
        }
        int searchInsertHelper(vector<int>&nums,int target,int begin,int end){
            if(begin>end){
                return begin;
            }
            int mid = (begin+end)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                return searchInsertHelper(nums,target,mid+1,end);
            }else {
                return searchInsertHelper(nums,target,begin,mid-1);
            }
        }
};
int main(){
    Solution test;
    vector <int> temp={1,2,4,5,6};
    test.searchInsert(temp,6);
    return 0;
}