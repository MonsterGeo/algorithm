#include <stdio.h>
#include <stdlib.h>


/*
//初始版本
typedef struct BSTree
{
    int data;
    int key;
    struct  BSTree* left;
    struct BSTree* right;
}bst;
*/


typedef struct BSTree
{
    int data;
    int key;
    struct BSTree* p;
    struct  BSTree* left;
    struct BSTree* right;
}bst, *Tree_Root;


bst* create_bstree(int key)
{
    bst* newNode = (bst*)malloc(sizeof(bst));
    if(newNode == NULL)
    {
        printf("create node fail/r/n");
        return 0;
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right= NULL;
    newNode->p = NULL;
    return newNode;
}

void INORDER_TREE_WALK(bst* T)
{
    if(T == NULL)
    {
        return;
    }
    INORDER_TREE_WALK(T->left);
    printf("%d ",T->key);
    INORDER_TREE_WALK(T->right);
}

bst* Tree_Search(bst* x,int k)
{
    if(x == NULL || k == x->key)
    {
        return x;
    }
    if(k < x->key)
    {
        return Tree_Search(x->left,k);
    }
    else
    {
        return Tree_Search(x->right,k);
    }
}

void Tree_insert(Tree_Root *T,bst* z) //T为头节点，使用二级指针方便修改
{
    bst *y = NULL; //记录头节点
    bst *x = *T; 

    while( x != NULL)
    {
        y = x;
        if(z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    z->p = y;
    if(y == NULL)
    {
        *T = z;
    }
    else if(z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
}


void Transplant(Tree_Root *T, bst* u, bst* v)
{
    if(u->p == NULL)
    {
        *T = v;
    }
    else if(u == u->p->left)
    {
        u->p->left = v;
    }
    else u->p->right = v;
    if(v != NULL)
    {
        v->p = u->p;
    }
}

bst* Tree_min(bst*x)
{
    while(x->left != NULL)
    {
        x = x->left;
    }
    return x;
}

void Tree_delete(Tree_Root *T,bst* z)
{
    bst *y = NULL;
    if(z->left == NULL)
    {
        Transplant(T,z,z->right);
    }
    else if(z->right == NULL)
    {
        Transplant(T,z,z->left);
    }
    else 
    {
        y = Tree_min(z->right);
        if(y->p != z)
        {
            Transplant(T,y,y->right);
            y->right = z->right;
            y->right->p = y;
        }
        Transplant(T,z,y);
        y->left = z->left;
        y->left->p = y;
    }

}

int main()
{
    Tree_Root T = NULL; // 初始化空树，根节点为NULL
    int arr[3] = {3, 1, 2}; // 待插入的3个元素（乱序）

    bst* A = create_bstree(3);
    bst* B = create_bstree(2);
    bst* C = create_bstree(6);
    Tree_insert(&T,A);
    Tree_insert(&T,B);
    Tree_insert(&T,C);
    // 输出排序结果（BST中序遍历天然升序）
    printf("3个元素BST排序结果（升序）：");
    INORDER_TREE_WALK(T);
    Tree_delete(&T,A); //删除操作
    printf("\n");
    INORDER_TREE_WALK(T);

    return 0;
}