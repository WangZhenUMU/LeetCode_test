struct ListNode* FindKthToTail(struct ListNode* pListHead,int k) {
    //创建快慢指针，先让快指针走k个节点，然后快指针和慢指针一起走，
    //当快指针指向NULL时，慢指针刚好指向第k个节点
    struct ListNode* fast=pListHead;
    struct ListNode* slow=pListHead;
    while(k--)
    {
        if(NULL==fast)
            return NULL;
        fast=fast->next;
    }
    while(fast)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}