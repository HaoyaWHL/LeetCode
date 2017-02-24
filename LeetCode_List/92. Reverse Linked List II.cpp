/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 1 ≤ m ≤ n ≤ length of list.一定满足的条件 所以不用再次检测

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
    	if (head == NULL || head->next == NULL) {  return head;	}

    	ListNode *mStart=head;
    	ListNode *nStop=head;
    	for (int i = 0; i < m; ++i)  {	mStart=mStart->next;  }    	
    	for (int i = 0; i < n; ++i)  {	nStop=nStop->next;    }

    	
    	//位于pre和next之间的就是需要翻转的链表
		ListNode *pre=head;
		for (int i = 0; i < (m-1); ++i)  {	pre=pre->next;  } 
    	

    	ListNode *next=nStop->next;
    	nStop->next=NULL;

    	*nStop=reverseList(mStart);

    	if (m==1)
    	{
    		mStart->next=next;
    	}
    	else
    	{
    		pre->next=nStop;
    		mStart->next=next;
    	}

    	return head;

    }



	ListNode* reverseList(ListNode* head) {
	    if ((head == NULL) || (head->next == NULL) )  {   return head;   }
	    ListNode *p=reverseList(head->next);
	    head->next->next=head;
	    head->next=NULL;
	    return p;
	}

};