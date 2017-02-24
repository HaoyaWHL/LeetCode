/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 按自己的理解 此代码可以编译通过 但是理解错了题目啊！！！！！！
 // 但是题目另有含义： 
//  有两个链表作为输入，它们表示逆序的两个非负数。如下面的两个链表表示的是342和465这两个数。你需要计算它们的和并且用同样的方式逆序输出。
//  如342+465 = 807,你需要把结果表达为7 ->0 ->8
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  
    	ListNode *head=l1;

    	while(l1->next!=NULL && l2->next!=NULL)
    	{
    		l1->val=(l1->val + l2->val)%10;
    		l1=l1->next;
    		l2=l2->next;
    	}
    	
    	if (l1->next!=NULL && l2->next!=NULL)
    	{
    		l1->val=(l1->val + l2->val)%10;
    	}
    	else if (l1->next!=NULL)
    	{
    		l1->val=(l1->val + l2->val)%10;
			l1=l1->next;
    		while(l1!=NULL)
    		{
    			l1->val=l1->val % 10;
				l1=l1->next;
    		}
    	}
    	else//l2!=NULL
    	{
	    	l1->val=(l1->val + l2->val)%10;
	    	l1->next=l2->next;
	    	while(l1!=NULL)
	    	{
    			l1->val=l1->val % 10;
				l1=l1->next;
	    	}
    	}

    	return head;
    }
};