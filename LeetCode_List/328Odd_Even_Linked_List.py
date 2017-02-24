# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if (head==None) or (head.next==None) :
        	return head

        odd,evenHead=head,head.next
        even=evenHead
     

        while even and even.next:
        	odd.next=even.next
        	odd=even.next
        	even.next=odd.next
        	even=odd.next

        odd.next=evenHead

        return head


#注释：第16行这样的一行内执行多次赋值 是同时进行的 相当于传入的是一个元组
#为了便于再次阅读时容易理解 所以我并没有把16行同17行合并
#if及while用的是 and 和 or 