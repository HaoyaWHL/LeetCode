/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 类似前面的题目 采用递归的思想 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) return NULL;

        if (head->next && head->val==head->next->val)
        {
            while( head->next && head->val==head->next->val )
                { head=head->next; }
            return deleteDuplicates(head->next);
        }
        else
            { head->next=deleteDuplicates(head->next); }
        return head;
    }
};