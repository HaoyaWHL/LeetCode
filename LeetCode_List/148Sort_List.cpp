/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// if the input is [2,1,3,6,23,5,2],look at the while loop in my code ,you will find sth. wrong
// because I choose the loop number as the length of input array,but in fact the really need is larger than this.

// I must say,the idea of using recursion is quite brilliant! The code is in the discuss!
// https://discuss.leetcode.com/category/156/sort-list

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
    	if(NULL == head) { return head;}

    	ListNode *p,*curr,*start;
    	int tmp;

    	start=head;
    	p=head;
    	curr=head->next;

    	int length=0;
    	while(start!=NULL)
    	{
    		length++;
    		start=start->next;
    	}


    	for (int i = 0; i < length; ++i)
    	{

	    	start=head;
	    	p=head;
	    	curr=head->next;

    		while(NULL != start->next)
	    	{

	    		if (p->val > curr->val)
	    		{
	    			tmp = p->val;
	    			p->val = curr->val;
	    			curr->val = tmp;
	    		}

				p=p->next;
				curr=curr->next;

	    		if(NULL == curr)  
				{
					start=start->next;
					p=start;
					curr=start->next;
				}
	    	}
            

    	}
    	
    	return head;
    }
};