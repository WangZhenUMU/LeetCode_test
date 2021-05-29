void inTraversal(struct TreeNode* root,int* ret,int* returnSize)
{
    if(NULL==root)
    {
        return;
    }
    inTraversal(root->left,ret,returnSize);
    ret[(*returnSize)++]=root->val;
    inTraversal(root->right,ret,returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *ret=(int*)malloc(sizeof(int)*100);
    *returnSize=0;
    inTraversal(root,ret,returnSize);
    return ret;
}