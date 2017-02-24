# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy=ListNode(0)

        while head:
        	iter=dummy;
        	while iter.next and iter.next.val<head.val:
        		iter=iter.next
        	tmpNext=head.next
        	head.next=iter.next
        	iter.next=head
        	head=tmpNext

        return dummy.next
