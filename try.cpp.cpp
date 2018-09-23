#include <bits/stdc++.h>
using namespace std;
struct Tree
{
	struct Tree *left, *right, *parent;
	int data, factor;
};
struct Tree *newNode(int data)
{
	struct Tree *node = (struct Tree *)malloc(sizeof(struct Tree));
	node->left = node->right = NULL;
	node->data = data;
	node->factor = 0;
	return node;
}
struct Tree* insert(struct Tree *root, int data)
{
	if(root == NULL)
	{
		root = newNode(data);
	}
	else
	{
		if(data < root->data)
		{
			root->left = insert(root->left, data);
		}
		else if(data > root->data)
		{
			root->right = insert(root->right, data);
		}
	}
	return root; 
}
int getHeight(struct Tree* root)
{
	if(root == NULL)
	{
		return 0;
	}
	int l = getHeight(root->left);
	int r = getHeight(root->right);
	if(l > r)
	{
		return (l + 1);
	}
	else
	{
		return (r + 1);
	}
}
void setFactor(struct Tree* root)
{
	if(root != NULL)
	{
		root->factor = getHeight(root->right) - getHeight(root->left);
	}
}
/*
void print_inorder(struct Tree *root)
{
	if(root != NULL)
	{
		cout << root->data << "\t";
		int l = getHeight(root->left);
		int r = getHeight(root->right);
		root->factor = r - l;
		cout << (root->factor) << "\n";
		print_inorder(root->left);
		print_inorder(root->right);
	}
}
*/
int main()
{
	struct Tree *root = NULL;
	int N, count = 0;
	cin >> N;
	while(N--)
	{
		int data;
		cin >> data;
		if(count == 0)
		{
			root = insert(root, data);
			count++;
		}
		else
		{
			insert(root, data);
		}
	}
	print_inorder(root);
	return 0;
}