/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 根据之前写的链表翻转的知识 用在这里 效果绝佳

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if ( head==NULL || head->next==NULL ) return head;

        ListNode* iter=head;
        int size=0;

        while(iter)
        {
            iter=iter->next;
            size++;
        }

        int group=size/k;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* preCurrent=head;
        ListNode* current=NULL;

        for (int i = 0; i < group; ++i)
        {
            for (int j = 1; j < k; ++j)
            {
                current=preCurrent->next;
                preCurrent->next=current->next;
                current->next=prev->next;
                prev->next=current;
            }
            prev=preCurrent;
            preCurrent=preCurrent->next;
        }

        return dummy->next;

    }
};