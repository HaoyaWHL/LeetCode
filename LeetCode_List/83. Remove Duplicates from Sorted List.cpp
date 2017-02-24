// 83. Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        
    	if (head == NULL) {return NULL;}
    	
    	ListNode *cur=head;
    	ListNode *then=cur->next;

    	while(then!=NULL)
    	{
    		if ((cur->val) == (then->val))
    		{
    			cur->next = then->next;
    			then = then->next;
    		}
    		else
    		{
    			cur = then;	
    			then = cur->next;
    		}
    	}

    	return head;
    }
};