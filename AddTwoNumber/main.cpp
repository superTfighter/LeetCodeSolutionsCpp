#include "iostream"

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *sum = new ListNode();

        generateSumList(l1, l2, sum);

        return sum;
    }

    void generateSumList(ListNode *l1, ListNode *l2, ListNode *sum, ListNode *previous = nullptr, int carry = 0)
    {

        if (l1 != nullptr || l2 != nullptr || carry != 0)
        {

            // Default values
            int val1 = 0;  ListNode *n1 = nullptr;
            int val2 = 0;  ListNode *n2 = nullptr;

            if (l1 != nullptr)
            {
                val1 = l1->val;
                n1 = l1->next;
            }

            if (l2 != nullptr)
            {
                val2 = l2->val;
                n2 = l2->next;
            }

            // do the sum 
            int summa = val1 + val2 + carry;

            int newVal = summa % 10;
            int c_ = summa / 10;

            sum->val = newVal;
            sum->next = new ListNode();

            this->generateSumList(n1, n2, sum->next, sum, c_);
        }
        else
        {
            // No more element
            previous->next = nullptr;
        }

        return;
    }
};

int main()
{

    Solution s;

    ListNode l1 = 2;
    ListNode l1_2 = 4;
    ListNode l1_3 = 3;

    l1_2.next = &l1_3;
    l1.next = &l1_2;

    ListNode l2 = 5;
    ListNode l2_2 = 6;
    ListNode l2_3 = 4;
    /*ListNode l2_4 = 9;
    ListNode l2_5 = 9;
    ListNode l2_6 = 9;
    ListNode l2_7 = 9;
    ListNode l2_8 = 9;
    ListNode l2_9 = 9;
    ListNode l2_10 = 9;
    ListNode l2_11 = 9;
    ListNode l2_12 = 9;
    ListNode l2_13 = 9;
    ListNode l2_14 = 9;
    ListNode l2_15 = 9;*/

    /*l2_14.next = &l2_15;
    l2_13.next = &l2_14;
    l2_12.next = &l2_13;
    l2_11.next = &l2_12;
    l2_10.next = &l2_11;
    l2_9.next = &l2_10;
    l2_8.next = &l2_9;
    l2_7.next = &l2_8;
    l2_6.next = &l2_7;
    l2_5.next = &l2_6;
    l2_4.next = &l2_5;
    l2_3.next = &l2_4;*/
    l2_2.next = &l2_3;
    l2.next = &l2_2;

    s.addTwoNumbers(&l1, &l2);
}