#include <bits/stdc++.h>
using namespace std;
int N, a, b, ans;
int arr[100000];
struct node{
	int value;
	node *children[2];
};
struct node *getNode(){
	node *temp = new node();
	temp->value = 0;
	temp->children[0] = temp->children[1] = NULL;
	return temp;
}
void insert(node *root, int val){
	node *temp = root;
	for(int i = 31; i >= 0; --i){
		bool v = val & (1 << i);
		if(temp->children[v] == NULL){
			temp->children[v] = getNode();
		}
		temp = temp->children[v];
	}
	temp->value = val;
}
void query(node *root, int val){
	node *temp = root;
	for(int i = 31; i >= 0; --i){
		bool v = val & (1 << i);
		if(temp->children[1 - v] != NULL){
			temp = temp->children[1 - v];
		}
		else if(temp->children[v] != NULL){
			temp = temp->children[v];
		}
	}
	//printf("%d %d %d\n", val, temp->value, val ^ (temp->value));
	int t = val ^ temp->value;
	if(t > ans){
		a = val;
		b = temp->value;
		ans = t;
	}
}
int main(){
	scanf("%d", &N);
	node *root = getNode();
	for(int i = 0; i < N; ++i){
		scanf("%d", &arr[i]);
		insert(root, arr[i]);
	}
	for(int i = 0; i < N; ++i){
		query(root, arr[i]);
	}
	printf("%d %d %d\n", a, b, ans);
	return 0;
}