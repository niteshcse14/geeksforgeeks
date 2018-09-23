#include <bits/stdc++.h>
using namespace std;
int const MAX = 100;
int arr[MAX], euler[MAX], level[MAX], first_occurrence[MAX];
int N, Q, V;
int ind;
struct Node
{
	int key;
	struct Node *left, *right;
};
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}
void euler_tour(Node *root, int l)
{
	if(root)
	{
		euler[ind] = root->key;
		level[ind] = l;
		ind++;
		if(first_occurrence[root->key] == -1)
		{
			first_occurrence[root->key] = ind - 1;
		}
		if(root->left)
		{
			euler_tour(root->left, l + 1);
			euler[ind] = root->key;
			level[ind] = l;
			ind++;
		}
		if(root->right)
		{
			euler_tour(root->right, l + 1);
			euler[ind] = root->key;
			level[ind] = l;
			ind++;
		}
	}
}
void constructSTUtil(int si, int ss, int se, int *st)
{
	if(ss == se)
	{
		st[si] = ss;
	}
	else
	{
		int mid = (ss + se) / 2;
		constructSTUtil(2 * si + 1, ss, mid, st);
		constructSTUtil(2 * si + 2, mid + 1, se, st);
		if(level[st[2 * si + 1]] < level[st[2 * si + 2]])
		{
			st[si] = st[2 * si + 1];
		}
		else
		{
			st[si] = st[2 * si + 2];
		}
	}
}
int *constructST(int n)
{
	int x = log2(n) + 1;
	int max_size = 2 * (1 << x) - 1;
	int *st = new int[max_size];
	constructSTUtil(0, 0, n - 1, st);
	return st;
}
int RMQUtil(int index, int ss, int se, int qs, int qe, int *st)
{
	if(qs <= ss && qe >= se)
	{
		return st[index];
	}
	else if(se < qs || ss > qe)
	{
		return -1;
	}
	int mid = (ss + se) / 2;
	int q1 = RMQUtil(2 * index + 1, ss, mid, qs, qe, st);
	int q2 = RMQUtil(2 * index + 2, mid + 1, se, qs, qe, st);
	if(q1 == -1)
	{
		return q2;
	}
	else if(q2 == -1)
	{
		return q1;
	}
	return (level[q1] < level[q2]) ? q1 : q2;
}
int RMQ(int *st, int n, int qs, int qe)
{
	if(qs < 0 || qe > n - 1 || qs > qe)
	{
		return -1;
	}
	return RMQUtil(0, 0, n - 1, qs, qe, st);
}
int find_lca(Node *root, int u, int v)
{
	memset(first_occurrence, -1, sizeof(first_occurrence));
	ind = 0;
	euler_tour(root, 0);
	int *st = constructST(2 * V - 1);
	if(first_occurrence[u] > first_occurrence[v])
	{
		swap(u, v);
	}
	int qs = first_occurrence[u];
	int qe = first_occurrence[v];
	int index = RMQ(st, 2 * V - 1, qs, qe);
	return euler[index];
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
    root->left->right->left = newNode(8);
    root->left->right->right = newNode(9);
 	V = 9;
    int u = 4, v = 9;
    printf("%d\n", find_lca(root, u, v));
	return 0;
}