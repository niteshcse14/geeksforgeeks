#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left, *right;
};
Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
bool findPath(Node *root, vector<int> &path, int n)
{
	if(root == NULL)
	{
		return false;
	}
	path.push_back(root->data);
	if(root->data == n)
	{
		return true;
	}
	if((root->left && findPath(root->left, path, n)) || (root->right && findPath(root->right, path, n)))
	{
		return true;
	}
	path.pop_back();
	return false;
}
int findLCA(Node *root, int n1, int n2)
{
	vector<int> path1, path2;
	if(!findPath(root, path1, n1) || !findPath(root, path2, n2))
	{
		return -1;
	}
	int i;
	for(i = 0; i < path1.size() && i < path2.size(); i++)
	{
		if(path1[i] != path2[i])
		{
			break;
		}
	}
	return path1[i - 1];
}
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	printf("%d\n", findLCA(root, 4, 5));
	printf("%d\n", findLCA(root, 4, 6));
	printf("%d\n", findLCA(root, 3, 4));
	printf("%d\n", findLCA(root, 2, 4));
	return 0;
}