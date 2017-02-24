// 2. Add Two Numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 失败的代码 不知道问题出在哪 个人认为是时间复杂度超了 而且代码写的不简练
 // 看了02就知道问题出在哪了。。。。。。。

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    	int sizeL1=0,sizeL2=0;
    	ListNode *itr1=l1, *itr2=l2;
    	while(l1!=NULL)
    	{
    		itr1=itr1->next;
    		sizeL1++;
    	}
    	while(l2!=NULL)
    	{
    		itr2=itr2->next;
    		sizeL2++;
    	}

    	ListNode *head;
    	if (sizeL1 >= sizeL2)
    	{
    		head=prioriLongList(l1,l2);
    	}
    	else
    	{
    		head=prioriLongList(l2,l1);
    	}
        
    	return head;
        
    }


    ListNode* prioriLongList(ListNode* l1,ListNode* l2){

        ListNode *head=l1;

    	while(l2!=NULL)
        {
            l1->val=(l1->val+l2->val)%10;
            l1=l1->next;
            l2=l2->next;
        }
        
        return head;
    }

};