// this code is very nice , and it takes me 5 days 

 struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *evenHead,*odd,*even,*p;

    //odd is 1 3 5 7 , even is 2 4 6 8
    if ( (NULL == head) || ( NULL == head->next ) ) {  return head;    }

    // the first step:initialization , at the start ponit
    odd=head;
    evenHead=odd->next;
    even=evenHead;

    // the second step:start to iteration 
    while((NULL != even) && (NULL != even->next))
    {
        odd->next = even->next;
        odd=even->next;
        even->next = odd->next;
        even = odd->next;
    }

    odd->next = evenHead; 

    return head;
 }

