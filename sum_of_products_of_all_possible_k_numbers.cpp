#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int n, k;
int inp[maxn], dp[maxn][maxn];
int solve(int idx,int cnt, int mx,int mn) {
	if (cnt == 0)
		return 1;
	if (idx == -1)
		return 0;
	if (dp[idx][cnt] != -1) 
		return dp[idx][cnt];
	int a = inp[idx] * solve (idx - 1, cnt - 1, max (mx, inp[idx]), min (mn, inp[idx]));
	int b = solve (idx - 1, cnt, mx, mn);
	if (a)
		printf("from a  %d %d %d %d\n", a, mx, mn, idx);
	if (b)
		printf("from b  %d %d %d %d\n", b, mx, mn, idx);
	dp[idx][cnt] = a + b;
	return dp[idx][cnt];
}
int main() {
	memset (dp, -1, sizeof dp);
	scanf ("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf ("%d", &inp[i]);
	printf("%d\n", solve (n - 1, k, 0, 9999));
	return 0;
}