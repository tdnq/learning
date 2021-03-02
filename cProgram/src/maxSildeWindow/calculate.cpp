#include <string>
#include <stack>
using namespace std;
class calculate
{
private:
    int num = 0;

public:
    int calculator(string s)
    {
        int start = 0;
        calculateHelper(s, start);
    }
    int calculateHelper(string s, int &index)
    {
        char operation = '+';
        stack<int> res;
        for (index; index < s.size(); index++)
        {
            char c = s[index];
            if (c == ' ')
            {
                continue;
            }
            if (c == '(')
            {
                num = calculateHelper(s, ++index);
                index++;
            }
            //legal
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            if (!isdigit(c)||index==s.size()-1)
            {
                int pre;
                switch (operation)
                {
                case '+':
                    res.push(num);
                    break;
                case '-':
                    res.push(-num);
                    break;
                case '*':
                    pre = res.top() * num;
                    res.pop();
                    res.push(pre);
                    break;
                case '/':
                    pre = res.top() / num;
                    res.pop();
                    res.push(pre);
                default:
                    break;
                }
                num = 0;
                operation = s[index];
            }
            if (c == ')')
            {
                break;
            }
        }
        int sum = 0;
        while (!res.empty())
        {
            sum += res.top();
            res.pop();
        }
        return sum;
    }
};
int main()
{
    calculate test;
    test.calculator("3+9-2*4");
}