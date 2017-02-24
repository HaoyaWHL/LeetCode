/*You can prove that: say A length = a + c, B length = b + c, after switching pointer, 
pointer A will move another b + c steps, pointer B will move a + c more steps, 
since a + c + b + c = b + c + a + c, it does not matter what value c is. 
Pointer A and B must meet after a + c + b (b + c + a) steps. If c == 0, they meet at NULL.*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// https://discuss.leetcode.com/topic/28067/java-solution-without-knowing-the-difference-in-len/12
// https://discuss.leetcode.com/topic/5527/my-accepted-simple-and-shortest-c-code-with-comments-explaining-the-algorithm-any-comments-or-improvements
/*as for the answer in last web link, I thisk the first and the second judgement in while() is useless
because at the final of the while loop , you can see if (NULL == p1) , so p1 and p2 can never be the NULL;
this code can also judge the two link have no intersection,for the if judgement in while , if p1=p2=NULL ,it will return NULL=p1*/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    	ListNode *p1,*p2;
    	p1=headA;
    	p2=headB;

		if((NULL == p1) || (NULL == p2))  { return NULL; }

		while (p1 != p2)
		{
			p1=p1->next;
			p2=p2->next;

			if (p1 == p2) { return p1; }
			
			if (NULL == p1) { p1=headB; }
			if (NULL == p2) { p2=headA; }

		}
		
		return p1;

    }
};

// 利用两者经过距离相等
// 核心思想全是这个 当然用计算出具体距离 再balabala也未尝不可 
// 然后代码可以在这个基础上更加简化


/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1=headA;
        ListNode* p2=headB;

        while(p1!=p2)
        {
            p1= (p1==NULL) ? headB : p1->next;
            p2= (p2==NULL) ? headA : p2->next;
        }

        return p1;
    }
};
*/