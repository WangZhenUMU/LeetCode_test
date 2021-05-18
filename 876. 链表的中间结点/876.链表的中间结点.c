/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
//利用快慢指针，快指针一次走俩个结点，慢指针一次走一个结点，当快指针到达末尾，慢指针刚好到达链表中间结点。
    if(NULL==head||NULL==head->next)
        return head;
    struct ListNode* fast=head;
    struct ListNode* slow=head;
    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}