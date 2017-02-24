/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//本题思路在于解决三种情况：链表头 链表尾 链表中
 //注意 是    <=     >= 


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

    	if (head==NULL || head->next==NULL)	{ return head;  }

    	ListNode* sortHead=head;
    	ListNode* sortTail=head;
    	head=head->next;
    	sortHead->next=NULL;

    	while(head!=NULL)
    	{
    		ListNode* tmp=head;
    		head=head->next;
    		tmp->next=NULL;


    		if (tmp->val < sortHead->val)
    		{
    			tmp->next=sortHead;
    			sortHead=tmp;
    			if (sortHead->next == NULL)
    			{
    				sortTail=sortHead;
    			}

    		}
    		else if(tmp->val >= sortTail->val)
    		{
    			sortTail->next=tmp;
    			sortTail=sortTail->next;
    		}
    		else
    		{
    			ListNode* cur=sortHead;
    			while(cur!=sortTail)
    			{
    				if ((cur->val <= tmp->val) && (cur->next->val >= tmp->val))
    				{
    					tmp->next=cur->next;
    					cur->next=tmp;
    					break;
    				}
    				cur=cur->next;
    			}
    		}

    	}

    	return sortHead;
        
    }
};