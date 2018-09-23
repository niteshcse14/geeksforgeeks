#include <bits/stdc++.h>
using namespace std;
struct node{
	node *children[26];
	bool isLeaf;
};
struct node *getNode(){
	node *n = new node();
	for(int i = 0; i < 26; ++i){
		n->children[i] = NULL;
	}
	n->isLeaf = false;
	return n;
}
void insert(node *n, string str){
	node *pCrawl = n;
	for(int i = 0; i < str.size(); ++i){
		int idx = str[i] - 'a';
		if(!pCrawl->children[idx]){
			pCrawl->children[idx] = getNode();
		}
		pCrawl = pCrawl->children[idx];
	}
	pCrawl->isLeaf = true;
}
bool search(node *n, string str){
	node *pCrawl = n;
	for(int i = 0; i < str.size(); ++i){
		int idx = str[i] - 'a';
		if(!pCrawl->children[idx]){
			return false;
		}
		pCrawl = pCrawl->children[idx];
	}
	return pCrawl != NULL && pCrawl->isLeaf;
}
int main(){
	int N, Q;
	string str;
	scanf("%d %d", &N, &Q);
	node *root = getNode();
	for(int i = 0; i < N; ++i){
		cin >> str;
		insert(root, str);
	}
	while(Q--){
		cin >> str;
		if(search(root, str)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}