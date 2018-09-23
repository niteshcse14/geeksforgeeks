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
void distance(struct Tree *root, int count , int k)
{
	if(root == NULL)
	{
		return;
	}
	if(count == k)
	{
		cout << (root->data) << "  ";
		return;
	}
	distance(root->left , count + 1, k);
	distance(root->right , count + 1, k);
}
int main()
{
	struct Tree *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);
    root->right->left = newNode(8);
    distance(root, 0, 1);
    printf("\n");
	return 0;
}
//prints_nodes_at_k_distance_from_root.cpp