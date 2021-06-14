#include <stdio.h>
#include <malloc.h>
typedef struct BinTreeNode
{
    char data;
    struct BinTreeNode* left;
    struct BinTreeNode* right;
}BinTreeNode;
BinTreeNode* CreatBinTree(char* str, int* pos)
{
    if(str[*pos]!= '#')
    {
        BinTreeNode*root=(BinTreeNode*)malloc(sizeof(BinTreeNode));
        root->data = str[*pos];
        ++(*pos);
        root->left=CreatBinTree(str,pos);
        ++(*pos);
        root->right=CreatBinTree(str,pos);
        return root;
    }
    else
        return NULL;// 如果是空节点，则返回NULL
}
//中序遍历
void Inorder(BinTreeNode* root)
{
    if(root)
    {
        Inorder(root->left);
        printf("%c ", root->data);
        Inorder(root->right);
    }
}

int main()
{
    char str[101];
    int i = 0;
    scanf("%s", str);
    BinTreeNode* root = CreatBinTree(str, &i);
    Inorder(root);
    printf("\n");
    return 0;
}