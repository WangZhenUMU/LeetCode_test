/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        //创建俩带头结点的单向链表分别用来存放大于等于X和小于x的结点。
        ListNode* Head1=(ListNode*)malloc(sizeof(ListNode));
        ListNode* Head2=(ListNode*)malloc(sizeof(ListNode));
        ListNode* pcurrent1=Head1;
        ListNode* pcurrent2=Head2;
        //遍历原链表，将原链表的各个结点分别尾插入俩个新链表
        while(pHead)
        {
            if(pHead->val<x)
            {
                pcurrent1->next=pHead;
                pcurrent1=pcurrent1->next;
            }
            else
            {
                pcurrent2->next=pHead;
                pcurrent2=pcurrent2->next;
            }
            pHead=pHead->next;
        }
        //将俩个链表链接在一起
        //同时释放掉开辟在堆区的Head1，Head2，防止内存泄漏。
        pcurrent2->next=NULL;
        pcurrent1->next=Head2->next;
        pHead=Head1->next;
        free(Head1);
        free(Head2);
        return pHead;
        }
};