/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//Return a deep copy of the list.什么是Deep copy，完全拷贝整个链表？

// intuitive adj. 直觉的；凭借直觉获取的

// The algorithm is composed of the follow three steps which are also 3 iteration rounds.

// Iterate the original list and duplicate each node. The duplicate of each node follows its original immediately.
// 迭代原链表，复制每个节点信息，复制的每个节点信息就跟在原节点之后
// Iterate the new list and assign the random pointer for each duplicated node.
// 迭代出新的链表，分配随机指针给每个复制的节点
// Restore the original list and extract the duplicated nodes.
// 复制原链表，抓出那些复制出来的节点


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	
    	if (head==NULL)	{ return NULL; }

    	RandomListNode *newHead,*l1,*l2;

    	for (l1=head; l1!=NULL ; l1=l1->next->next)
    	{
    		l2=new RandomListNode(l1->label);
			l2->next=l1->next;
			l1->next=l2;
    	}

    	// step2:copy the information of the random pointer
    	newHead=head->next;
    	for(l1=head; l1!=NULL; l1=l1->next->next)
    	{
    		if (l1->random!=NULL)   { l1->next->random=l1->random->next; } //指向同一处
    	}

    	// step3:seperate the list,return the copy list2 
    	for (l1=head; l1!=NULL; l1=l1->next)
    	{
    		l2=l1->next;
    		l1->next=l2->next;
    		if (l2->next!=NULL)  {	l2->next=l1->next->next; }    	
 	    }

 	   return newHead;

    }
};
