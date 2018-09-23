#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data, count;
	struct Node *left, *right;
};
Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->count = 0;
	temp->left = temp->right = NULL;
	return temp;
}
int printKDistantfromLeaf(Node *root, int k)
{
	if(root == NULL)
	{
		return 0;
	}
	if(root->left == NULL && root->right == NULL)
	{
		root->count = 1;
		return root->count;
	}
	int l = printKDistantfromLeaf(root->left, k);
	int r = printKDistantfromLeaf(root->right, k);
	root->count++;
	if(root->count == k)
	{
		printf("%d ", root->data);
	}
	return root->count;
}
int main()
{
	Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    printKDistantfromLeaf(root, 2);
	return 0;
}