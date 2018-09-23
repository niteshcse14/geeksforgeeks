#include <bits/stdc++.h>
using namespace std;
struct node{
	int prio;
	int size;
	int val;
	node *l;
	node *r;
	node(){
		l(0);
		r(0);
	}
}
node pool[6 * 100005];
int size(node *n){
	return n ? n->size : 0;
}
void update(node *n){
	if(n){
		n->size = 1 + size(n->l) + size(n->r);
	}
}
void split(node *n, node *&l, node *&r, int key, int add = 0){
	if(!n){
		return void(l = r = 0);
	}
	int nkey = add + size(n->l) + 1;
}
int main(){
	//
	return 0;
}