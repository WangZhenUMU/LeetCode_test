/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    //当一个链表为空或者只有一到俩个结点时，链表无法构成环，所以不存在开始进入环的点
    if (head == NULL || head->next == NULL || head->next->next == NULL) 
     {
        return NULL;
    }
    //定义快慢指针判断链表是否存在环
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            break;
        }
    }
    //如果不存在，返回NULL
    if(fast!=slow)
        return NULL;
    //反之令慢指针指向头。
    slow=head;
    //快慢指针每次各走一步，当他们俩再次指向同一个结点时。那个结点就是开始入环的第一个结点
    while(slow!=fast)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return fast;
}