#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector < int > adj[maxn];
bool visited[maxn];
int n, a, b;
int dp1[maxn], dp2[maxn];
int C[maxn];
void dfs(int u) {
	visited[u] = 1;
	int sum1 = 0;
	int sum2 = 0;
	vector < int > :: iterator v;
	for(v = adj[u].begin(); v != adj[u].end(); ++v) {
		if(!visited[*v]) {
			dfs(*v);
			sum1 += dp2[*v];
			sum2 += max(dp1[*v], dp2[*v]);
			printf("In %d  %d  %d  %d  %d\n", u, sum1, sum2, dp1[*v], dp2[*v]);
		}
	}
	dp1[u] = C[u] + sum1;
	dp2[u] = sum2;
	printf("out %d  %d  %d  %d  %d\n\n", u, sum1, sum2, dp1[u], dp2[u]);
}
int main() {
	memset(visited, false, sizeof(visited));
	memset(dp1, 0, sizeof(dp1));
	memset(dp2, 0, sizeof(dp2));
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &C[i]);
	}
	dfs(1);
	printf("\nmaz  ans   %d\n", max(dp1[1], dp2[1]));
	return 0;
}