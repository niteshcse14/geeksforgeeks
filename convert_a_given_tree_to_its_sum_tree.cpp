#include <bits/stdc++.h>
using namespace std;
struct Tree
{
	struct Tree  *left, *right;
	int data;
};
struct Tree *newNode(int data)
{
	struct Tree *node = (struct Tree *)malloc(sizeof(struct Tree));
	node->data =  data;
	node->left = node->right = NULL;
	return node;
}
int sum_tree(struct Tree *root)
{
	if(root == NULL)
	{
		return 0;
	}
	//cout << root->data << "\n";
	int old_val = root->data;
	root->data = sum_tree(root->left) + sum_tree(root->right);
	
	return root->data + old_val;

}
void printInorder(struct Tree *root)
{
     if (root == NULL)
          return;
     printInorder(root->left);
     printf("%d ", root->data);
     printInorder(root->right);
}
int main()
{
	struct Tree *root = NULL;
	root = newNode(10);
  	root->left = newNode(-2);
  	root->right = newNode(6);
  	root->left->left = newNode(8);
  	root->left->right = newNode(-4);
  	root->right->left = newNode(7);
  	root->right->right = newNode(5);
  	sum_tree(root);
  	printInorder(root);
  	printf("\n");
	return 0;
}
//convert_a_given_tree_to_its_sum_tree.cpp