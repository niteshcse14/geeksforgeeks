#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int n;
int inp[maxn];
struct node{
	node *left,*right;
	int height,key;
	node():key(0),height(0),left(nullptr),right(nullptr){};
	node(int val):left(nullptr),right(nullptr),key(val),height(1){};
};
int height(node *root){
	return root==NULL?0:root->height;
}
node* right_rotate(node *y){
	node *x=y->left;
	node *t2=x->right;
	y->left=t2;
	x->right=y;
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return x;
}
node* left_rotate(node *x){
	node *y=x->right;
	node *t2=y->left;
	y->left=x;
	x->right=t2;
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;
}
int getBalance(node *root){
	if(root==NULL)return 0;
	return height(root->left)-height(root->right);
}
node *insert(node *root,int key){
	if(root==NULL)
		return new node(key);
	if(key<root->key) root->left=insert(root->left,key);
	else if(key>root->key) root->right=insert(root->right,key);
	else return root;
	root->height=1+max(height(root->left),height(root->right));
	int balance=getBalance(root);
	if(balance>1&&key<root->left->key){
		return right_rotate(root);
	}
	if(balance<-1&&key>root->right->key){
		return left_rotate(root);
	}
	if(balance>1&&key>root->left->key){
		root->left=left_rotate(root->left);
		return right_rotate(root);
	}
	if(balance<-1&&key<root->right->key){
		root->right=right_rotate(root->right);
		return left_rotate(root);
	}
	return root;
}
void print_sol(node *root){
	if(root!=NULL){
		printf("%d ",root->key);
		print_sol(root->left);
		print_sol(root->right);
	}
}
int main(){
	scanf("%d",&n);
	node *root=NULL;
	for(int i=0;i<n;++i){
		scanf("%d",&inp[i]);
		root=insert(root,inp[i]);
	}
	print_sol(root);
	printf("\n");
	return 0;
}