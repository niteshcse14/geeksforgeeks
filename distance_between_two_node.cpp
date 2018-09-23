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
bool findPath(struct Tree *root, vector<int> &path, int k)
{
	if(root == NULL)
	{
		return false;
	}
	path.push_back(root->data);
	if(root->data == k)
	{
		return  true;
	}
	if((root->left && findPath(root->left, path, k)) || 
		(root->right && findPath(root->right, path, k)))
	{
		return true;
	}
	path.pop_back();
	return false;
}
int distance_between_two_node(struct Tree *root, int a, int b)
{
	vector<int> path1, path2;
	if(!findPath(root, path1, a) || !findPath(root, path2, b))
	{
		return -1;
	}
	int i = 0;
	for(i = 0; i < path1.size() && path2.size(); i++)
	{
		if(path1[i] != path2[i])
		{ 
			break;
		}
	}
	return (path1.size()  + path2.size() - 2 * i);
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
    //distance_between_two_node(root, 1, 3);
    cout << distance_between_two_node(root, 10, 14) << "\n";
    cout << distance_between_two_node(root, 14, 8) << "\n";
    cout << distance_between_two_node(root, 10, 22) << "\n";
	return 0;
}
//distance_between_two_node.cpp