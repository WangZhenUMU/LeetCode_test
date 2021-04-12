/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
	struct ListNode* pCurrent = node->next;
	node->val = pCurrent->val;
	node->next = pCurrent->next;
	free(pCurrent);
	return;
}