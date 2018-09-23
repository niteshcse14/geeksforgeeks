#include <bits/stdc++.h>
using namespace std;
#define maxn 1010
int dp[maxn][maxn], inp[maxn];
int n, k, m, mx, t;
int main() {
	scanf ("%d", &t);
	while (t--) {
		memset (dp, 0, sizeof dp);
		scanf ("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &inp[i]);
			mx = max (mx, inp[i]);
		}
		dp[0][0] = 1;
		m = pow (2, log2 (mx) + 1) - 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ inp[i - 1]];
			}
		}
		printf("%d\n", dp[n][k]);
	}
	return 0;
}