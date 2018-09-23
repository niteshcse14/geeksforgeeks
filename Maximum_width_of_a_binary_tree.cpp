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
int width(struct Tree *root)
{
	if(root == NULL)
	{
		return -1;
	}
	int res = INT_MIN;
	queue<Tree *> q;
	q.push(root);
	while(q.size() > 0)
	{
		int q_size = q.size();
		res = max(q_size, res);
		while(q_size > 0)
		{
			struct Tree *node = q.front();
			q.pop();
			//cout << node->data << " ";
			q_size--;
			if(node->left != NULL)
			{
				q.push(node->left);
			}
			if(node->right != NULL)
			{
				q.push(node->right);
		 	}
		} 
		//printf("\n");
	}
	return res;
}
int main()
{
	struct Tree *root = NULL;
    root = newNode(1);
    root->left               = newNode(2);
    root->right              = newNode(3);
    root->left->left         = newNode(4);
    root->left->right        = newNode(5);
    root->right->right  	 = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);
    cout << width(root) << "\n";
	return 0;
}
//Maximum_width_of_a_binary_tree.cpp