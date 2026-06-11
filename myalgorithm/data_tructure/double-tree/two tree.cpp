#include<iostream>
using namespace std;
#define MAXSIZE 100
#define ElemType char
//给你一个二叉树的数组存储要求给出链式存储并且输出中序遍历的结果
struct TreeNode
{
   ElemType data;
   TreeNode* l;
   TreeNode* r;
};
typedef TreeNode* BiTree;
int index = 0;
char str[] = "ABDH#K###E##CFI###G#J##";//树的数组存储
void creat(BiTree &T) 
{
    ElemType ch;
    ch = str[index++];
    if(ch == '#')
    {
        T=nullptr;
    }
    else 
    {
        T = new(TreeNode);
        T  -> data = ch;
        creat(T->l);
        creat(T->r); 
    }
}
void porder(BiTree &T)//中序遍历
{
    if(T == nullptr)
        return;
    
    porder(T->l);
    cout<<T->data<<' ';
    porder(T->r);
}
int main()
{
    BiTree t = new(TreeNode);
    creat(t);
    porder(t);
}
//已知前序遍历和后续遍历，是不能确定一颗二叉树的，其余知道两个即可