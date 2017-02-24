/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// this code also runs out of time limited! -_-||
// BUT!!the function is OK!

class Solution {
public:
    ListNode* sortList(ListNode* head) {
		
		if((NULL == head) || (NULL == head->next)) { return head;}

		ListNode *start,*curr;
		start=head;
		curr=head->next;

		int minVal;

		while( start->next != NULL ) 
		{ 

			while(curr != NULL)
			{
				if (start->val > curr->val)
				{
					minVal = curr->val;
					curr->val = start->val;
					start->val = minVal;
				}
				curr=curr->next;
			}

			start=start->next;
			curr=start->next;

		}


		return head;
    }
};