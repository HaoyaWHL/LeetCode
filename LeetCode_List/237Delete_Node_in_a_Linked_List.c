/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 //this question means given the node 2, and you are supposed to delete the node 2
 
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}