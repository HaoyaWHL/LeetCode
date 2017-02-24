/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //Given a linked list, determine if it has a cycle in it.

//NOTE:快慢指针的使用，暴露初一个小问题，就是第一个if语句中，对head的判定要在head->next判定之前，判定的逻辑顺序！！！！！

 class Solution {
 public:
     bool hasCycle(ListNode *head) {

         if ( (head == NULL) ||  (head->next == NULL) ) {   return false;  }

         ListNode* fast=head;
         ListNode* slow=head;

         while((fast->next != NULL) && (fast->next->next !=NULL))
         {
             fast=fast->next->next;
             slow=slow->next;
             if (slow == fast) {
                 return true;
             }
         }

         return false;

     }
 };
