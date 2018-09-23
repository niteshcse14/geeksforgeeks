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
int distance(struct Tree *root, int k, int level)
{
	if(root == NULL)
	{
		return -1;
	}
	if(root->data == k)
	{
		//cout <<  level << "\n";
		return level;
	}
	int l = distance(root->left, k, level + 1);
	return (l != -1) ? l : distance(root->right , k, level + 1);
}
int main()
{
	struct Tree * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << distance(root, 5, 1) << "\n";
    //cout << distance(root, 6, 1) << "\n";
    //cout << distance(root, 7, 1) << "\n";
    //cout << distance(root, 8, 1) << "\n";
	return 0;
}
//root_node_distance.cpp