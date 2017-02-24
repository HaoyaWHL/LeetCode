class Solution(object):
    def sortList(self, head):
        if not head or not head.next:
            return head

        fast=slow=head

        while fast and fast.next:
            prev=slow
            slow,fast=slow.next,fast.next.next
        prev.next=None

        l=self.sortList(head)
        r=self.sortList(slow)

        return self.merge(l,r)

    def merge(self,l,r):
        if not l or not r:
            return l or r

        if l.val > r.val:
            l,r=r,l

        pre=head=l
        l=l.next

        while l and r:
            if l.val<r.val:
                pre.next=l
                l=l.next
            else:
                pre.next=r
                r=r.next
            pre=pre.next

        pre.next=l or r
        return head