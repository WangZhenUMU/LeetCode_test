/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    //先判断是否有链表为空，如果有，则返回另外一个链表
    if(l1==NULL)
    return l2;
    if(l2==NULL)
    return l1;
    struct ListNode* pcurrent1=l1;
    struct ListNode* pcurrent2=l2;
    //创建新的链表头结点
    struct ListNode* newlist=NULL;
    struct ListNode* newhead=NULL;
    //对俩个链表中的元素挨个进行比较，依次用尾插的方法插入新链表
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
    //如果链表1插完，则将链表2中所有未插元素插到链表末尾
    if(NULL==pcurrent1)
    {
        newlist->next=pcurrent2;
    }
    //如果链表2插完，则将链表1中所有未插元素插到链表末尾
    else
    {
        newlist->next=pcurrent1;
    }
    //返回新链表头结点的地址。
    return newhead;
}