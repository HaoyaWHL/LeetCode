/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 1 ≤ m ≤ n ≤ length of list.一定满足的条件 所以不用再次检测
//非常厉害的一个思想 值得学习

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
     
        if(head==NULL)  { return head; }

        ListNode *dummy=new ListNode(0);
        dummy->next=head;

        ListNode *pre=dummy;
        for (int i = 0; i < m-1; ++i)  {  pre=pre->next;  }

        ListNode *start=pre->next;
        ListNode *then=start->next;

        for (int i = 0; i < n-m; ++i)
        {
            start->next=then->next;
            then->next=pre->next;
            pre->next=then;
            then=start->next;
        }

        return dummy->next;

    }
};