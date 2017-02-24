/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead,*l1,*l2;
        if (head==NULL) return head;
        for ( l1=head;l1!=NULL;l1=l1->next->next )
        {
            l2=new RandomListNode(l1->label);
            l2->next=l1->next;
            l1->next=l2;
        }

        newHead=head->next;
        for( l1=head;l1!=NULL;l1=l1->next->next )
        {
            // 这里对random的理解 这是一个指针 它为真的时候里面存了地址 所以就是random->next的信息
            if(l1->random) { l1->next->random=l1->random->next; }
        }

        for(  l1=head,l2=head->next;l1!=NULL;l1=l1->next,l2=l2->next  )
        {
            l1->next=l1->next->next;
            if(l2->next)  l2->next=l2->next->next; 
            //此处一定要判断l2->next的情况 仔细想想就知道 l2->next如果没有值 l2->next->next就无从谈起
        }

        return newHead;
    }
};