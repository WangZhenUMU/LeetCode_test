void postTraversal(struct TreeNode* root,int ret[],int* retSize)
 {
     if(NULL==root)
     {
         return ;
     }
     postTraversal(root->left,ret,retSize);
     postTraversal(root->right,ret,retSize);
     ret[(*retSize)++]=root->val;
 }
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* ret = (int*)malloc(sizeof(int)*100);
    int size = 0;
    postTraversal(root, ret, &size);
    *returnSize = size;
    return ret;
}