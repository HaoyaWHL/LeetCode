// 25. Reverse Nodes in k-Group
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 很有难度的一个题目，k个节点一组进行反向，最后如果不满足k个节点，保持原来顺序
 // 我的思路仅仅搭出一个框架 写不下去了 代码能力不够

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (head==NULL || head->next==NULL) {  return head;  }

		int size=0;
		ListNode *itr=head;
		while(itr!=NULL) 
		{
			itr=itr->next; 
			size++;
		}

		int numOfGroup=size/k; //组数，如果为0，只能说明k>size，就一组，不用反向，直接返回head就行
		int numOfLast=size%k;  //最后一组个数，是否有剩余

		ListNode *dummy=new ListNode(0);
		dummy->next=head;
		ListNode *preTail=dummy;
		ListNode *curHead=head;
		

		if (numOfGroup==0)
		{
			return head;
		}
		else//reverse nodes in K-Group
		{
			while(numOfGroup!=0)
			{

				numOfGroup--;
			}
		}


		if (numOfLast==0)
		{
			continue;
		}
		else//solve the last group which the number of nodes is less than k
		{
			/* code */
		}


    }




    ListNode* reverseList(ListNode* head) {
        if ((head == NULL) || (head->next == NULL) )  {   return head;   }
        ListNode *p=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return p;
    }

};