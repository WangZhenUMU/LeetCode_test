bool isUnivalTree(struct TreeNode* root)
{
    if(NULL==root)
    return true;
    if((NULL!=root->left&&root->left->val!=root->val)
    || (NULL!=root->right&&root->right->val!=root->val))
        return false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}