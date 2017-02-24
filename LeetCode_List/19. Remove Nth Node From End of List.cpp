// 19. Remove Nth Node From End of List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 牛比如我 一次通过 虽然没懂题目里的one pass是什么意思

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    	int count=0;
    	ListNode *itr=head;
    	while(itr!=NULL)
    	{
    		itr=itr->next;
    		count++;
    	}

    	if(count==n) { return head->next; }

    	itr=head;
    	for (int i = 0; i < (count-n-1); ++i)
    	{
    		itr=itr->next;
    	}
    	itr->next=itr->next->next;

    	return head;

    }
};