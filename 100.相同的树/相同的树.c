bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(NULL == p && NULL == q)
        return true;
    if(NULL == p || NULL == q)
        return false;
    if(p->val != q->val)
        return false;
    if(isSameTree(p->left,q->left)&&isSameTree(p->right,q->right))
        return true;
    return false;
}