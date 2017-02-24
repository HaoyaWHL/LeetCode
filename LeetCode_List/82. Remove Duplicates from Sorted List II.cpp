// 82. Remove Duplicates from Sorted List II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// runtime error 超时？
 // 仔细与03代码比较，我们思想是一致的，但是在val相同节点的细节处理上略有区别
 // 还有pn是每次重新构造，而我的then是一开始就给出的，多了flag的判定，
 // 03中直接在if语句下加while循环处理
 // while大循环中，我判定的是then和cur，而03判定的就是当前指针，p

 // 我多加了对then的判定，很可能就是超时的原因，而03中处理的显得比较简洁

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
	    if (head == NULL) {return NULL;}
	    	

	    ListNode *dummy=new ListNode(0);
	    dummy->next=head;
	    ListNode *pre=dummy;
	    ListNode *cur=head;
	    ListNode *then=cur->next;

	    int flag=0;

	    while((then!=NULL) || (cur!=NULL))
	    {
	    	while ((cur->val) == (then->val))
	    	{
	    		then=then->next;
	    		flag=1;
	    		if (then == NULL)
	    		{
	    			pre->next = NULL;
	    			break;
	    		}
	    	}

	    	if (flag==1)
	    	{
		    	pre->next=then;
		    	cur=then;
		    	then=cur->next;
		    	flag=0;
	    	}
	    	else
	    	{
	    		pre=pre->next;
	    		cur=pre->next;
	    		then=cur->next;
	    	}
	    }

	    return dummy->next;    
    }
};