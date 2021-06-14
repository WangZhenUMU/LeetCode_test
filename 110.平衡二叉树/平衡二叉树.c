// 求最大深度
// 在求最大深度的同时判断是否为高度平衡二叉树
int deep(struct TreeNode* root, bool* isB)
{
    if(root)
    {
        int ldeep = deep(root->left, isB);
        int rdeep = deep(root->right, isB);
        // 如果两个子树的高度差的绝对值超过1，则不为平衡二叉树
        if(fabs(ldeep-rdeep)>1)
        {
            *isB = false;
        }
        return fmax(ldeep, rdeep) + 1;
    } 
    return 0;
}

bool isBalanced(struct TreeNode* root){
    bool isB = true;
    if(root)
        deep(root,&isB);
    return isB;
}