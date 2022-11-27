#include <deque>
#include <vector>
using namespace std;
class MonoTonicQueue
{
private:
    deque<int> data;

public:
    void push(int n)
    {
        while (!data.empty() && data.back() < n)
        {
            data.pop_back();
        }
        data.push_back(n);
    }
    int max()
    {
        return data.front();
    }
    void pop(int n)
    {
        if (!data.empty() && data.front() == n)
        {
            data.pop_front();
        }
    }
};

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    MonoTonicQueue window;
    vector<int> res;
    for (int i= 0; i < nums.size(); i++)
    {
        if (i < k - 1)
        {
            window.push(nums[i]);
        }
        else
        {
            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i - k + 1]);
        }
    }
    return res;
}
int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    maxSlidingWindow(nums,3);
}