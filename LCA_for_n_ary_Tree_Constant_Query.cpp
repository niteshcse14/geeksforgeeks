#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define pb push_back
#define maxn 1000010
int t, n, m, u, v, ptr;
vector <int> adj[maxn], eu;
bool vis[maxn];
int pw[20], logn[maxn], st[maxn], dep[maxn], dp[maxn][20];
void euler(int cur, int pre) {
	if (st[cur] == -1)
		st[cur] = ptr;
	dep[cur] = pre;
	eu.pb(cur);
	vis[cur] = true;
	ptr++;
	for (auto i : adj[cur]) {
		if (!vis[i]) {
			euler(i, pre + 1);
			eu.pb(i);
			ptr++;
		}
	}
}
void s_table() {
	memset(dp, -1, sizeof dp);
	for (int i = 1; i < ptr; ++i)
		dp[i - 1][0] = (dep[i] < dep[i - 1]) ? i : (i - 1);
	for (int i = 1; i < 15; ++i) {
		for (int j = 0; j < ptr; ++j) {
			int a = dp[j][i - 1];
			int b = dp[j + pw[i - 1]][i - 1];
			if (a != -1 and b != -1) {
				dp[j][i] = (a < b) ? a : b;
			}
			else break;
		}
	}
}
int query(int l, int r) {
	int d = r - l;
	int dx = logn[dx];
	if (l == r) return l;
	if (eu[dp[l][dx]] > eu[dp[r - pw[dx]][dx]]) 
		return dp[r  - pw[dx]][dx];
	return dp[l][dx];
}
void preprocess() {
	pw[0] = 1;
	for (int i = 1; i < 18; ++i) 
		pw[i] = pw[i - 1] * 2;
	int val = 1, ptr = 0;
	for (int i = 1; i < maxn; ++i) {
		logn[i] = ptr - 1;
		if (val == i) {
			val = 2 * val;
			logn[i] = ptr;
			ptr++;
		}
	}
}
int lca(int l, int r) {
	if (l == r) return l;
	if (st[l] > st[r])
		swap(l, r);
	return eu[query(st[l], st[r])];
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		memset(st, -1, sizeof st);
		euler(1, 0);
		printf("LCA %d\n", lca(6, 7));
		printf("LCA %d\n", lca(6, 4));
	}
	return 0;
}