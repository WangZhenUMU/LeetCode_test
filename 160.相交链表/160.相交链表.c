/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //�ȷֱ�������������������ĳ��ȡ�
    //Ȼ�󽫽ϳ����������|countA-countB|����㣬ʹ���β�����롣
    //Ȼ��������������Ԫ�����ν��бȽϣ�������ֽ����ͬ���򷵻ؽ��ĵ�ַ��
    int countA=0;
    int countB=0;
    struct ListNode* pcurrentA=headA;
    struct ListNode* pcurrentB=headB;
    //-------����������������---------
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
    //-------�������β������--------
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
    //--------�Ƚ�������֮��Ľ��------
    while(pcurrentA)
    {
        if(pcurrentA==pcurrentB)
        return pcurrentA;
        pcurrentA=pcurrentA->next;
        pcurrentB=pcurrentB->next;
    }
    return NULL;
}