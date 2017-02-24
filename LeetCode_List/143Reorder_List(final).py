# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

def _splitList(head):
	fast=slow=head
	while fast and fast.next:
		slow,fast=slow.next,fast.next.next
	middle=slow.next
	slow.next=None

	return head,middle
    
def _reverseList(head):
	last=None
	currentNode=head

	while currentNode:
		nextNode=currentNode.next
		currentNode.next=last
		last=currentNode
		currentNode=nextNode

	return last

def _mergeLists(a,b):
	tail=head=a
	a=a.next

	while b:
		tail.next=b
		tail=tail.next
		b=b.next
		if a:
			a,b=b,a

	return head
   			


class Solution:

    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if not head or not head.next:
        	return 

        a,b=_splitList(head)
        b=_reverseList(b)
        head=_mergeLists(a,b)

