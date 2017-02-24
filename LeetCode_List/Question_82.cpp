/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 检查不出错误 只能理解为运行超时 if和while的结合所导致
// 一个非常小的细节
// !!!!!!!!!!!!!!!!!!!
// 32行while的判定条件写错了顺序 为什么！ 因为当then是NULL的时候
// 无法进行val的判定 这个顺序是从左到右的啊！！！！！！！

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* cur=prev->next;
        ListNode* then=NULL;

        while(cur && cur->next)
        {
            then=cur->next;
            if (cur->val==then->val)
            {
                while(cur->val==then->val && then!=NULL)
                    {  then=then->next;  }
                cur=then;
                prev->next=cur;
            }
            else
            {
                prev=cur;
                cur=cur->next;     
            }
        }

        return dummy->next;
    }
};