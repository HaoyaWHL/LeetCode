/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 还是觉得这份代码最叼 没有之一 毕竟是采用了递归的思想

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL || head->next==NULL) { return head; }
     	ListNode *p=reverseList(head->next);
     	head->next->next=head;
     	head->next=NULL;
     	return p;
    }
};