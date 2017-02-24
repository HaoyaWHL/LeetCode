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

// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 // What is the meaning of "a height balanced BST"

// https://discuss.leetcode.com/topic/3286/share-my-code-with-o-n-time-and-o-1-space
 
 // One of the best answer,I record it in my notebook


// list 依次访问每个点 放入平衡树中，而平衡树的遍历是从左至右的遍历
// 符合这个list的从head开始到tail的读取顺序
// 1-2-3-4-5-6
// 			         4
	        // 2       	   5
 		// 1       3    6




class Solution {
public:
	ListNode* list;
	int count(ListNode *node)
	{
		int size=0;
		while(node!=NULL)
		{
			size++;
			node=node->next;
		}
		return size;
	}


	TreeNode* generate(int n)
	{
		if(n==0) { return NULL; }
		TreeNode* node=new TreeNode(0);
		node->left=generate(n/2);
		node->val=list->val;
		list=list->next;
		node->right=generate(n-n/2-1);
		return node;
	}



    TreeNode* sortedListToBST(ListNode* head) {
        this->list=head;// 非常重要 因为这样才能把公有变量list与head相关联
        return generate(count(head));
    }
};



