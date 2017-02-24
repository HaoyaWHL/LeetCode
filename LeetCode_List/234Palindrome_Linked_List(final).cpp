// 这份代码思想很简单  
// 1、快慢指针找到中间节点
// 2、翻转中间结点之后的序列
// 3、比较前部分和后部分的节点值 并返回结果
// O(n) time and O(1) memory
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next==NULL)  { return true; }
        ListNode *fast=head;
        ListNode *slow=head;

        while(fast->next && fast->next->next)
        {
        	slow=slow->next;
        	fast=fast->next->next;
        }
        // 经过本人在草稿纸上的精密推算 2n+1或者2n长序列 slow->next总是指向后n个的第一个节点
        slow->next=reverseList(slow->next);

        ListNode* comparHead=slow->next;//后n长待比较序列的头节点 与前面的n长head进行比较

        while(comparHead){
        	if (head->val != comparHead->val) { return false;}
        	comparHead=comparHead->next;
        	head=head->next;        	
        }
        return true;
    }

    ListNode *reverseList(ListNode *head){
    	ListNode *pre=NULL;
    	ListNode *next=NULL;

    	while(head){
    		next=head->next;
    		head->next=pre;
    		pre=head;
    		head=next;
    	}

    	return pre;
    }

};