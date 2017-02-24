// 24. Swap Nodes in Pairs
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 完全仿照25题思路进行 只是此处将K换成常量=2

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
    	ListNode *curr=head;
    	int count=0;
    	while(curr!=NULL && count!=2)
    	{
    		curr=curr->next;
    		count++;
    	}

    	if (count==2)
    	{
    		curr=swapPairs(curr);

    		while(count-- >0)
    		{
    			ListNode *tmp=head->next;
    			head->next=curr;
    			curr=head;
    			head=tmp;
    		}
    		head=curr;
    	}
    	return head;

    }
};