// Straigntforward Java solution, O(1) space, O(n) time
// 极其简单的思想 无需多说 关键的就是while循环的判定 

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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL) { return head; }
        
        ListNode *odd,*even,*evenHead;

        odd=head;
        evenHead=head->next;
        even=evenHead;

        while (even && even->next)
        {
            odd->next=even->next;
            odd=even->next;
            even->next=odd->next;
            even=odd->next;
        }
        
        odd->next=evenHead;

        return head;

    }
};