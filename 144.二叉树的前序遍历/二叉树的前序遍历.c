void prevTraversal(struct TreeNode* root,int ret[],int* retSize)
 {
     if(NULL==root)
     {
         return ;
     }
     ret[(*retSize)++]=root->val;
     prevTraversal(root->left,ret,retSize);
     prevTraversal(root->right,ret,retSize);
 }
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* ret = (int*)malloc(sizeof(int)*100);
    *returnSize = 0;
    prevTraversal(root,ret,returnSize);
    return ret;
}