bool CompSymmetric(struct TreeNode* p,struct TreeNode* q){
    if(p==NULL && q==NULL)
        return true;
    if(p==NULL || q==NULL)
        return false;
    if(p->val!=q->val)
        return false;
    return CompSymmetric(p->left,q->right) && CompSymmetric(p->right,q->left);
}
bool isSymmetric(struct TreeNode* root){
    if(NULL==root)
        return true;
    else
        return CompSymmetric(root->left,root->right);
}