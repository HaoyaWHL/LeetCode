// 61. Rotate List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 完美解决 自己写的accepted！

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
    	if (head==NULL || head->next==NULL) { return head; }

    	
    	ListNode *itr=head;
    	int size=1;
    	while(itr->next != NULL)
    	{
    		size++;
    		itr=itr->next;
    	}

    	k=k%size; //这里和33行一定要搞清楚联系 旋转多少 所以记得取%
    	if(k==0) { return head; } //其实不必要

    	ListNode *cur=new ListNode(0);
    	cur->next=head;
    	for (int i = 0; i < (size-k); ++i)
    	{
    		cur=cur->next;
    	}

    	ListNode *newhead=cur->next;
    	itr->next=head;
    	cur->next=NULL;

    	return newhead;

    }

};