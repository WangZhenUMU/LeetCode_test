/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
if(NULL==head || NULL==head->next)
    return head;
//创建一个带头结点的新链表,并将原链表中的头结点取出，插入新链表。
struct ListNode*  newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
//检查是否开辟成功
if(NULL==newhead)
{
    assert(0);
}
newhead->next=head;
struct ListNode* pcurrent=head->next;//定义一个指针指向原链表的第二个元素
struct ListNode* prev=NULL;
struct ListNode* pnext;
newhead->next->next=NULL;
//依次将原链表中的元素按顺序插入链表
while(pcurrent)
{
    prev=newhead;
    pnext=pcurrent->next;
    //判断是否到达需要插入的位置，如果没有，prev指针后移，反之则插入结点
    while(prev->next!=NULL && prev->next->val<pcurrent->val)
    {
        prev=prev->next;
    }
    //插入结点
    pcurrent->next=prev->next;
    prev->next=pcurrent;
    //pcurrent指针后移
    pcurrent=pnext;
}
//释放掉自己定义在堆区的内存，防止内存泄漏。
head=newhead->next;
free(newhead);
return head;
}