#include <bits/stdc++.h>
using namespace std;
int arr[1000];
struct Persistent
{
	struct Persistent *left, *right;
	int data;
	Persistent()
	{
		//
	}
	Persistent(Persistent *l, Persistent *r, int d)
	{
		left = l;
		right = r;
		data = d;
	}
};
Persistent *version[1000];
void build(struct Persistent *node, int low, int high)
{
	if(low == high)
	{
		node->data = arr[low];
		return;
	}
	int mid = (low + high) / 2;
	node->left = new Persistent(NULL, NULL, 0);
	node->right = new Persistent(NULL, NULL, 0);
	build(node->left, low, mid);
	build(node->right, mid + 1, high);
	node->data = node->left->data + node->right->data;
}
void upgrade(Persistent *prev, Persistent *curr, int low, int high, int index, int val)
{
	if(low == high)
	{
		curr->data = val;
	}
	int mid = (low + high) / 2;
	if(index <= mid)
	{
		curr->right = prev->right;
		curr->left = new Persistent(NULL, NULL, 0);
		upgrade(prev->left, curr->left, low, mid, index, val);
	}
	else
	{
		curr->left = prev->left;
		cur->right = new Persistent(NULL, NULL, 0);
		upgrade(prev->right, curr->right, mid + 1, high, index, val);
	}
	curr->data = curr->left->data + curr->right->data;
}
int main()
{
	int A[] = {1, 2, 3, 4, 5};
	int N = sizeof(A) / sizeof(int);
	for(int i = 0; i < N; i++)
	{
		arr[i] = A[i];
	}
	Persistent *node = new Persistent(NULL, NULL, 0);
	build(node, 0, N - 1);
	version[0] = node;
	//
	return 0;
}