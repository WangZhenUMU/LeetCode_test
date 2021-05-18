/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //先分别遍历俩链表算出俩链表的长度。
    //然后将较长的链表遍历|countA-countB|个结点，使其从尾部对齐。
    //然后将俩个链表后面的元素依次进行比较，如果发现结点相同，则返回结点的地址。
    int countA=0;
    int countB=0;
    struct ListNode* pcurrentA=headA;
    struct ListNode* pcurrentB=headB;
    //-------遍历链表算链表长度---------
    while(pcurrentA)
    {
        pcurrentA=pcurrentA->next;
        countA++;
    }
    while(pcurrentB)
    {
        pcurrentB=pcurrentB->next;
        countB++;
    }
    pcurrentA=headA;
    pcurrentB=headB;
    //-------将链表从尾部对齐--------
    if(countA>countB)
    {
        int i=countA-countB;
        while(i--)
        {
            pcurrentA=pcurrentA->next;
        }
    }
    else
    {
        int i=countB-countA;
        while(i--)
        {
            pcurrentB=pcurrentB->next;
        }
    }
    //--------比较俩链表之后的结点------
    while(pcurrentA)
    {
        if(pcurrentA==pcurrentB)
        return pcurrentA;
        pcurrentA=pcurrentA->next;
        pcurrentB=pcurrentB->next;
    }
    return NULL;
}