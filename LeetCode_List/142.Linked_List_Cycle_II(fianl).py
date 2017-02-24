# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Floyd's cycle detection algorithm, also known as the hare-tortoise algorithm.

class Solution(object):
    def detectCycle(self, head):
        if head is None: return None
        hare=turtle=head
        while hare!=None:
            turtle=turtle.next
            hare=hare.next
            if hare is None: return None    
            hare=hare.next
            if hare=turtle:
                turtle=head
                while turtle!= hare:
                    hare=hare.next
                    turtle=turtle.next
                return hare
            return None
        