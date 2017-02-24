// 23. Merge k Sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 自己写的 体现自己的一个思路 但是编译无法通过 
 // 这是最笨最普通的思想。。。。。。

// 当然无法通过 因为for中取最小取的永远是最后两个list中最小的那个
// while最后的if语句写错了 如果为null 肯定是删除erase操作 而不是push_back添加操作

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    	ListNode *dummy=new ListNode(0);
    	ListNode *fakeHead=dummy;

		while(!lists.empty())
		{
	    	int loc=0;
	    	for (int i = 0; i < lists.size()-1; ++i)
	    	{
	    		if ((lists(i)->val) < (lists(i+1)->val))
	    		{ loc=i; }
	    		else
	    		{ loc=i+1; } 
	    	}

	    	dummy->next=lists(loc);
	    	list(loc)=lists(loc)->next;
	    	dummy=dummy->next;

	    	if (lists(loc)==NULL)
	    	{
	    		lists.push_back(loc);
	    	}
		}

		return fakeHead->next;
    }
};