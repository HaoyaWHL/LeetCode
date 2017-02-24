// All of the discussion 
// https://discuss.leetcode.com/category/156/sort-list
// I think I should make a study of this question.


// https://discuss.leetcode.com/topic/3085/my-o-n-log-n-time-o-1-space-solution
// I don't know the meaning of the virtual_head(0)
// this code also use function min() , I don't know I can use it before!

/*
Nice problem. I use a non-recurisve way to write merge sort.
For example, the size of ListNode is 8,

Round #1 block_size = 1

(a1, a2), (a3, a4), (a5, a6), (a7, a8)

Compare a1 with a2, a3 with a4 ...

Round #2 block_size = 2

(a1, a2, a3, a4), (a5, a6, a7, a8)

merge two sorted arrays (a1, a2) and (a3, a4), then merge tow sorted arrays(a5, a6) and (a7, a8)

Round #3 block_size = 4

(a1, a2, a3, a4, a5, a6, a7, a8)

merge two sorted arrays (a1, a2, a3, a4), and (a5, a6, a7, a8)

No need for round #4 cause block_size = 8 >= n = 8
*/

class Solution {
public:
    int count_size(ListNode *node){
        int n = 0;
        while (node != NULL){
            node = node->next;
            ++n;
        }
        return n;
    }
    ListNode *sortList(ListNode *head) {
        int block_size = 1, n = count_size(head), iter = 0, i = 0, a = 0, b = 0;
        ListNode virtual_head(0);
        ListNode *last = NULL, *it = NULL, *A = NULL, *B = NULL, *tmp = NULL;
        virtual_head.next = head;
        while (block_size < n){
            iter = 0;
            last = &virtual_head;
            it = virtual_head.next;
            while (iter <  n){
                a = min(n - iter, block_size);
                b = min(n - iter - a, block_size);
                
                A = it;
                if (b != 0){
                    for (i = 0; i < a - 1; ++i) it = it->next;
                    B = it->next;
                    it->next = NULL;
                    it = B;
                    
                    for (i = 0; i < b - 1; ++i) it = it->next;
                    tmp = it->next;
                    it->next = NULL;
                    it = tmp;
                }
                
                while (A || B){
                    if (B == NULL || (A != NULL && A->val <= B->val)){
                        last->next = A;
                        last = last->next;
                        A = A->next;
                    } else {
                        last->next = B;
                        last = last->next;
                        B = B->next;
                    }
                }
                last->next = NULL;
                iter += a + b;
            }
            block_size <<= 1;
        }
        return virtual_head.next;
    }
};