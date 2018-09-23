#include <bits/stdc++.h>
using namespace std;
#define maxn 6000010
#define lt(a) 2 * a
#define rt(a) 2 * a + 1
int n, t, res = 1, pre;
int inp[maxn], bit[maxn][3];
struct node {
	int val;
	node *ar[2];
};
node *newNode() {
	node *temp = new node;
	temp->val = 0;
	temp->ar[0] = temp->ar[1] = NULL;
	return temp;
}
void insert(node *root, int pre_xor) {
	node *temp = root;
	for (int i = 31; i >= 0; --i) {
		bool val = pre_xor & (1 << i);
		if (temp->ar[val] == NULL)
			temp->ar[val] = newNode();
		temp = temp->ar[val];
	}
	temp->val = pre_xor;
}
int query(node *root, int pre_xor){
	node *temp = root;
	for (int i = 31; i >= 0; --i) {
		bool val = pre_xor & (1 << i);
		if (temp->ar[1 - val] != NULL)
			temp = temp->ar[1 - val];
		else if (temp->ar[val] !=NULL) 
			temp = temp->ar[val];
	}
	return temp->val ^ pre_xor;
}
void build(int idx, int cnt) {
	if (cnt == 0) {
		bit[idx][2] = 0;
		return;
	}
	build(lt(idx), cnt - 1);
	build(rt(idx), cnt - 1);
}
void update(int idx, int val, int cnt) {
	if (cnt == -1) {
		bit[idx][2] = val;
		//printf("update %d %d\n", idx, val);
		return;
	}
	//printf("%d %d\n", val, idx);
	if ((val >> cnt) & 1) 
		update(rt(idx), val, cnt - 1);
	else 
		update(lt(idx), val, cnt - 1);
}
int get(int idx, int val, int cnt) {
	if (cnt == -1) return val ^ bit[idx][2];
	if ((val >> cnt) & 1){
		get(lt(idx), val, cnt - 1);
	}
	else { 
		get(rt(idx), val, cnt - 1);
	}
}
int main() {
	scanf ("%d", &t);
	while(t--) {
		node *root = newNode();
		insert(root, 0);
		pre = 0;
		scanf("%d", &n);
		build(1, 20);
		for (int i = 0;i < n; ++i)
			scanf("%d", &inp[i]);
		for (int i = 0; i < n; ++i) {
			pre ^= inp[i];
			insert(root, pre);
			res = max(res, query(root, pre));
			//printf("get is %d %d\n", res, pre);
		}
		printf("%d\n", res);
	}
	return 0;
}