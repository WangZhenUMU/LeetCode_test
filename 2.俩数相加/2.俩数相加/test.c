//���������ǿյ�������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ�������ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢һλ���֡�
//���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
//����Լ���������� 0 ֮�⣬���������������� 0��ͷ��
//ֻд�˺���ûд��������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
};
  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	  int pro = 0;//�洢��λֵ
	  struct ListNode* pCurrent1 = l1;
	  struct ListNode* pCurrent2 = l2;
	  struct ListNode* NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	  NewNode->next = NULL;
	  struct ListNode* NewList = NewNode;
	  while (pCurrent1 != NULL || pCurrent2 != NULL || pro != 0)
	  {
		  int t = (pCurrent1 != NULL ? pCurrent1->val : 0) + (pCurrent2 != NULL ? pCurrent2->val : 0) + pro;
		  NewNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		  NewNode = NewNode->next;
		  NewNode->val = t % 10;
		  NewNode->next = NULL;
		  pro = t / 10;
		  if (pCurrent1 != NULL)
			  pCurrent1 = pCurrent1->next;
		  if (pCurrent2 != NULL)
			  pCurrent2 = pCurrent2->next;
	  }
	  return NewList->next;
  }