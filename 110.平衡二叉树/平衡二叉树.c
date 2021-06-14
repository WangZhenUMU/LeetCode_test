// ��������
// ���������ȵ�ͬʱ�ж��Ƿ�Ϊ�߶�ƽ�������
int deep(struct TreeNode* root, bool* isB)
{
    if(root)
    {
        int ldeep = deep(root->left, isB);
        int rdeep = deep(root->right, isB);
        // ������������ĸ߶Ȳ�ľ���ֵ����1����Ϊƽ�������
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