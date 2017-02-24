/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // NOTES:我用的是数组的方法储存前半部分 然后进行比较 （用C） 
 // 与C++中采用vector或者stack的方法是一样的
 // 而且空间复杂度都超了

//newNote 相当于把整个链表的值压入堆栈 比较一次 实际上比较一半的节点就行 方法是只存入一半节点的值
// 可以这么做 tmp=tmp->next 在st.size()这个范围内判定

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        stack<int> st;
        struct ListNode *tmp = head;
        while(tmp)
        {
            st.push(tmp->val);
            tmp = tmp->next;
        }

    while(head)
    {
        if(head->val != st.top() ) return false;
        head = head->next;
        st.pop();
    }
        return true;
    }
};