struct ListNode* FindKthToTail(struct ListNode* pListHead,int k) {
    //��������ָ�룬���ÿ�ָ����k���ڵ㣬Ȼ���ָ�����ָ��һ���ߣ�
    //����ָ��ָ��NULLʱ����ָ��պ�ָ���k���ڵ�
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