/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//总而言之 这一题的几乎所有高票答案 思想是一致的

// 这份代码的思想就是不断的二分 每相邻两个节点进行排序  最后把相邻的两个已经排序的链表进行合并（通过比较大小合并）
// 3-1-2-4  拆成3 1     2 4
// 再然后是1-3   2-4
// 再来依次比较两个list的val 得到 1-2  -3 -4 OK

// 这个方法出现的结果是runtime error 但是思路已经完全GET 不过空间复杂度貌似O(nlogn) 超了

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
    	if(head==NULL || head->next==NULL) return head;

    	ListNode *prev=NULL;
    	ListNode *slow=head;
    	ListNode *fast=head;

    	while(fast!=NULL && fast->next!=NULL)
    	{
    		prev=slow;
    		slow=slow->next;
    		fast=fast->next->next;
    	}

    	prev->next=NULL;

    	ListNode *l1=sortList(head);
    	ListNode *l2=sortList(slow);

    	return merge(l1,l2);
    }

    ListNode *merge(ListNode *l1,ListNode *l2){
    	ListNode *l=new ListNode(0);
    	ListNode *p=l;

    	while(l1!=NULL && l2!=NULL){
    		if (l1->val < l2->val)
    		{
    			p->next=l1;
    			l1=l1->next;
    		}
    		else{
    			p->next=l2;
    			l2->next=l2;
    		}
    		p=p->next;
    	}

    	if (l1!=NULL) { p->next=l1; }
    	if (l2!=NULL) { p->next=l2; }

    	return l->next;
    }
};



/*
这一份代码则是merge函数的进一步简化

    public ListNode merge(ListNode h1, ListNode h2){
        if(h1 == null){
            return h2;
        }
        if(h2 == null){
            return h1;
        }
        
        if(h1.val < h2.val){
            h1.next = merge(h1.next, h2);
            return h1;
        }
        else{
            h2.next = merge(h1, h2.next);
            return h2;
        }
        
    }
*/