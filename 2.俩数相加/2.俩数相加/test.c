//给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0开头。
//只写了函数没写完整程序。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
};
  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	  int pro = 0;//存储进位值
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