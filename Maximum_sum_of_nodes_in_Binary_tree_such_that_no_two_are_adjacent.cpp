#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int u, v;
int C[N];
vector<int> adj[N];
int dp1[N], dp2[N];
void dfs(int V, int parent_of_V){

    //for storing sums of dp1 and max(dp1, dp2) for all children of V
    int sum1 = 0, sum2 = 0;

    //traverse over all children
    vector<int>::iterator v;
    for(v = adj[V].begin(); v != adj[V].end(); v++)
    {
	    if(*v == parent_of_V) continue;
	    dfs(*v, V);
	    sum1 += dp2[*v];
	    sum2 += max(dp1[*v], dp2[*v]);
	    printf("In For Loop   %d  %d  %d  %d  %d\n\n", *v, dp1[*v], dp2[*v], sum1, sum2);
    }

    dp1[V] = C[V] + sum1;
    dp2[V] = sum2;
    printf("outer Loop    %d  %d  %d  %d  %d\n", V, dp1[V], dp2[V], sum1, sum2);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
    	scanf("%d", &C[i]);
    }
    for(int i = 1; i < n; i++)
    {
	    cin >> u >> v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
    }

    dfs(1, 0);
    int ans = max(dp1[1], dp2[1]);
    cout << ans << endl;
}