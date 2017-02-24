// 86. Partition List
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
    ListNode* partition(ListNode* head, int x) {
        
        if (head==NULL)  {  return NULL;  }
     

        ListNode *s=new ListNode(0);
        ListNode *h=new ListNode(0);
        ListNode *small=s,*high=h; //容易出错的地方，small前面写了*，但是high忘了，下次记住。。。。
        ListNode *cur=head;


        while(cur!=NULL)
    	{
	        if( (cur->val) < x)
	        {
	        	s->next = cur;
	        	s=s->next;
	        }
	        else
	        {
	        	h->next = cur;
	        	h=h->next;
	        }
	        cur=cur->next;	
    	}

    	h->next=NULL;
    	s->next=high->next;

    	return small->next;

    }
};