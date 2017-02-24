/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head==NULL) return NULL;

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        // 也是个相当不错的答案 注意这个prev的if判定不能少 假设list只有一个节点的时候 就知道if的作用了 
        // 结合36行node的赋值一起看就能明白
        // 还有个值得注意的地方就是25行prev的初始化为null 以后这里成为习惯

        TreeNode* node=new TreeNode(slow->val);

        if(prev!=NULL){
            prev->next=NULL;
        }
        else{
            head=NULL;
        }

        node->left=sortedListToBST(head);
        node->right=sortedListToBST(slow->next);

        return node;
    }
};
