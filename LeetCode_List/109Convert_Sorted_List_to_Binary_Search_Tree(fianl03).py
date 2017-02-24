# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        if head is None: return None
        slow,fast,prev=head,head,None
        while fast and fast.next:
            prev,slow,fast=slow,slow.next,fast.next.next

        node=TreeNode(slow.val)

        if prev:
            prev.next=None
        else:
            head=None

        node.left=self.sortedListToBST(head)
        node.right=self.sortedListToBST(slow.next)

        return node
