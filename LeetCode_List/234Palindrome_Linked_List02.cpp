/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// the space complexity is O(1)

class Solution {
private:
    ListNode *lst;
public:
    bool judge(ListNode *head)
    {
        if(head == NULL) return true;

        if(judge(head->next) == false) return false;

        if(lst->val != head->val) return false;
        else{
            lst = lst->next;
            return true;
        }
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        lst = head;

        return judge(head);
    }
};