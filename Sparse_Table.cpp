#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int lookup[maxn][20], inp[maxn];
int n;
int query(int l, int r) {
	int j = log2(r - l + 1);
	if (lookup[l][j] <= lookup[r - (1 << j) + 1][j])
		return lookup[l][j];
	return lookup[r - (1 << j) + 1][j];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &inp[i]);
	for (int i = 0; i < n; ++i)
		lookup[i][0] = inp[i];
	for (int j = 1; (1 << j) <= n; ++j) {
		for (int i = 0; (i + (1 << j)) <= n; ++i) {
			int a = lookup[i][j - 1];
			int b = lookup[i + (1 << (j - 1))][j - 1];
			lookup[i][j] = min(a, b);
		}
	}
	printf("%d\n", query(0, 4));
	printf("%d\n", query(4, 7));
	printf("%d\n", query(7, 8));
	return 0;
}
//7 2 3 0 5 10 3 12 18