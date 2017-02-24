// 更为简练 思想是一样的
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy=new ListNode(0);

        while(head) {
            ListNode *iter=dummy;

            while(iter->next && iter->next->val < head->val)  { iter=iter->next; }

            ListNode *next=head->next;
            head->next=iter->next;
            iter->next=head;
            head=next;
        }

        return dummy->next;

    }
};