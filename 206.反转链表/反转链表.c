struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *newhead=NULL;
    struct ListNode *pcurrent=head;
    struct ListNode *pnext=NULL;
    while(pcurrent)
    {
        pnext=pcurrent->next;
        pcurrent->next=newhead;
        newhead=pcurrent;
        pcurrent=pnext;
    } 
    return newhead;
}