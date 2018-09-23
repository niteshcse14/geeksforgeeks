#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *l;
	node *r;
};
node *buildCartesianTreeUtil(int root, int arr[], int parent[], int leftChild[], int rightChild[]){
	if(root == -1){
		return NULL;
	}
	node *newNode = new node;
	newNode->data = arr[root];
	newNode->l = buildCartesianTreeUtil(leftChild[root], arr, parent, leftChild, rightChild]);
	newNode->r = buildCartesianTreeUtil(rightChild[root], arr, parent, leftChild, rightChild);
	return newNode;
}
node *buildCartesianTree(int arr[], int n){
	int parent[n];
	int leftChild[n];
	int rightChild[n];
	memset(parent, -1, sizeof(parent));
	memset(leftChild, -1, sizeof(leftChild));
	memset(rightChild, -1, sizeof(rightChild));
}
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
	}
	return 0;
}