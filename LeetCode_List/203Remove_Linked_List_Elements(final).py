# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 可以编译通过 但是runtime error


class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if head==None:
        	return head
        head.next=self.removeElements(head.next,val):
        if head.val==val:
        	return head.next
        else:
        	return head