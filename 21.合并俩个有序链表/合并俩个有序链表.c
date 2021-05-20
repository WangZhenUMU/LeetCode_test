/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    //���ж��Ƿ�������Ϊ�գ�����У��򷵻�����һ������
    if(l1==NULL)
    return l2;
    if(l2==NULL)
    return l1;
    struct ListNode* pcurrent1=l1;
    struct ListNode* pcurrent2=l2;
    //�����µ�����ͷ���
    struct ListNode* newlist=NULL;
    struct ListNode* newhead=NULL;
    //�����������е�Ԫ�ذ������бȽϣ�������β��ķ�������������
    while(pcurrent1&&pcurrent2)
    {
        if(pcurrent1->val<pcurrent2->val)
        {
            if(newhead==NULL)
            {
                newhead=newlist=pcurrent1;
                pcurrent1=pcurrent1->next;
            }
            else
            {
                newlist->next=pcurrent1;
                pcurrent1=pcurrent1->next;
                newlist=newlist->next;
            }
        }
        else
        {
            if(newhead==NULL)
            {
                newhead=newlist=pcurrent2;
                pcurrent2=pcurrent2->next;
            }
            else
            {
                newlist->next=pcurrent2;
                pcurrent2=pcurrent2->next;
                newlist=newlist->next;
            }
        }
    }
    //�������1���꣬������2������δ��Ԫ�ز嵽����ĩβ
    if(NULL==pcurrent1)
    {
        newlist->next=pcurrent2;
    }
    //�������2���꣬������1������δ��Ԫ�ز嵽����ĩβ
    else
    {
        newlist->next=pcurrent1;
    }
    //����������ͷ���ĵ�ַ��
    return newhead;
}