/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 非常简单的思想 跟我在question中提出的算法一样 但是就是我的不能通过 问题出在哪里？

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* fakeHead=new ListNode(0);
        fakeHead->next=head;
        ListNode* pre=fakeHead;
        ListNode* cur=head;
        while(cur){
            while(cur->next && cur->val==cur->next->val)
                { cur=cur->next; }
            if(pre->next==cur) 
                { pre=pre->next; }
            else
                { pre->next=cur->next; }
            cur=cur->next;
        }
        return fakeHead->next;
    }
};