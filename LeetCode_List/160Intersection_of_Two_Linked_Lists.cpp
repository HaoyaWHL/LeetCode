/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// NOTES:this code will find the intersection node , but linked structure is modified , and get error finally

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	ListNode *p1,*p2,*interNode;

    	interNode=NULL;

    	if ((NULL == headA ) || (NULL == headB)) 	{	return NULL; 	}

    	p1= reverseList(headA);
    	p2= reverseList(headB);

    	if(p1 == p2)
    	{
	    	while(p1->next != p2->next)
	    	{
	    		p1=p1->next;
	    		p2=p2->next;
	    	}

	    	interNode=p1;

	    	headA=reverseList(p1);
	    	headB=reverseList(p2);
	    }

    	return interNode;
	   
    }

    ListNode* reverseList(ListNode* head) {
        if ((head == NULL) || (head->next == NULL) )  {   return head;   }
        ListNode *p=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return p;
    }


};
