#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
ll arr[maxn];
ll t, n, k;
int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &arr[i]);
		}
		for (int i = 0; i <= n - k; ++i) {
			ll mx = -9999999;
			for (int j = i; j < i + k; ++j) {
				mx = max(mx, arr[j]);
			}
			printf("%lld  ", mx);
		}
		printf("\n");
	}
	return 0;
}