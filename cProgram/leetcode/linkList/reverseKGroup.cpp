#include<tuple>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int listLength = getLengthOfList(head);
        if (k <= 1 || listLength < k)
        {
            return head;
        }
        int loop = listLength / k;
        ListNode *dummy = new ListNode(-1, head), *prev = dummy, *curr = head, *next;

        for (; loop > 0; loop--)
        {
            for (int i = 0; i < k - 1; i++)
            {
                next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
    int getLengthOfList(ListNode *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            len++;
            head = head->next;
        }
        return len;
    }
};
class Solution2 {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    for (int i = 2; i < 6; i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    Solution2 test;
    test.reverseKGroup(head, 5);
    return 0;
}