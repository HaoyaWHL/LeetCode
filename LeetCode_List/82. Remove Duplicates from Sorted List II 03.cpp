class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode fakeHead(0);
        fakeHead.next = head;
        ListNode* pre = &fakeHead;
        ListNode* p = pre->next;
        while (p ) {
            ListNode* pn = p->next;
            
            if (pn && p->val == pn->val) {
                // move pn to next different value
                while (pn && p->val == pn->val) {
                    pn = pn->next;
                }
                
                p = pn;
                pre->next = p;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
        return fakeHead.next;
    }
};