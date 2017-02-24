// 长见识了，while(count-- > 0)中count--优先进行 ，然后再判断>0

// 讲道理 这份递归迭代的代码思想很牛逼 值得慢慢体会

// https://discuss.leetcode.com/topic/7126/short-but-recursive-java-code-with-comments
// java但是while(count-- > 0) 中如果count的初始值为2 总觉得这里只会循环1次 也是是因为对java的不熟悉
public ListNode reverseKGroup(ListNode head, int k) {
    ListNode curr = head;
    int count = 0;
    while (curr != null && count != k) { // find the k+1 node
        curr = curr.next;
        count++;
    }
    if (count == k) { // if k+1 node is found
        curr = reverseKGroup(curr, k); // reverse list with k+1 node as head
        // head - head-pointer to direct part, 
        // curr - head-pointer to reversed part;
        while (count-- > 0) { // reverse current k-group: 
            ListNode tmp = head.next; // tmp - next head in direct part
            head.next = curr; // preappending "direct" head to the reversed list 
            curr = head; // move head of reversed part to a new node
            head = tmp; // move "direct" head to the next node in direct part
        }
        head = curr;
    }
    return head;
}
