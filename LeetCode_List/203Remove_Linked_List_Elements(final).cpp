/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 不要小瞧一个问题 当这个问题简单的时候 就是看如何用最精炼的代码 写出一个最为高效的代码

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) { return head; }
        head->next=removeElements(head->next,val);
        return head.val==val ? head->next : head;
    }
};