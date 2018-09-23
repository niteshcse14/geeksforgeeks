#include <bits/stdc++.h>
using namespace std;
struct Tree
{
	struct Tree *left, *right;
	int data;
};
struct Tree *newNode(int data)
{
	struct Tree *node = (struct Tree *)malloc(sizeof(struct Tree));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}
void mirror(struct Tree *root)
{
	if(root == NULL)
	{
		return;
	}
	mirror(root->left);
	mirror(root->right);
	struct Tree *temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
}
void print(struct Tree *root)
{
	if(root != NULL)
	{
		cout << root->data << " ";
		print(root->left);
		print(root->right);
	}
}
int main()
{
	struct Tree *root = NULL;
	root =  newNode(1);
	root->left = newNode(3); 
	root->right = newNode(2);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	print(root);
	printf("\n");
	mirror(root);
	print(root);
	printf("\n");
	return 0;
}