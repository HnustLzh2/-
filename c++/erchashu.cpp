#include <bits/stdc++.h>
using namespace std;
struct elems
{
    char key;
    int datas;
};
/**1.如果删除的是叶子节点就直接删（把叶子的节点的双亲节点改为空）

2.删除的节点只有左子树或者右子树（用左孩子或者右孩子替换节点）

3.删除的节点左右子树都有（左子树的最大的节点，有用最大的节点替换被删除的节点，最大的节点就左子树的最右下的树；也可以用后面的最小值去替换）**/

typedef struct erchashu
{
    int data;
    struct erchashu *lchild, *rchild;
} BSTNode, *BSTtree;

void charu(BSTtree &T, int e)
{
    if (!T)
    {
        T = new BSTNode;
        T->data = e;
        T->lchild = T->rchild = NULL;
    }
    else if (e > T->data)
    {
        charu(T->rchild, e);
    }
    else
    {
        charu(T->lchild, e);
    }
}

BSTtree chazhao(BSTtree &T, int key)
{
    if ((!T) || key == T->data)
    {
        return T;
    }
    else if (key > T->data)
    {
        return chazhao(T->rchild, key);
    }
    else
    {
        return chazhao(T->lchild, key);
    }
}

void Deletelr(BSTtree &T, BSTtree &Tl)
{
    BSTNode *q;
    if (Tl->rchild != NULL)
    {
        Deletelr(T, Tl->rchild);
    }
    else
    {
        T->data = Tl->data;
        q = Tl;
        Tl = Tl->lchild;
        delete q;
    }
}

int deletes(BSTtree &T, int key)
{
    if (T == NULL)
    {
        return 0;
    }
    BSTtree S = chazhao(T, key);
    BSTNode *q = new BSTNode;
    if (S->lchild == NULL)
    {
        q = S;
        S = S->rchild;
        delete q;
        return 1;
    }
    else if (S->rchild == NULL)
    {
        q = S;
        S = S->lchild;
        delete q;
        return 1;
    }
    else
    {
        Deletelr(S, S->lchild);
        return 1;
    }
}

void Printtree(BSTtree &T, int i)
{
    if (!T)
        return;
    Printtree(T->lchild, i + 1); 
    cout << i << "." << T->data << " "; // i表示元素所在的层数
    Printtree(T->rchild, i + 1);
}

int main()
{
    BSTtree T = NULL;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        charu(T, x);
    }
    Printtree(T, 1);
    return 0;
}