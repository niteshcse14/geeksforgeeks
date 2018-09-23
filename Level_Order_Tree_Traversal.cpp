#include <bits/stdc++.h>
using namespace std;
struct Tree
{
    struct Tree *left,  *right;
    int data;
};
struct Tree *newNode(int data)
{
    struct Tree *node = (struct Tree*)malloc(sizeof(struct Tree));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}
void printLevelOrder(struct Tree *root, int level)
{
    if(root == NULL)
    {
        return;
    }
    if(level == 1)
    {
        cout << (root->data) << "  ";
    }
    else
    {
        printLevelOrder(root->left, level - 1);
        printLevelOrder(root->right, level - 1);
    }
}
int getHeight(struct Tree *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int lheight = getHeight(root->left);
        int rheight = getHeight(root->right);
        if(lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}
void printLevel(struct Tree *root)
{
    int height = getHeight(root);
    for(int i = 1; i <= height; i++)
    {
        printLevelOrder(root, i);
    }
}
void inorder(struct Tree *root, stack<Tree *> s)
{
    //
}
int main()
{
    struct Tree *root = NULL;
    root = newNode(1);
    root->right = newNode(3);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printLevel(root);
    cout << "\n";
    stack<Tree *> s;
    inorder(root, s);
    return 0;
}
//Level_Order_Tree_Traversal.cpp
