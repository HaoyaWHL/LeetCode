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
    ListNode* reverseList(ListNode* head) {

        if(head==NULL || head->next==NULL) return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* preCurrent=head;
        
        while(preCurrent->next!=NULL){
            ListNode* current=preCurrent->next;
            preCurrent->next=current->next;
            current->next=dummy->next;
            dummy->next=current;
        }
        return dummy->next;
    }
};