/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// the only trouble is , if the input is [] or [1] or [1,1] ,and I should del the val 1 , the result will say failed.
 // the reason is : if the head is NULL , I can never push PC to run the 'head->val' operator!

class Solution {
public:
    ListNode* removeElements(ListNode* head, int delVal) {

	   	if (NULL == head)  {  return head;  }

    	while(delVal == head->val) 	
		{	
			head=head->next;
			if (NULL == head)  {  return head;  }
		}

      	ListNode *pre,*curr;

    	pre=head;
    	curr=head->next;

    	while(NULL != curr)
    	{
    		if (delVal == curr->val)
    		{
    			pre->next=curr->next;
    			curr=curr->next;
    		}
    		else
    		{
    			pre=pre->next;
    			curr=curr->next;
    		}
    	}

    	return head;

    }
};