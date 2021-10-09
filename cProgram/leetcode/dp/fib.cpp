class Solution
{
public:
    int fib_traverse(int n)
    {
        return 0;
    }
    int fib_recursive(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else
        {
            return fib_recursive(n - 1) + fib_recursive(n - 2);
        }
    }
    int fib_dp(int n)
    {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int res[n+1];
        res[0] = 0, res[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n];
    }
};
int main()
{
    Solution test;
    int res = test.fib_recursive(5);
    res = test.fib_dp(2);
    return 0;
}