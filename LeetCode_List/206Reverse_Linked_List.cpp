/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// the time complexity is too biger , so failed

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
    	if ((NULL == head) || (NULL == head->next)) {return head;}

    	ListNode *rlist,*tmp;

    	rlist->val=head->val;
    	rlist->next=NULL;
    	
    	head=head->next;

    	while(NULL != head)
    	{
    		tmp->val=head->val;
    		tmp->next=rlist;
    		rlist=tmp;

    		free(tmp);

    		head=head->next;
    	}

    	return rlist;
    }
};