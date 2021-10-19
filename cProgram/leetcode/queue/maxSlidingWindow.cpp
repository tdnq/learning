#include<vector>
#include<climits>
#include<deque>
using namespace std;
class Solution{
  public:
    vector<int> maxSlidingWindow(vector<int>&nums,int k){
        int len = nums.size();
        if(len<k){
            return vector<int>{};
        }
        vector<int> res(  len - k +1);
        deque<int> helperQueue;
        helperQueue.push_back(0);
        for(int i=0;i<len;i++){
            while(!helperQueue.empty() && nums[i]>=nums[helperQueue.back()])
            {
                helperQueue.pop_back();
            }
            if(!helperQueue.empty() && helperQueue.front()<=i-k){
                helperQueue.pop_front();
            }
            helperQueue.push_back(i);
            if(i>=k-1){
                res[i-k+1] = nums[helperQueue.front()];
            }
        }
        return res;
    }
};
int main(){
    vector<int> data = {1,3,-1,-3,5,3,6,7};
    Solution test;
    test.maxSlidingWindow(data,3);
    return 0;
}