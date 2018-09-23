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
void printPathArray(int arr[], int N)
{
    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n";
}
void path(struct Tree *root , int i, int arr[])
{
    if(root == NULL)
    {
        return;
    }
    arr[i] = root->data;
    i++;
    if(root->left == NULL && root->right == NULL)
    {
        printPathArray(arr,  i);
    }
    path(root->left, i,  arr);
    path(root->right, i,  arr);
}
void inorder(struct Tree *root, stack<Tree *> s)
{
    //
}
int main()
{
    struct Tree *root = NULL;
    root = newNode(10);
    root->right = newNode(2);
    //root->right->left = newNode(2);
    root->left = newNode(8);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    int arr[100];
    path(root, 0, arr);
    return 0;
}
