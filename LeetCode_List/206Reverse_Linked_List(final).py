# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 啊哈哈哈 牛逼如我 想了一下那个回文链表的list怎么写 就一次通过了！

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        rev=None
    	while head:
    		rev,rev.next,head=head,rev,head.next
    	return rev