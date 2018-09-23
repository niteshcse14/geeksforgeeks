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
void findLca(struct Tree *root , int a, int b)
{
	if(root == NULL)
	{
		return;
	}
	if(root->data > a && root->data < b)
	{
		cout << (root->data) << "\n";
		return;
	}
	if(root->data == a || root->data == b)
	{
		cout << (root->data) << "\n";
		return;
	}
	findLca(root->left, a, b);
	findLca(root->right, a, b);
}
int main()
{
    struct Tree *root = NULL;
    root = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
    //findLca(root, 1, 3);
    findLca(root, 10, 14);
    findLca(root, 14, 8);
    findLca(root, 10, 22);
    return 0;
}