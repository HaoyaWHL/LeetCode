#a stupid question

#也许这是唯一一份值得看的代码 应该是采用了this指针 把两行缩减到了一行！
# void deleteNode(struct ListNode* node) {
#     *node = *node->next;
# }


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val=node.next.val
        node.next=node.next.next