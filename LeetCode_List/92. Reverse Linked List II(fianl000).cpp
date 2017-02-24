/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 触类旁通 博闻强记 根据第143reorder list 写出来的方法 
// 尤其是preCurrent的迭代！
// 跟高票答案算法一样

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head==NULL || head->next==NULL) return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* prev=dummy;
        for(int i=0;i<m-1;i++) { prev=prev->next; }

        ListNode* preCurrent=prev->next;
        for (int i = 0; i < n-m; ++i)
        {
            ListNode* current=preCurrent->next;
            preCurrent->next=current->next;
            current->next=prev->next;
            prev->next=current;
        }

        return dummy->next;
    }
};